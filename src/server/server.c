#include "../../include/minitalk.h"

// SIGUSR1 = 0
// SIGUSR2 = 1
int c;

void ft_handler(int signal) {

  if (signal == SIGUSR1)
    c <<= 1;
  else if (signal == SIGUSR2) {
    c += 1;
    c <<= 1;
  }
}

int main() {

  ft_printf("Server PID 🗄️ :%d", getpid());
  signal(SIGUSR1, &ft_handler);
  signal(SIGUSR2, &ft_handler);
  while (1)
    continue;
  return 0;
}
