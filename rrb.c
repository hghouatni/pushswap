/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:18:39 by macbook           #+#    #+#             */
/*   Updated: 2025/01/29 16:20:12 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void rrb(Stack *stack_a)
{
  if (stack_a->head == NULL || stack_a->head->next == NULL)
    return;
  ft_rrotate(stack_a);
  write(1, "rra\n", 4);
}