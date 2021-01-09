#include <stdio.h>

#ifndef CALCULON_H
#define CALCULON_H

#define MAX_LEN 64

typedef struct argument_t {
   char value[MAX_LEN];
   struct argument_t *next;
} Argument, Pfiles;

typedef struct test_t {
   char in[MAX_LEN];
   char out[MAX_LEN];
   int timeout;

   int argc;
   Argument *argv;

   struct test_t *next;
} Test;

typedef struct program_t {
   char executable[MAX_LEN];
   Pfiles *files;
   Test *tests;
} Program;
int read_suite(FILE* suite, Program* p);

#endif

