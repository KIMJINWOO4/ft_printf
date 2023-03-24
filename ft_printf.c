/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:30:16 by jinwokim          #+#    #+#             */
/*   Updated: 2023/03/24 15:54:46 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isprint(va_list ap, char c, int *index)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), index);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), index);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), "0123456789", index);
	else if (c == 'u')
		ft_unsign_base(va_arg(ap, unsigned int), "0123456789", index);
	else if (c == 'p')
		ft_putaddr(va_arg(ap, void *), index, "0123456789abcdef");
	else if (c == 'x')
		ft_unsign_base(va_arg(ap, unsigned int), "0123456789abcdef", index);
	else if (c == 'X')
		ft_unsign_base(va_arg(ap, unsigned int), "0123456789ABCDEF", index);
	else if (c == '%')
		ft_putchar(c, index);
	else
		*index = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (*(format))
	{
		if (*(format) == '%')
		{
			format++;
			ft_isprint(ap, *(format), &i);
		}
		else
			ft_putchar(*(format), &i);
		if (i == -1)
		{
			va_end(ap);
			return (i);
		}
		format++;
	}
	va_end(ap);
	return (i);
}
