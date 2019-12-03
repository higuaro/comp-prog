#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

enum class EventType { SHIFT, SLEEP, WAKE_UP };

struct event {
  EventType type;
  int month;
  int day;
  int minute;
  int guard_id;
  event(EventType type, int month, int day, int minute, int guard_id) :
    type(type), month(month), day(day), minute(minute), guard_id(guard_id) {}
};
ostream& operator<<(ostream& o, const event& e) {
  switch (e.type) {
    case EventType::SHIFT: o << "Shitf"; break;
    case EventType::SLEEP: o << "Sleep"; break;
    case EventType::WAKE_UP: o << "Wake up"; break;
  }
  o << '[' << e.day << '/' << e.month << ' ' << e.minute << ' ';
  if (e.type == EventType::SHIFT)
    o << "guard #" << e.guard_id;
  return o << ']';
}

bool operator<(const event& e1, const event& e2) {
  if (e1.month == e2.month) {
    if (e1.day == e2.day) {
      if (e1.minute == e2.minute) {
        return e1.guard_id < e2.guard_id;
      } else {
        return e1.minute < e2.minute;
      }
    } else {
      return e1.day < e2.day;
    }
  }
  return e1.month < e2.month;
}

event shift_event(int month, int day, int min, int guard_id) {
  return event(EventType::SHIFT, month, day, min, guard_id);
}

event wake_up_event(int month, int day, int min) {
  return event(EventType::WAKE_UP, month, day, min, -1);
}

event sleep_event(int month, int day, int min) {
  return event(EventType::SLEEP, month, day, min, -1);
}

event parse_event(const std::string& line) {
  const string sample_date("[1518-11-01 00:00] ");
  const size_t date_size = sample_date.size();

  string date = line.substr(0, date_size);
  string event_info = line.substr(date_size);

  regex date_re("\\[1518-(\\d+)-(\\d+) (\\d+):(\\d+)\\] ");
  smatch date_match;
  regex_match(date, date_match, date_re);

  int month = stoi(date_match.str(1));
  int day = stoi(date_match.str(2));
  int hour = stoi(date_match.str(3));
  int min = stoi(date_match.str(4));

  int min_of_day = hour * 60 + min;

  const string wake_up("wakes up");
  const string sleep("falls asleep");

  if (event_info == wake_up) {
    return wake_up_event(month, day, min_of_day);
  } else if (event_info == sleep) {
    return sleep_event(month, day, min_of_day);
  } else {
    regex shift_re("Guard #(\\d+) begins shift");
    smatch shift_match;
    regex_match(event_info, shift_match, shift_re);
    return shift_event(month, day, min_of_day, stoi(shift_match.str(1)));
  }
}

pair<int, int> clamp(const pair<int, int>& nap) {
  int start = nap.first < 0 ? 0 : (nap.first < 60 ? nap.first : 59);
  int end = nap.second < 0 ? 0 : (nap.second < 60 ? nap.second : 59);
  return make_pair(start, end);
}

pair<int, int> minute_slept_most(const vector<event>& events) {
  vector<pair<int, int>> naps;
  int nap_start_min = numeric_limits<int>::min();
  int previous_event_date = 0;
  bool sleeping = false;
  for (auto e : events) {
    if (sleeping) {
      int event_date = 100 * e.month + e.day;
      pair<int, int> nap = event_date == previous_event_date
          ? make_pair(nap_start_min, e.minute)
          : make_pair(nap_start_min, numeric_limits<int>::max());
      naps.push_back(nap);
    }
    previous_event_date = 100 * e.month + e.day;
    sleeping = e.type == EventType::SLEEP;
    if (sleeping) nap_start_min = e.minute;
  }
  if (sleeping)
     naps.push_back(make_pair(nap_start_min, numeric_limits<int>::max()));

  // Focus on the first hour 00:00-00:59
  array<int, 60> minutes{0};
  for (auto nap : naps) {
    pair<int, int> range = clamp(nap);
    if (range.first == range.second) continue;
    for (int i = range.first; i < range.second; i++)
      minutes[i]++;
  }

  auto max_value = max_element(begin(minutes), end(minutes));
  auto minute = distance(begin(minutes), max_value);
  return make_pair(minute, *max_value);
}

pair<int, int> guard_slept_most(const map<int, vector<event>>& guards_events) {
  int max_guard_id;
  pair<int, int> max = make_pair(numeric_limits<int>::min(), numeric_limits<int>::min());
  for (auto guard_events : guards_events) {
    pair<int, int> slept = minute_slept_most(guard_events.second);
    if (slept.second > max.second) {
      max = slept;
      max_guard_id = guard_events.first;
    }
  }
  return make_pair(max_guard_id, max.first);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string line;
  vector<event> events;
  while (getline(cin, line, '\n'))
    events.push_back(parse_event(line));
  sort(begin(events), end(events));

  int current_guard = -1;
  map<int, vector<event>> guard_events;
  for (auto e : events) {
    if (e.type == EventType::SHIFT) {
      current_guard = e.guard_id;
      guard_events[current_guard].push_back(wake_up_event(e.month, e.day, e.minute));
      continue;
    }
    guard_events[current_guard].push_back(e);
  }
  pair<int, int> guard = guard_slept_most(guard_events);
  cout << guard.first << ',' << guard.second << '\n';

  cout << guard.first * guard.second << '\n';
  return 0;
}
