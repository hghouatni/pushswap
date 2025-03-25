/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:11:44 by macbook           #+#    #+#             */
/*   Updated: 2025/03/25 13:40:52 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sb(t_stack *stack_b) {
  if (stack_b->head == NULL || stack_b->head->next == NULL)
    return;
  ft_swap(stack_b);
  write(1, "sb\n", 3); 
}