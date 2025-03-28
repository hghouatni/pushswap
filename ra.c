/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:07:31 by macbook           #+#    #+#             */
/*   Updated: 2025/03/28 16:51:03 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}
