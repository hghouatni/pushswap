/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:49:55 by macbook           #+#    #+#             */
/*   Updated: 2025/03/25 13:40:52 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb(t_stack *stack_b)
{
  if (stack_b->head == NULL || stack_b->head->next == NULL)
    return;
  ft_rotate(stack_b);
  write(1, "rb\n", 3); 
}