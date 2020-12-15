#include <stdio.h>

// Takes in a stream of hexadecimal numbers and converts them to assembly
int Disassemble8080p(unsigned char *codebuffer, in pc)
{
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf("%04xd", pc);
    
    // A switch statement to convert hexadecimal to assembly
    switch (*code)
    {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI    B,#$%02x%02x", code[2], code[1]); opbytes=3; break;
        case 0x02: printf("STAX   B"); break;
        case 0x03: printf("INX    B"); break;
        case 0x04: printf("INR    B"); break;
        case 0x05: printf("DCR    B"); break;
        case 0x06: printf("MVI    B,#$%02x", code[1]); opbytes=2; break;
        case 0x07: printf("RLC"); break;
        case 0x08: printf("NOP"); break;
        case 0x09: printf("DCR    B"); break;
        case 0x0a: printf("DCR    B"); break;
        case 0x0b: printf("DCR    B"); break;
        case 0x0c: printf("DCR    B"); break;
        case 0x0d: printf("DCR    B"); break;
        case 0x0e: printf("DCR    B"); break;
        case 0x0f: printf("DCR    B"); break;
        case 0x10: printf("DCR    B"); break;
        case 0x11: printf("DCR    B"); break;
        case 0x12: printf("DCR    B"); break;
        case 0x13: printf("DCR    B"); break;
        case 0x14: printf("DCR    B"); break;
        case 0x15: printf("DCR    B"); break;
        case 0x16: printf("DCR    B"); break;
        case 0x17: printf("DCR    B"); break;
        case 0x18: printf("DCR    B"); break;
        case 0x19: printf("DCR    B"); break;
        case 0x1a: printf("DCR    B"); break;
        case 0x1b: printf("DCR    B"); break;
        case 0x1c: printf("DCR    B"); break;
        case 0x1d: printf("DCR    B"); break;
        case 0x1e: printf("DCR    B"); break;
        case 0x1f: printf("DCR    B"); break;
        case 0x03: printf("DCR    B"); break;
        case 0x03: printf("DCR    B"); break;
        case 0x03: printf("DCR    B"); break;
