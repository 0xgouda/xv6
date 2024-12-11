#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int
main(int argc, char *argv[])
{
  for (uint i = atoi(argv[1]); i < atoi(argv[2]); i++) {
    uint phys_addr = v2paddr(i);
    if (!phys_addr) {
      printf(1, "Invalid Virtual Address\n");
    }
    printf(1, "Physical Address Of 0x%d: %d\n", i, phys_addr);
  }
  exit();
}
