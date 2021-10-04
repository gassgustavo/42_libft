/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoraes- <gmoraes-l@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:12:27 by gmoraes-          #+#    #+#             */
/*   Updated: 2021/10/04 00:24:07 by gmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_string(char *str, size_t size, size_t num, int is_negative)
{
	str[size] = 0;
	while (size--)
	{
		str[size] = (num % 10) + 48;
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

static size_t	num_counter(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	size_t	n_len;
	char	*str;

	n_len = num_counter(n);
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	str = malloc(n_len + 1);
	if (!str)
		return (0);
	return (get_string(str, n_len, (unsigned int)n, is_negative));
}
