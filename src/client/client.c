#include "../../include/minitalk.h"

// SIGUSR1 = 0
// SIGUSR2 = 1
int main(int ac, char **av) {
  int n;
  int i;

  i = 0;
  if (ac != 3) {
    n = ft_atoi(av[1]);
    while (av[2][i]) {
      while (av[2][i]) {
        if (!(av[2][i] & 1))
          kill(n, SIGUSR1);
        else
          kill(n, SIGUSR2);
        av[1][i] >>= 1;
      }
      i++;
    }
  }
  return 0;
}
