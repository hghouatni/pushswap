/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:06:24 by hghoutan          #+#    #+#             */
/*   Updated: 2024/11/09 15:33:27 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *haystack, const char *needle, size_t i)
{
	size_t	j;

	j = 0;
	while (haystack[i + j] && needle[j])
	{
		if (haystack[i + j] != needle[j])
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	needle_len = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] && (i + needle_len <= len))
		{
			if (is_match(haystack, needle, i))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
