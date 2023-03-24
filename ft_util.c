/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:05:26 by jinwokim          #+#    #+#             */
/*   Updated: 2023/03/24 15:06:23 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, int *index)
{
	int	j;

	if (*index == -1)
		return ;
	j = 0;
	j = write(1, &c, 1);
	if (j == -1)
	{
		*index = -1;
		return ;
	}
	*index += 1;
}

void	ft_putstr(char *s, int *index)
{
	unsigned int	size;
	int				j;

	j = 0;
	size = 0;
	if (!s)
	{
		j = write(1, "(null)", 6);
		if (j == -1)
		{
			*index = -1;
			return ;
		}
		*index += 6;
		return ;
	}
	while (*(s + size))
		size++;
	j = write(1, s, size);
	if (j == -1)
	{
		*index = -1;
		return ;
	}
	*index += size;
}

static void	ft_printaddr(char *result, int i, int *index)
{
	while (i < 16)
	{
		if (*index == -1)
			return ;
		ft_putchar(result[i], index);
		i++;
	}
}

void	ft_putaddr(void *addr, int *index, char *charset)
{
	unsigned int	i;
	char			result[17];
	unsigned long	d;

	i = 15;
	d = (unsigned long)addr;
	ft_putstr("0x", index);
	if (!d)
		return (ft_putchar('0', index));
	result[16] = '\0';
	while (d)
	{
		result[i] = charset[(int)(d % 16)];
		d /= 16;
		i--;
	}
	while (i++ < 16)
	{
		if (result[i] != '0')
			break ;
	}
	ft_printaddr(result, i, index);
}
