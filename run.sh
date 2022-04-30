#!/bin/bash
tmp=$(mktemp)
make clean >/dev/null
make &> "$tmp"
if [ $? -eq 0 ]; then
   ./a.out
else
   cat "$tmp"
fi
rm "$tmp"