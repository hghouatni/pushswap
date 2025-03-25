/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:14 by macbook           #+#    #+#             */
/*   Updated: 2025/03/25 15:20:35 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node {
    int data;
    struct s_node* next;
} t_node;

typedef struct s_stack {
    t_node* head;
} t_stack;

void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_b, t_stack *stack_a);
void ra(t_stack *stack_a);
void rb(t_stack *stack_a);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_a);
void rrr(t_stack *stack_a, t_stack *stack_b);
void print_stack(t_node *head);
void init_stack(t_stack *stack);
void push_stack(t_stack *stack, int data);
void ft_push(t_stack *from, t_stack *to);
void ft_rotate(t_stack *stack);
void ft_rrotate(t_stack *stack);
void ft_swap(t_stack *stack);
#endif