/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:02:51 by macbook           #+#    #+#             */
/*   Updated: 2025/03/27 15:05:18 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void pb(t_stack *stack_a, t_stack *stack_b) {
  if (stack_a == NULL || stack_a->head == NULL)
    return ;
  
  ft_push(stack_a, stack_b);
  write(1, "pb\n", 3);
}