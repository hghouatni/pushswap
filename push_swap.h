/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:14 by macbook           #+#    #+#             */
/*   Updated: 2025/03/24 16:37:29 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct Node {
    void *data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

void sa(Stack *stack);
void sb(Stack *stack);
void ss(Stack *stack_a, Stack *stack_b);
void pb(Stack *stack_a, Stack *stack_b);
void pa(Stack *stack_b, Stack *stack_a);
void ra(Stack *stack_a);
void rb(Stack *stack_a);
void rr(Stack *stack_a, Stack *stack_b);
void rra(Stack *stack_a);
void rrb(Stack *stack_a);
void rrr(Stack *stack_a, Stack *stack_b);
void print_stack(Node *head);
void init_stack(Stack *stack);
void push_stack(Stack *stack, int data);
void ft_push(Stack *from, Stack *to);
void ft_rotate(Stack *stack);
void ft_rrotate(Stack *stack);
void ft_swap(Stack *stack);
#endif