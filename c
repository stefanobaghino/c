#!/usr/bin/env bash

export OUT=out
export SRC="$1"
export BIN="$OUT"/"${SRC%.*}"

mkdir -p "$OUT" && cc "$SRC" -o "$BIN" && "$BIN"

