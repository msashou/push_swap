/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:35:32 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/05 12:12:45 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s);

int	ft_treat_char(int s)
{
	if (write(1, &s, 1) != 1)
		return (-1);
	else
		return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_treat_str(char *str)
{
	size_t	len;
	int		er;

	len = 0;
	er = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	er = write(1, str, len);
	if (er == -1)
		return (-1);
	return (er);
}

int	ft_treat_nbr(int nb)
{
	long int	i;
	char		c;
	int			count;
	int			er;

	count = 0;
	i = nb;
	if (i < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		i = -i;
		count++;
	}
	er = 0;
	if (i >= 10)
		er = ft_treat_nbr(i / 10);
	if (er == -1)
		return (-1);
	count += er;
	c = (i % 10) + 48;
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_treat_unsigned(unsigned int nb)
{
	unsigned int	i;
	int				count;
	char			c;

	i = nb;
	count = 0;
	if (i >= 10)
	{
		count = ft_treat_unsigned(i / 10);
		if (count == -1)
			return (-1);
	}
	c = (i % 10) + 48;
	if (write(1, &c, 1) != 1)
		return (-1);
	else
		count++;
	return (count);
}
