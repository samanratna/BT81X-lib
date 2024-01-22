//
// Created by peter on 4/2/2023.
//

#ifndef TEST_PRINT_H
#define TEST_PRINT_H

#include <stdint.h>
#include <stdarg.h>

void printChar(char ch);
void printString(char*str,uint32_t len);
uint32_t sprint(char*buff ,const char * format, ...);

uint32_t print(const char * format, ...);


#endif //TEST_PRINT_H
