#include "memory.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void initialize_memory();
void load_rom(const char*);
uint8_t read_memory(uint16_t);
void write_memory(uint16_t, uint16_t);

int main(int argc, char **argv) {

    if(argc < 2) {
        printf("ERROR: expected 2 arguments\n");
        printf("USE: [./exe][PATH/TO/ROM]");
        exit(1);
    }

    char* rom_path = argv[1];
    initialize_memory();
    load_rom(rom_path);
    
    return 0;
}