#include "memory.h"
#include "cpu.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if(argc < 2) {
        printf("ERROR: expected 2 arguments\n");
        printf("USE: [./exe][PATH/TO/ROM]");
        exit(1);
    }

    char* rom_path = argv[1];
    initialize_memory();
    load_rom(rom_path);

    initialize_cpu();
    uint16_t opcode = fetch_opcode(PC, memory);
    
    return 0;
}