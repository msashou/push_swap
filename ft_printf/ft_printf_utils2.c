/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 01:24:24 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/05 12:12:50 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_ptr(void *ptr)
{
	uintptr_t	addr;
	int			count;
	int			er;

	count = 0;
	er = 0;
	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		else
			return (5);
	}
	addr = (uintptr_t)ptr;
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	er = ft_treat_hex(addr, 0);
	if (er == -1)
		return (-1);
	count += er;
	return (count);
}

int	ft_treat_hex(uintptr_t n, int uppercase)
{
	char	*base;
	int		count;
	char	c;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count = ft_treat_hex(n / 16, uppercase);
		if (count == -1)
			return (-1);
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		count++;
	return (count);
}
