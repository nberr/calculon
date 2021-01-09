#include <stdio.h>
#include <unistd.h>

#include "Calculon.h"

int main(int argc, char **argv) {
   FILE *suite;
   char directory[MAX_LEN] = {0};
   Program program;

   /* user must provide a suite file */
   if (argc != 2) {
      printf("Invalid number or args\n");
      return -1;
   }

   if (!(suite = fopen(argv[1], "r"))) {
      printf("Unable to open file\n");
      return -1;
   }

   /* set directory to be hidden */
   directory[0] = '.';
   sprintf(directory + 1, "%d", getpid());

   if(read_suite(suite, &program) < 0) {
      printf("Unable to read suite file\n");
      return -1;
   }

   return 0;
}
