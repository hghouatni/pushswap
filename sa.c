/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:11:44 by macbook           #+#    #+#             */
/*   Updated: 2025/01/27 17:50:18 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sa(Stack *stack) {
  Node *tmp;
  Node *current;

  if (stack->head == NULL || stack->head->next == NULL) {
      return ;
  }
  
  current = stack->head;
  tmp = current->next;
  
  current->next = tmp->next;
  tmp->next = current;
  
  stack->head = tmp;
}