#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 4096

static uint8_t memory[MEM_SIZE];

void initialize_memory() {

    //Initializes memory array with 0x00 
    memset(memory, 0x00, MEM_SIZE);
}

void load_rom(const char* rom_path) {

    FILE *rom_file = NULL;
    rom_file = fopen(rom_path, "r");

    if(rom_file == NULL){
        perror("Failed to open file: ");
    }
    else{
        printf("\nSuccessfully opened: %s\n", rom_path);
    }

    if(fseek(rom_file,0,SEEK_END) == -1) {
        printf("Failed to fseek %s\n", rom_path);
        exit(EXIT_FAILURE);
    }
    int fsize = ftell(rom_file);

    if(fsize == -1) {
        printf("Failed to ftell %s\n", rom_path);
        exit(EXIT_FAILURE);
    }

    printf("[*] Filename: %s, \nFile Size: %d\n\n", rom_path, fsize);
    rewind(rom_file);

    char buffer[fsize];
    fread(buffer, 1, fsize, rom_file);
}

uint8_t read_memory(uint16_t address) {

}

void write_memory(uint16_t address, uint8_t value) {

}
