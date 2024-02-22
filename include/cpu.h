#pragma once

#include <common.h>
#include <instructions.h>

typedef struct {
    u8   a;
    u8   f;
    u8   b;
    u8   c;
    u8   d;
    u8   e;
    u8   h;
    u8   l;
    u16 pc; // Program Counter.
    u16 sp; // Stack   Pointer.
} cpu_registers;

typedef struct {
    cpu_registers regs;
    
    // Current fetch...
    u16       fetched_data;
    u16           mem_dest;
    bool       dest_is_mem;
    u8          cur_opcode;
    instruction *curr_inst;

    bool    halted; // Is CPU halted ?
    bool  stepping; // Are we in stepping mode ?

} cpu_context;

void cpu_init();
bool cpu_step();
