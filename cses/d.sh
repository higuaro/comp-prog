#/usr/bin/env bash
echo "compiling"
g++ --std=c++17 -ggdb "${1}".cpp -o "${1}" && echo "debugging" && gdb -tui -ex 'set args -2 < ./t.in' "${1}"
