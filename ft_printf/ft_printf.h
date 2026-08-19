/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:17:16 by smasatak          #+#    #+#             */
/*   Updated: 2026/08/05 12:12:57 by smasatak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_treat_char(int c);
int	ft_treat_str(char *s);
int	ft_treat_nbr(int n);
int	ft_treat_unsigned(unsigned int n);
int	ft_treat_hex(uintptr_t n, int uppercase);
int	ft_treat_ptr(void *ptr);

#endif
