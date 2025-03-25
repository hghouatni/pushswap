/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:11:44 by macbook           #+#    #+#             */
/*   Updated: 2025/03/25 13:40:52 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sa(t_stack *stack_a) {
  if (stack_a->head == NULL || stack_a->head->next == NULL)
    return;
  ft_swap(stack_a);
  write(1, "sa\n", 3);
}