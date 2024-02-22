/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamkhobba <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:09:04 by adamkhobba        #+#    #+#             */
/*   Updated: 2024/02/18 15:20:32 by adamkhobba       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

// SIGUSR1 = 1
// SIGUSR2 = 0

void ft_handler(int signal, siginfo_t *info, void *context) {
  static char counter;
  static char c;
  int pid_client;

  (void)context;
  if (signal == SIGUSR1 || signal == SIGUSR2) {
    c = c << 1;
    if (signal == SIGUSR1)
      c += 1;
    counter++;
  }
  pid_client = info->si_pid;
  if (counter == 8) {
    if (c == '\0')
      kill(pid_client, SIGUSR2);
    write(1, &c, 1);
    counter = 0;
    c = 0;
  }
}

int main(void) {
  struct sigaction act;

  ft_printf("Server PID 🗄️ :%d\n", getpid());
  act.sa_sigaction = &ft_handler;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  while (1)
    ;
  return (0);
}
