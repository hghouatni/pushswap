/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:42 by macbook           #+#    #+#             */
/*   Updated: 2025/03/24 12:02:14 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_push(Stack *from, Stack *to) {
  Node *tmp;
  
  if (from == NULL || from->head == NULL)
    return;
  tmp = from->head;        
  from->head = from->head->next;
  tmp->next = to->head;
  to->head = tmp;
}

void ft_rotate(Stack *stack)
{
  Node *current;
  Node *tmp;
  
  if (stack->head == NULL || stack->head->next == NULL)
    return;
  tmp = stack->head;
  stack->head = tmp->next;
  tmp->next = NULL;
  current = stack->head;
  while (current->next)
  {
    current = current->next;
  }
  current->next = tmp;  
}

void ft_rrotate(Stack *stack)
{
  Node *current;
  Node *prev;
  Node *tmp;
  
  if (stack->head == NULL || stack->head->next == NULL)
    return;
  prev = NULL;
  tmp = stack->head;
  current = stack->head;
  
  while (current->next)
  {
    prev = current;
    current = current->next;
  }
  prev->next = NULL;
  current->next = tmp;
  stack->head = current;
}
