/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamkhobba <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:09:22 by adamkhobba        #+#    #+#             */
/*   Updated: 2024/02/18 11:09:24 by adamkhobba       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

// SIGUSR1 = 1
// SIGUSR2 = 0
void ft_client(int pid, char *str) {
  int i;
  int j;
  int k;

  i = 0;
  k = 0;
  while (str[k]) {
    j = 7;
    while (j >= 0) {
      if (str[i] >> j & 1) {
        kill(pid, SIGUSR1);
      } else {
        kill(pid, SIGUSR2);
      }
      usleep(1500);
      j--;
    }
    i++;
    k = i - 1;
  }
}

void coming_handler(int signal) {
  if (signal == SIGUSR2) {
    write(1, "MISSION COMPLETED\n", 18);
    exit(EXIT_SUCCESS);
  }
}

int main(int ac, char **av) {
  int pid;

  if (ac == 3) {
    pid = ft_atoi(av[1]);
    signal(SIGUSR2, coming_handler);
    ft_client(pid, av[2]);
  } else
    return (-1);
  while (1) {
    sleep(5);
  }
  return 0;
}
