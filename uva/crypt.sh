#!/bin/bash

if [ ! $# -eq 1 ]; then
cat << EOF
    Mode of use:
        $0 "<text to be coded>"
EOF
    exit 1
fi

declare -a "ALPH=({a..z})"
declare -A MAP

echo "REPLACEMENT MAP:"
echo "-------------------------"
for c in {a..z}; do
    INDEX=$(($RANDOM % ${#ALPH[@]}))
    MAP[$c]="${ALPH[$INDEX]}"

    ALPH=(${ALPH[@]:0:$INDEX} ${ALPH[@]:$(($INDEX + 1))})

    echo "MAP[$c]=""${MAP[$c]}"
done
echo "-------------------------"

TO_ENCRYPT="$1"
OUTPUT=""
for i in $( seq 0 $(( ${#TO_ENCRYPT} - 1 )) ); do
    CHAR=${TO_ENCRYPT:$i:1}
    if [ "$CHAR" != " " ]; then
        OUTPUT="$OUTPUT"${MAP[$CHAR]}
    else
        OUTPUT="$OUTPUT "
    fi
done
echo $TO_ENCRYPT
echo $OUTPUT
