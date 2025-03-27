/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:42 by macbook           #+#    #+#             */
/*   Updated: 2025/03/27 15:31:33 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_push(t_stack *from, t_stack *to) {
  t_node *tmp;
  
  if (from == NULL || from->head == NULL)
    return;
  tmp = from->head;        
  from->head = from->head->next;
  tmp->next = to->head;
  to->head = tmp;
}

void ft_rotate(t_stack *stack)
{
  t_node *current;
  t_node *tmp;
  
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

void ft_rrotate(t_stack *stack)
{
  t_node *current;
  t_node *prev;
  t_node *tmp;
  
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

void ft_swap(t_stack *stack)
{
  t_node *tmp;
  t_node *current;
  
  if (stack->head == NULL || stack->head->next == NULL) {
      return ;
  }
  current = stack->head;
  tmp = current->next;
  current->next = tmp->next;
  tmp->next = current;
  stack->head = tmp;
}
