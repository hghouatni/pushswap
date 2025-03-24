/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:14 by macbook           #+#    #+#             */
/*   Updated: 2025/01/29 15:46:23 by macbook          ###   ########.fr       */
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
void pb(Stack *stack_a, Stack *stack_b);
void ra(Stack *stack_a);
void rb(Stack *stack_a);
void rra(Stack *stack_a);
void print_stack(Node *head);
void init_stack(Stack *stack);
void push_stack(Stack *stack, int data);
void ft_push(Stack *from, Stack *to);
void ft_rotate(Stack *stack);
void ft_rrotate(Stack *stack);
#endif