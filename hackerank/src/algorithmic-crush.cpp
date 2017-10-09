#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>

#include <string>
#include <sstream>

#include <fstream>

template<typename Number>
struct segment_tree {
   typedef struct node {
      Number value;
      Number lazy;
      int left_child_index;

      node() : value(0), lazy(0), left_child_index(-1) {}

      int get_left_child_index() const {
         return left_child_index;
      }

      int get_right_child_index() const {
         return left_child_index + 1;
      }

      bool is_leaf() const {
         return left_child_index < 0;
      }
   } segment_tree_node;

   typedef std::function<Number(const Number&, const Number&)> node_operation_function;
   typedef std::function<Number(const Number&, const Number&, const uint32_t&, const uint32_t&)> range_operation_function;

   node_operation_function node_operation;
   range_operation_function range_update;
   Number range_max;
   std::vector<segment_tree_node> nodes;

   segment_tree(const node_operation_function& operation,
                const range_operation_function& range_operation,
                const Number& range_max) :
   node_operation(operation), range_update(range_operation), range_max(range_max) {
      const int max_num_nodes = (2 * range_max) - 1;
      nodes.reserve(max_num_nodes);
      nodes.insert(nodes.end(), max_num_nodes, node());
      build_node_indexes(range_max, max_num_nodes);
   }

   void build_node_indexes(const Number& range_max, const int max_num_nodes) {
      struct node_state {
         Number range_left;
         Number range_right;
         uint32_t node_index;
      };
      std::queue<node_state> states;
      states.push({0, range_max - 1, 0});
      uint32_t counter = 1;

      while (!states.empty()) {
         node_state state = states.front(); states.pop();
         nodes[state.node_index].left_child_index = counter;

         Number range_mid = (state.range_right + state.range_left) / 2;
         if (state.range_left < range_mid)
            states.push({state.range_left, range_mid, counter});
         if ((range_mid + 1) < state.range_right)
            states.push({range_mid + 1, state.range_right, counter + 1});
         counter += 2;
      }
   }

   void update_interval_internal(const int node_index, const int low, const int high,
                                 const Number interval_start, const Number interval_end,
                                 const Number delta) {

      auto node = &nodes[node_index];
      const int left_child_index = node->get_left_child_index();
      const int right_child_index = node->get_right_child_index();

      if (node->lazy != 0) {
         node->value = range_update(node->value, node->lazy, low, high);

         if (low < high) {
            nodes[left_child_index].lazy += node->lazy;
            nodes[right_child_index].lazy += node->lazy;
         }
         node->lazy = 0;
      }

      if (low > high || low > interval_end || high < interval_start) return;

      if (low >= interval_start && high <= interval_end) {
         node->value = range_update(node->value, delta, low, high);
         if (low < high) {
            nodes[left_child_index].lazy += delta;
            nodes[right_child_index].lazy += delta;
         }
         return;
      }

      int midpoint = (low + high) / 2;
      update_interval_internal(left_child_index, low, midpoint, interval_start, interval_end, delta);
      update_interval_internal(right_child_index, midpoint + 1, high, interval_start, interval_end, delta);
      node->value = node_operation(nodes[left_child_index].value, nodes[right_child_index].value);
   }

   void update_interval(const uint32_t interval_left, const uint32_t interval_right, const Number delta) {
      update_interval_internal(0, 0, range_max - 1, interval_left - 1, interval_right - 1, delta);
   }

   Number query_interval_internal(const uint32_t node_index, const uint32_t start, const uint32_t end,
                                  const uint32_t interval_left, const uint32_t interval_right) {
      auto node = &nodes[node_index];
      const int left_child_index = node->get_left_child_index();
      const int right_child_index = node->get_right_child_index();

      if (start > end || start > interval_right || end < interval_left) return 0;

      if (node->lazy != 0) {
         node->value = range_update(node->value, node->lazy, interval_left, interval_right);

         if (start < end) {
            nodes[left_child_index].lazy += node->lazy;
            nodes[right_child_index].lazy += node->lazy;
         }
         node->lazy = 0;
         return node->value;
      }

      if (start >= interval_left && end <= interval_right) {
         return node->value;
      }

      int midpoint = (start + end) / 2;
      Number left = query_interval_internal(left_child_index, start, midpoint, interval_left, interval_right);
      Number right = query_interval_internal(right_child_index, midpoint + 1, end, interval_left, interval_right);
      return node_operation(left, right);
   }

   Number query_interval(const uint32_t interval_left, const uint32_t interval_right) {
      return query_interval_internal(0, 0, range_max - 1, interval_left - 1, interval_right - 1);
   }

   std::string to_str(const uint32_t node_index, const uint32_t start, const uint32_t end) const {
      std::ostringstream oss;
      const std::string tab = "   ";
      auto node = nodes[node_index];
      if (node.is_leaf()) {
         oss << tab << node_index << " [shape=box, label=\"<" << node_index << ">\\n" << node.value << "\\n[" << start << "]\\nlazy=" << node.lazy <<  "\"]" << std::endl;
      } else {
         oss << tab << node_index << " [label=\"<" << node_index << ">\\n" << node.value << "\\n[" << start << ".." << end << "]\\nlazy=" << node.lazy << "\"]" << std::endl;
         oss << tab << node_index << " -- " << node.get_left_child_index() << std::endl;
         oss << tab << node_index << " -- " << node.get_right_child_index() << std::endl;
         int midpoint = (end + start) / 2;
         oss << to_str(node.get_left_child_index(), start, midpoint);
         oss << to_str(node.get_right_child_index(), midpoint + 1, end);
      }

      return oss.str();
   }

   std::string str() const {
      return to_str(0, 0, range_max - 1);
   }
};

template<typename Number>
std::ostream& operator<<(std::ostream& out, const segment_tree<Number>& tree) {
   // Generate a .dot file representation of the tree
   // can be viewed with `dot -Tpn a.dot > a.png`
   out << "graph {" << std::endl;
   out << tree.str();
   return out << "}" << std::endl;
}

int main(int argc, char** argv) {
//     std::ifstream fis("test.in");
//     std::cin.rdbuf(fis.rdbuf());

   typedef uint64_t Number;

   auto node_operation = [](const Number& a, const Number& b) -> Number {
      return std::max(a, b);
   };
   auto range_update = [](const Number& current_value, const Number& delta, const uint32_t& l, const uint32_t& r) -> Number {
      return current_value + delta;
   };

   uint32_t n, m;
   std::cin >> n >> m;

   segment_tree<Number> tree(node_operation, range_update, n);

   for (int i = 0; i < m; i++) {
      int a, b, k;
      std::cin >> a >> b >> k;
      tree.update_interval(a, b, k);
   }
//   std::cerr << tree << std::endl;
//   std::cout << tree << std::endl;
   std::cout << tree.query_interval(1, n) << std::endl;

   return 0;
}