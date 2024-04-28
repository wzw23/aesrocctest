#include <stdio.h>
#include <riscv-pk/encoding.h>
#include "marchid.h"

int main(void) {
  int c=1+2;
  printf("Hello world from core 0, c=%d\n", c);
   __asm__ __volatile__(
     ".word 0x0000006b\n\t"
     ::: /* No clobber list */
     );
  return 0;
}
