/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:02:51 by macbook           #+#    #+#             */
/*   Updated: 2025/01/29 15:29:50 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void pb(Stack *stack_a, Stack *stack_b) {
  if (stack_a == NULL || stack_a->head == NULL)
    return;
  
  ft_push(stack_a, stack_b);
  write(1, "pb\n", 3);
}