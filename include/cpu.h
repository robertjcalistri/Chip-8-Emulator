#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

extern int16_t PC;

void initialize_cpu();
uint16_t fetch_opcode(uint16_t PC, uint8_t memory[]);