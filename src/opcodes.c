#include "opcodes.h"

// TODO(lemmtopia): Add more opcodes
    globalvar emu_opcode_t opcodes[] = {
    // Immediate
    { 0x69, 2, 2, "ADC" },     // ADC
    { 0x29, 2, 2, "AND" },     // AND
    { 0xC9, 2, 2, "CMP" },     // CMP
    { 0xE0, 2, 2, "CPX" },     // CPX
    { 0xC0, 2, 2, "CPY" },     // CPY
    { 0x49, 2, 2, "EOR" },     // EOR
    { 0xA9, 2, 2, "LDA" },     // LDA
    { 0xA2, 2, 2, "LDX" },     // LDX
    { 0xA0, 2, 2, "LDY" },     // LDY
    { 0x09, 2, 2, "ORA" },     // ORA
    { 0xE9, 2, 2, "SBC" },     // SBC

    // Implied
    { 0x00, 7, 1, "BRK" },     // BRK
    { 0xEA, 2, 1, "NOP" },     // NOP
};
