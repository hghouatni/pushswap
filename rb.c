/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:49:55 by macbook           #+#    #+#             */
/*   Updated: 2025/01/29 17:34:17 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb(Stack *stack_a)
{
  if (stack_a->head == NULL || stack_a->head->next == NULL)
    return;
  ft_rotate(stack_a);
  write(1, "rb\n", 3); 
}