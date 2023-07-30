#include <stdlib.h>
#include <stdint.h>

void initialize_memory();
void load_rom(const char* rom_path);
uint8_t read_memory(uint16_t address);
void write_memory(uint16_t address, uint8_t value);