/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:17:49 by hghoutan          #+#    #+#             */
/*   Updated: 2024/11/07 22:10:55 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_digits(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_string(char *str, int n, int ng)
{
	int	i;

	if (ng)
		str[0] = '-';
	i = num_of_digits(n) + ng;
	str[i--] = '\0';
	while (n > 9)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	str[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		ng;
	char	*str;

	ng = 0;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		n = -n;
		ng = 1;
	}
	str = (char *)malloc(num_of_digits(n) + ng + 1);
	if (str == NULL)
		return (NULL);
	fill_string(str, n, ng);
	return (str);
}
