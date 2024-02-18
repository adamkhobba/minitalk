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

// SIGUSR1 = 0
// SIGUSR2 = 1
int main(int ac, char **av) {
  int n;
  int i;
  int j;
  i = 0;
  if (ac == 3)
  {
    n = ft_atoi(av[1]);

    while(av[2][i])
    {
       j = 7;
      while(j >= 0)
      {
          if(av[2][i] >> j & 1)
         {    
           kill(n, SIGUSR1);      
         }
        else
          kill(n, SIGUSR2);
        usleep(100);
        j--; 
      }
      i++;
    }
  }
}





// sfgfshjdhsljghjdfghsfjd