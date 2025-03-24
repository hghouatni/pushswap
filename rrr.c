/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:26:00 by macbook           #+#    #+#             */
/*   Updated: 2025/01/29 17:05:10 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrr(Stack *stack_a, Stack *stack_b)
{
  if (stack_a->head == NULL || stack_a->head->next == NULL)
    if (stack_b->head == NULL || stack_b->head->next == NULL)
      return;
  ft_rrotate(stack_a);
  ft_rrotate(stack_b);
  write(1, "rrr\n", 4);
}