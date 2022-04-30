/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:16:37 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/30 16:16:30 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	bb_len(int n)
{
	size_t	l;

	l = 0;
	if (n <= 0)
		l = 1;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static unsigned long	bb_inttolong(int n)
{
	unsigned long	nb;

	if (n < 0)
		nb = -((unsigned long)n);
	else
		nb = (unsigned long)n;
	return (nb);
}

static unsigned long	bb_unit10(unsigned long nb)
{
	unsigned long	d;

	d = 1;
	if (nb == 0)
		return (1);
	while (nb)
	{
		d *= 10;
		nb /= 10;
	}
	return (d / 10);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned long	nb;
	size_t			i;
	size_t			d;
	size_t			l;

	i = 0;
	l = bb_len(n);
	nb = bb_inttolong(n);
	d = bb_unit10(nb);
	nbr = malloc(l + 1);
	if (!nbr)
		return (NULL);
	if (n < 0)
		nbr[i++] = '-';
	while (i < l)
	{
		nbr[i++] = '0' + ((nb / d) % 10);
		d = d / 10;
	}
	nbr[i] = '\0';
	return (nbr);
}
