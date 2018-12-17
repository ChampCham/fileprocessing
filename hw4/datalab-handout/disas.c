#include <stdio.h>
#include <stdlib.h>
void print_hex_bytes(const unsigned char *raw_instr, int size){
         for (int i = 0; i <  size; i++){
             if (raw_instr[i] == 0){
                printf("00 ");
             }else{
                printf("%x ", raw_instr[i]);
             }   
         }
         printf("    ");
}
void disassemble(const unsigned char *raw_instr){
    char **registers =  (char **)malloc(sizeof(char*)*8);
    registers[0] = "%rax";
    registers[1] = "%rcx";
    registers[2] = "%rdx";
    registers[3] = "%rbx"; 
    registers[4] = "%rsp";
    registers[5] = "%rbp"; 
    registers[6] = "%rsi";
    registers[7] = "%rdi"; 
    
    if (raw_instr[0] == 0x68){
        print_hex_bytes(raw_instr, 5);
        int byte1 = (0xff & raw_instr[4]) << 24; 
        int byte2 = (0xff & raw_instr[3]) << 16;
        int byte3 = (0xff & raw_instr[2]) << 8;
        int byte4 = 0xff & raw_instr[1];
        int little_endian = byte1+byte2+byte3+byte4;
        printf("pushq $%#x\n", little_endian);
    }else if (raw_instr[0] == 0xff){ 
        int mask = 0xf8&raw_instr[1];
        int reg = raw_instr[1]&7;
        if (mask == 0x30){
            print_hex_bytes(raw_instr, 2);
            printf("pushq (%s)\n", registers[reg]);
        }else if (mask == 0x70){
            if (reg != 4){
                print_hex_bytes(raw_instr, 3);
                printf("pushq %#x(%s)\n",raw_instr[2],registers[reg]);
       
            }else{
                print_hex_bytes(raw_instr, 4);
                int shift = (raw_instr[2]&0xc0)>> 6;
                int scale = 1 << shift;
                int reg1 =  raw_instr[2]&0x7;
                int reg2 =  (raw_instr[2]&0x38)>> 3;
                printf("pushq %#x(%s,%s,%d)\n",raw_instr[3],registers[reg1], registers[reg2], scale);
            }
            
        }       
    }else{
        print_hex_bytes(raw_instr, 1);
        int mask = raw_instr[0]&7;
        printf("pushq %s\n", registers[mask]);
    }
    free(registers);
}
//int main(){
//  const unsigned char raw_instr[] = {0x68, 0x10, 0x3f, 0x00, 0x00};
//  const unsigned char raw_instr1[] = {0x53};
//  const unsigned char raw_instr2[] = {0xff, 0x32};
//  const unsigned char raw_instr3[] = {0xff, 0x70, 0x08};
//  const unsigned char raw_instr4[] = {0xff, 0x74, 0xcd, 0xff};

  //disassemble(raw_instr);
 // disassemble(raw_instr1);
 // disassemble(raw_instr2);
 // disassemble(raw_instr3);
 // disassemble(raw_instr4);
//}
