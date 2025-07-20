#!/bin/bash

mkdir -p build

gcc -std=c99 src/emu6507_term.c -o build/emu6507_term
