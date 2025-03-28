/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:30 by hghoutan          #+#    #+#             */
/*   Updated: 2025/03/27 16:09:17 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		if (stack_b->head == NULL || stack_b->head->next == NULL)
			return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
