/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:30:21 by macbook           #+#    #+#             */
/*   Updated: 2025/03/24 16:45:51 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int ft_exist(Stack *stack, int num) {
    Node *current = stack->head;
    while (current != NULL) {
        if ((long)current->data == num)
            return 1;
        current = current->next;
    }
    return 0;
}

void free_split(char **split_args) {
    int i;
    
    i = 0;
    while (split_args[i]) {
        free(split_args[i]);
        i++;
    }
    free(split_args);
}

int validate_input(char **argv, Stack *stack) {
    char **split_args;
    int i;
    int j;
    int k;
    long num;

    i = 1;
    while (argv[i]) {
        split_args = ft_split(argv[i], ' ');
        k = 0;
        while (split_args[k]) {
            j = 0;
            if (split_args[k][j] == '-')
                j++;
            if (split_args[k][j] == '\0')
                return 0;
            while (split_args[k][j]) {
                if ((split_args[k][j] < '0' || split_args[k][j] > '9'))
                    return 0;
                j++;
            }
            num = ft_atoi(split_args[k]);
            if (num > 2147483647 || num < -2147483648)
                return 0;
            if (ft_exist(stack, num))
                return 0;
            push_stack(stack, num);
            k++;
        }
        free_split(split_args);
        i++;
    }
    return 1;
}



Node* createNode(long data) {
  Node* new_node;
  
  new_node = (Node*)malloc(sizeof(Node));
  new_node->data = (void*)data;
  new_node->next = NULL;
  return new_node;
}

void push_stack(Stack *stack, int data) {
    Node* node;
    Node *current;
    
    node = createNode(data);
    if (stack->head == NULL) {
        stack->head = node;
        return;
    }
    current = stack->head;
    if (node == NULL)
        return;
    while (current->next)
        current = current->next;
    current->next = node;
}

void print_stack(Node *head) {
  Node* current;

  current = head;
  while (current) {
    printf("%ld\n", (long)current->data);
    current = current->next;
  }
}

int main(int argc, char **argv)
{
    int i;
    Stack stack_a;
    Stack stack_b;
    
    if (argc < 2)
        return (0);
    i = 1;
    stack_a.head = NULL;
    stack_b.head = NULL;
    if (validate_input(argv, &stack_a))
    {
        //sa(&stack_a);
        // pb(&stack_a, &stack_b);
        // pb(&stack_a, &stack_b);
        // pb(&stack_a, &stack_b);
        
         ra(&stack_a);
        // rb(&stack_b);

        //rr(&stack_a, &stack_b);
        
        // rra(&stack_a);
        // rrb(&stack_b);
        
        // sb(&stack_b);
        // rra(&stack_a);
        // pb(&stack_a, &stack_b);
        // pb(&stack_a, &stack_b);
        
        
        print_stack((&stack_a)->head);
        printf("\n");
        printf("\n");
        print_stack((&stack_b)->head);
    
    }
    else
        write(1, "Error\n", 6);
    return (0);
}

