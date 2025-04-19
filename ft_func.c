/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddame <maddame@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:13:49 by maddame           #+#    #+#             */
/*   Updated: 2024/11/12 10:48:43 by maddame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (data->upint == 1)
		data->nbint = va_arg(data->ap, unsigned int);
	else
		data->nbint = va_arg(data->ap, int);
	if (data->nbint < 0 && ++count)
	{
		write(1, "-", 1);
		data->nbint = -(data->nbint);
	}
	else if (data->nbint == 0)
		data->buf[i++] = '0';
	while (data->nbint)
	{
		data->buf[i++] = (data->nbint % 10) + 48;
		data->nbint /= 10;
	}
	count += i;
	while (--i >= 0)
		write(1, &data->buf[i], 1);
	return (count);
}

int	ft_putstr(t_data *data)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(data->ap, char *);
	if (!s)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ndi(t_data *data)
{
	if (data->adrs == 1)
	{
		data->nb = va_arg(data->ap, unsigned long);
		if (data->nb == 0)
		{
			data->ch += write(1, "(nil)", 5);
			return (-1);
		}
		data->ch += write(1, "0x", 2);
	}
	else
		data->nb = va_arg(data->ap, unsigned int);
	return (1);
}

int	ft_putchar(t_data *data)
{
	char	c;

	c = va_arg(data->ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_puthex(t_data *data)
{
	char	*hex;
	char	buf[16];

	if (ndi(data) == -1)
		return (data->ch);
	if (data->uphex == 1)
		hex = "0123456789ABCDEF";
	else if (!data->uphex || data->adrs == 1)
		hex = "0123456789abcdef";
	if (data->nb == 0)
	{
		data->ch += write(1, "0", 1);
		return (data->ch);
	}
	while (data->nb)
	{
		buf[data->ih++] = hex[(data->nb % 16)];
		data->nb /= 16;
	}
	while (--data->ih >= 0)
		data->ch += write(1, &buf[data->ih], 1);
	return (data->ch);
}
