/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:19:12 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/24 15:03:23 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_node;

	t_node = (t_list *)malloc(sizeof(t_list));
	if (!t_node)
		return (NULL);
	t_node->content = content;
	t_node->next = 0;
	return (t_node);
}
