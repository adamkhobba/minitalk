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

// SIGUSR1 = 0
// SIGUSR2 = 1
int c = 0;

void ft_handler(int signal) 
{
  static char counter = 0;
  static char c;
    if(signal == SIGUSR1)
    {
        c = c << 1 | 1;
        counter++;
    }
    else if (signal == SIGUSR2)
    {
      c = c << 1;
      counter++;
    }
    if(counter == 8)
    {
      write(1,&c, 1);
      counter = 0;
      c = 0;
    }
   
}

int main() {

  ft_printf("Server PID 🗄️ :%d\n", getpid());
  signal(SIGUSR1, &ft_handler);
  signal(SIGUSR2, &ft_handler);
  while (1)
  {
    pause();
  }
  return 0;
}
