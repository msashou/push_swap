/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:14:07 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/05 12:12:37 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char c, va_list *ap);
static int	ft_handle_non_percent(const char *format, int *i);
static int	ft_handle_percent_error(const char *format, int *i, va_list *ap);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			er;
	int			count;

	va_start(ap, format);
	count = 0;
	i = 0;
	er = 0;
	while (format[i])
	{
		if (format[i] == '%')
			er = ft_handle_percent_error(format, &i, &ap);
		else
			er = ft_handle_non_percent(format, &i);
		if (er == -1)
			return (-1);
		count += er;
		i++;
	}
	va_end(ap);
	return (count);
}

static int	ft_handle_percent_error(const char *format, int *i, va_list *ap)
{
	int	er;

	er = 0;
	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	er = ft_conversion(format[*i], ap);
	return (er);
}

static int	ft_handle_non_percent(const char *format, int *i)
{
	int	count;

	count = 0;
	if (write(1, &format[*i], 1) == -1)
		return (-1);
	count++;
	return (count);
}

static int	ft_conversion(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_treat_char(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_treat_str(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_treat_nbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_treat_unsigned(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (ft_treat_hex(va_arg(*ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_treat_hex(va_arg(*ap, unsigned int), 1));
	else if (c == 'p')
		return (ft_treat_ptr(va_arg(*ap, void *)));
	else if (c == '%')
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		else
			return (1);
	}
	return (0);
}
