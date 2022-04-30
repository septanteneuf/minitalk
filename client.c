/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:13:48 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/30 18:02:30 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		d;

	if (argc == 3)
	{
		d = 0;
		str = argv[2];
		while (str[d])
		{
			i = 0;
			while (i < 8)
			{
				if ((str[d] >> (7 - i)) & 1)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				usleep(100);
				i++;
			}
			d++;
		}
	}
	else
		write(1, "usage: client <pid> <message>", 29);
}
