/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:20:29 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/24 12:04:09 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	s_len;

	i = 0;
	count = 0;
	s_len = ft_strlen(s);
	if (s[i] != c && s[i])
		count++;
	while (s[i] && i < s_len - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*fill_word(char const *s, char c, int *index)
{
	int		i;
	int		count;
	char	*ptr;

	count = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	i = *(index);
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	ptr = malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[*index] != c && s[*index])
	{
		ptr[i++] = s[(*index)++];
	}
	ptr[i] = '\0';
	while (s[*index] == c && s[*index])
		(*index)++;
	return (ptr);
}

void	free_ptr(char **ptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		index;
	char	**ptr;

	i = 0;
	index = 0;
	count = count_words(s, c);
	ptr = (char **)malloc((count + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (i < count)
	{
		ptr[i] = fill_word(s, c, &index);
		if (ptr[i] == NULL)
		{
			free_ptr(ptr, i);
			return (NULL);
		}
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
