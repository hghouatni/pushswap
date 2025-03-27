/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:53:45 by macbook           #+#    #+#             */
/*   Updated: 2025/03/27 16:09:01 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rra(t_stack *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	ft_rrotate(stack_a);
	write(1, "rra\n", 4);
}
