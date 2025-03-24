/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:34:35 by macbook           #+#    #+#             */
/*   Updated: 2025/01/29 17:35:23 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rr(Stack *stack_a, Stack *stack_b)
{
  if (stack_a->head == NULL || stack_a->head->next == NULL)
    if (stack_b->head == NULL || stack_b->head->next == NULL)
      return;
  ft_rotate(stack_a);
  ft_rotate(stack_b);
  write(1, "rr\n", 3);
}