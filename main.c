#include <stddef.h>     // for size_t
#include <stdint.h>     // for uint8_t
#include <stdio.h>      // for printf
#include <stdlib.h>     // for exit
#include <netinet/in.h> // for htons

void add_nbo(uint32_t first, uint32_t second){
    
    first = htonl(first);
    second = htonl(second);
    // format : 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", first, first, second, second, first+second, first+second);    
}

void usage(){
    puts("[!] usage   : ./add_nbo [first_binary_file_path] [second_binary_file_path]");
    puts("[!] example : ./add_nbo ./thousand.bin ./five-hundred.bin");
}

int main(int argc, char *argv[]){
    uint32_t first_data; 
    uint32_t second_data;
    
    if (argc < 2){
        usage();
        exit(0);
    }
    FILE * first_file = fopen(argv[1], "rb");
    if (first_file == NULL){
        printf("[!] %s file doesn't exist.\n", argv[1]);
        exit(0);
    }
    
    FILE * second_file = fopen(argv[2], "rb");
    if (second_file == NULL){
        printf("[!] %s file doesn't exist.\n", argv[2]);
        exit(0);
    }

    fread(&first_data, 4, 1, first_file);
    fread(&second_data, 4, 1, second_file);
    
    add_nbo(first_data, second_data);

    return 0;
}

