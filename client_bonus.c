/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:13:48 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/30 18:11:36 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int server_pid, char *msg)
{
	int		i;
	int		bits;
	int		len;

	i = 0;
	len = ft_strlen(msg);
	while (i < len + 1)
	{
		bits = 0;
		while (bits < 8)
		{
			if ((msg[i] >> (7 - bits)) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			bits++;
		}
		i++;
	}
}

void	handler(int signumber)
{
	if (signumber == SIGUSR1)
	{
		write(1, "message received\n", 17);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(1, "message failled\n", 16);
		exit(EXIT_FAILURE);
	}
}

void	send_signal(int server_pid, char *msg)
{
	char	*mpid;

	mpid = ft_itoa(getpid());
	if (mpid == NULL)
		return ;
	send_message(server_pid, mpid);
	free(mpid);
	send_message(server_pid, msg);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, handler);
		send_signal(ft_atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
	else
		write(1, "usage: client <pid> <message>\n", 30);
}
