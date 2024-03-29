#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 4096
#define MEM_START 0x200

uint8_t memory[MEM_SIZE];

void initialize_memory() {

    //Initializes memory array with 0x00 
    memset(memory, 0x00, MEM_SIZE);
}

void load_rom(const char* rom_path) {

    FILE *rom_file = NULL;
    rom_file = fopen(rom_path, "r");

    if(rom_file == NULL){
        perror("ERROR: Failed to open file: ");
    }
    else{
        printf("\nSUCCESS: Successfully opened: %s\n", rom_path);
    }

    if(fseek(rom_file,0,SEEK_END) == -1) {
        printf("ERROR: Failed to fseek %s\n", rom_path);
        exit(EXIT_FAILURE);
    }
    int fsize = ftell(rom_file);

    if(fsize == -1) {
        printf("ERROR: Failed to ftell %s\n", rom_path);
        exit(EXIT_FAILURE);
    }

    printf("[*] Filename: %s, \nFile Size: %d\n\n", rom_path, fsize);
    rewind(rom_file);

    char buffer[fsize];
    fread(buffer, 1, fsize, rom_file);

    if(fsize <= MEM_SIZE) {
        for(int i = 0; i <= fsize; i++) {

            memory[MEM_START + i] = buffer[i];
        }
        printf("SUCCESS: ROM successfully loaded into memory\n");
    }
    else {
        printf("ERROR: ROM size too large for memory\n");
    }
}

uint8_t read_memory(uint16_t address) {

    uint8_t data;

    if(address > 0 && address < MEM_SIZE) {

        data = memory[address];
        printf("SUCCESS: Data: %i succesfully read from address: %i\n", data, address);
    }
    else{
        //data = NULL;
        printf("ERROR: Invalid memory address\n");
    }
    return data;

}

void write_memory(uint16_t address, uint8_t value) {

    if(address > 0 && address < MEM_SIZE) {

        memory[address] = value;
        printf("SUCCESS: Value: %i successfully written to address: %i\n", value, address);
    }
    else{
        printf("ERROR: Invalid memory address\n");
    }

}
