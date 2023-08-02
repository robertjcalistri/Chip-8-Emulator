#include <stdlib.h>
#include <stdint.h>

#ifndef MEMORY_H
#define MEMORY_H
#define MEM_SIZE 4096

extern uint8_t memory[MEM_SIZE];

void initialize_memory();
void load_rom(const char* rom_path);
uint8_t read_memory(uint16_t address);
void write_memory(uint16_t address, uint8_t value);

#endif 