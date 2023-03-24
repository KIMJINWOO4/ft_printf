/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:28:23 by jinwokim          #+#    #+#             */
/*   Updated: 2023/03/24 15:06:34 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_isprint(va_list ap, char c, int *index);
void	ft_putchar(unsigned char c, int *index);
int		ft_printf(const char *format, ...);
void	ft_putstr(char *s, int *index);
void	ft_putnbr_base(int nbr, char *base, int *index);
void	ft_unsign_base(unsigned int nbr, char *base, int *index);
void	ft_putaddr(void *addr, int *index, char *charset);
#endif