/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:22:33 by macbook           #+#    #+#             */
/*   Updated: 2025/03/24 16:35:29 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void pa(Stack *stack_b, Stack *stack_a) {  
  if (stack_b == NULL || stack_b->head == NULL)
    return;
  
  ft_push(stack_b, stack_a);
  write(1, "pa\n", 3);
}