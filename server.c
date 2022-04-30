/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:13:45 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/30 18:12:02 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signumber)
{
	static int		i = 0;
	static char		msg = 0;

	if (i < 8)
	{
		msg = (msg << 1) + (signumber == SIGUSR1);
		i++;
	}
	if (i == 8)
	{
		write(1, &msg, 1);
		i = 0;
		msg = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (1);
}
