/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoda <rnoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 22:44:12 by rnoda             #+#    #+#             */
/*   Updated: 2026/08/19 22:44:13 by rnoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *result;
	size_t i;
	size_t total_size;

	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (__SIZE_MAX__ / size < nmemb)
		return (NULL);
	total_size = size * nmemb;
	result = (void *)malloc(total_size);
	if (result == NULL)
		return (result);
	i = 0;
	while (i < total_size)
		((unsigned char *)result)[i++] = 0;
	return (result);
}