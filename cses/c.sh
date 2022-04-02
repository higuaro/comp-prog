#!/usr/bin/env bash
if [ "${1}" = "-o" ]; then
  shift
  echo "compiling ${1} for performance:"
  g++ -O2 --std=c++17 "${1}".cpp -o "${1}" 
else
  echo "compiling ${1} for debug:"
  g++ -ggdb --std=c++17 "${1}".cpp -o "${1}" 
fi
if [ $? -eq 0 ]; then
  if [ -f "./t.in" ]; then
    echo "Running with t.in:"
    ./"${1}" < t.in
  else
    echo "Done! type/paste input:"
    ./"${1}"
  fi
fi

