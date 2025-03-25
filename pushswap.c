/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:30:21 by macbook           #+#    #+#             */
/*   Updated: 2025/03/25 13:30:38 by hghoutan         ###   ########.fr       */
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

void free_all(char **split_args) {
    int i;
    
    i = 0;
    while (split_args[i]) {
        free(split_args[i]);
        i++;
    }
    free(split_args);
}

long	ft_atoi2(const char *str)
{
	int	ng;
	long	num;

	ng = 1;
	num = 0;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ng = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
        if (num > 2147483647 && ng == 1)
            return (2147483648);
        if (num > 2147483648 && ng == -1)
            return (-2147483649);
		str++;
	}
	return (num * ng);
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
            if (split_args[k][j] == '-' || split_args[k][j] == '+')
                j++;
            if (split_args[k][j] == '\0')
                return (free_all(split_args), 0);
            while (split_args[k][j]) {
                if ((split_args[k][j] < '0' || split_args[k][j] > '9'))
                    return (free_all(split_args), 0);
                j++;
            }
            num = ft_atoi2(split_args[k]);
            if (num > 2147483647 || num < -2147483648)
                return (free_all(split_args), 0);
            if (ft_exist(stack, num))
                return (free_all(split_args), 0);
            push_stack(stack, num);
            k++;
        }
        free_all(split_args);
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
    if (node == NULL)
        return;
    if (stack->head == NULL) 
        return (void)(stack->head = node);
    current = stack->head;
    while (current->next)
        current = current->next;
    current->next = node;
}

void print_stack(Node *head) {
  Node* current;

  current = head;
  while (current) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

int is_sorted(Stack *stack) {
    Node *current;
    int max;

    current = stack->head;
    while (current->next) {
        if (current->data > (current->next->data))
            return (0);
        current = current->next;
    }
    return (1);
}

int get_size(Stack *stack) {
    Node *current;
    int size;
    
    size = 0;
    current = stack->head;
    while (current) {
        size++;
        current = current->next;
    }
    return (size);
}

void sort_small_stack(Stack *stack_a, Stack *stack_b, int size) {
    if (size == 2) {
        sa(stack_a);
    }
    // else if (size == 3) {
    //     if (stack_a->head->data > stack_a->head->next->data && stack_a->head->data < stack_a->head->next->next->data)
    //         sa(stack_a);
    //     else if (stack_a->head->data > stack_a->head->next->data && stack_a->head->data > stack_a->head->next->next->data)
    //     {
    //         sa(stack_a);
    //         rra(stack_a);
    //     }
    //     else if (stack_a->head->data < stack_a->head->next->data && stack_a->head->data > stack_a->head->next->next->data)
    //         ra(stack_a);
    //     else if (stack_a->head->data < stack_a->head->next->data && stack_a->head->data < stack_a->head->next->next->data)
    //     {
    //         sa(stack_a);
    //         ra(stack_a);
    //     }
    // }
    // else if (size == 4) {
    //     pb(stack_a, stack_b);
    //     pb(stack_a, stack_b);
    //     sort_small_stack(stack_a, stack_b, 2);
    //     pa(stack_b, stack_a);
    //     pa(stack_b, stack_a);
    // }
}

void free_stack(Stack *stack) {
    Node *current;
    Node *temp;

    current = stack->head;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    stack->head = NULL;
}

int main(int argc, char **argv)
{
    int i;
    int size;
    Stack stack_a;
    Stack stack_b;
    
    if (argc < 2)
        return (0);
    i = 1;
    stack_a.head = NULL;
    stack_b.head = NULL;
    if (validate_input(argv, &stack_a))
    {
        // if (is_sorted(&stack_a))
        //     return (0);
        // size = get_size(&stack_a);
        // if (size < 5)
        //     sort_small_stack(&stack_a, &stack_b, size);
        
        // //sa(&stack_a);
        // // pb(&stack_a, &stack_b);
        // // pb(&stack_a, &stack_b);
        // // pb(&stack_a, &stack_b);
        
        //  ra(&stack_a);
        // // rb(&stack_b);

        // //rr(&stack_a, &stack_b);
        
        // // rra(&stack_a);
        // // rrb(&stack_b);
        
        // // sb(&stack_b);
        // // rra(&stack_a);
        // // pb(&stack_a, &stack_b);
        // // pb(&stack_a, &stack_b);
        
        
        // print_stack((&stack_a)->head);
        // printf("\n");
        // printf("\n");
        // print_stack((&stack_b)->head);
    
    }
    else
        write(1, "Error\n", 6);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}

