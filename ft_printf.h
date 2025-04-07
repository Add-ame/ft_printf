/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddame <maddame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:41:13 by maddame           #+#    #+#             */
/*   Updated: 2024/11/12 09:23:30 by maddame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_data
{
	long unsigned int	nb;
	long long			nbint;
	va_list				ap;
	int					count;
	int					ch;
	int					i;
	int					ih;
	int					j;
	int					upint;
	int					uphex;
	int					adrs;
	char				buf[10];
}	t_data;

typedef struct s_format
{
	const char	*sep;
	int			(*f)(struct s_data *);
}	t_format;

int	ft_printf(const char *format, ...);
int	ft_putnbr(t_data *data);
int	ft_putstr(t_data *data);
int	ft_puthex(t_data *data);
int	ft_putchar(t_data *data);

#endif
