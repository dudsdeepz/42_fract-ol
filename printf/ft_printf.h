/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:32 by eduarodr          #+#    #+#             */
/*   Updated: 2022/11/18 10:26:37 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		fmtspec(char a, va_list arg);
int		ft_putnbr(int c);
int		ft_putnbr_uns(int c);
int		ft_printf(const char *format, ...);
int		ft_nbrhex(unsigned long int c, const char *b);
int		ft_pt(unsigned long int c, const char *b, int flag);
#endif
