/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:10:11 by bbourcy           #+#    #+#             */
/*   Updated: 2022/04/30 18:12:31 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);

#endif
