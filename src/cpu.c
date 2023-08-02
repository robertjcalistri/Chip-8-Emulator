#include <stdio.h>
#include <stdint.h>
#include "memory.h"

#define MEM_START 0x200

uint8_t V[16];
uint16_t I;
uint16_t PC;

void initialize_cpu(){

    PC = MEM_START;
    printf("Program counter initialized to 0x200\n");

    I = MEM_START;
    printf("Address register initialized to 0x200\n");

    for(int i = 0; i < 16; i++) {
        V[i] = 0;
    }

    printf("Initialized all register to value 0\n");
}

uint16_t fetch_opcode(uint16_t PC, uint8_t memory[]){

    uint8_t first_eight = memory[PC];
    uint8_t second_eight = memory[PC+1];
    uint16_t opcode = first_eight << 8 | second_eight;

    printf("First eight: %x\n Second eight: %x\n Opcode: %x\n", first_eight, second_eight, opcode);
    return opcode;
}

