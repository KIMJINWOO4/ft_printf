/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:19:32 by jinwokim          #+#    #+#             */
/*   Updated: 2023/03/23 18:39:05 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static void	ft_write(int nbr, char *base, int i, int *index)
{
	if (nbr == 0)
		return ;
	else
	{
		ft_write(nbr / i, base, i, index);
		if (*index == -1)
			return ;
		ft_putchar(base[nbr % i], index);
	}
}

static void	ft_unswrite(unsigned int nbr, char *base, int i, int *index)
{
	if (nbr == 0)
		return ;
	else
	{
		ft_unswrite(nbr / i, base, i, index);
		if (*index == -1)
			return ;
		ft_putchar(base[nbr % i], index);
	}
}

void	ft_putnbr_base(int nbr, char *base, int *index)
{
	int			leng;
	int			sign;

	sign = 1;
	leng = base_check(base);
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2147483648", index);
			return ;
		}
		ft_putchar('-', index);
		nbr = -(nbr);
	}
	else if (nbr == 0)
	{
		ft_putchar('0', index);
		return ;
	}
	ft_write(nbr, base, leng, index);
}

void	ft_unsign_base(unsigned int nbr, char *base, int *index)
{
	int			leng;
	int			sign;

	sign = 1;
	leng = base_check(base);
	if (nbr == 0)
	{
		ft_putchar(base[0], index);
		return ;
	}
	ft_unswrite(nbr, base, leng, index);
}
