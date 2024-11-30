#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc != 3) {
    exit();
  }

  int tickets_set = settickets(atoi(argv[2]));
  if (tickets_set == 0) {
    int x = 0;
    for(i=1; i < atoi(argv[1]); i++) {
      x += 1;
      printf(1, "process with %s runs\n", argv[2]);
    }
  }
  exit();
}
