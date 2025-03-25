/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:30:21 by macbook           #+#    #+#             */
/*   Updated: 2025/03/25 15:44:08 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int ft_exist(t_stack *stack, int num) {
    t_node *current = stack->head;
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

int validate_input(char **argv, t_stack *stack) {
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



t_node* createt_node(int data) {
  t_node* new_node;
  
  new_node = (t_node*)malloc(sizeof(t_node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void push_stack(t_stack *stack, int data) {
    t_node* node;
    t_node *current;
    
    node = createt_node(data);
    if (node == NULL)
        return;
    if (stack->head == NULL) 
        return (void)(stack->head = node);
    current = stack->head;
    while (current->next)
        current = current->next;
    current->next = node;
}

void print_stack(t_node *head) {
  t_node* current;

  current = head;
  while (current) {
    printf("%ld\n", (long)current->data);
    current = current->next;
  }
}

int is_sorted(t_stack *stack) {
    t_node *current;
    int max;

    current = stack->head;
    while (current->next) {
        if (current->data > (current->next->data))
            return (0);
        current = current->next;
    }
    return (1);
}

int get_size(t_stack *stack) {
    t_node *current;
    int size;
    
    size = 0;
    current = stack->head;
    while (current) {
        size++;
        current = current->next;
    }
    return (size);
}

void sort_three(t_stack *stack) {
    int a;
    int b;
    int c;

    a = (long)stack->head->data;
    b = (int)stack->head->next->data;
    c = (int)stack->head->next->next->data;

    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c && a > c) {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b > c && a < c)
        ra(stack);
    else if (a < b && b > c && a < c) {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

void count_sort(t_stack *stack_a, t_stack *stack_b, int size) {
    
}

void sort_small_stack(t_stack *stack_a, t_stack *stack_b, int size) {
    if (size == 1)
        return;
    else if (size == 2) {
        sa(stack_a);
    }
    while (size > 3) {
        pb(stack_a, stack_b);
        size--;
    }
    sort_three(stack_a);
    else
        count_sort(stack_a, stack_b, size);
}

void free_stack(t_stack *stack) {
    t_node *current;
    t_node *temp;

    current = stack->head;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    stack->head = NULL;
}

int getMax(t_stack *stack_a, int n)
{
    t_node *current;
    int max;
    
    max = 0;
    current = stack_a->head;
    while (current) {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int arr[], int n, int exp)
{

    // Output array
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(t_stack stack_a, t_stack stack_b, int n)
{
    int m = getMax(stack_a, n);
}

int main(int argc, char **argv)
{
    int i;
    int size;
    t_stack stack_a;
    t_stack stack_b;
    
    if (argc < 2)
        return (0);
    i = 1;
    stack_a.head = NULL;
    stack_b.head = NULL;
    if (validate_input(argv, &stack_a))
    {
        if (is_sorted(&stack_a))
            return (0);
        size = get_size(&stack_a);
        if (size < 20)
            sort_small_stack(&stack_a, &stack_b, size);
        else
            radix_sort(&stack_a, &stack_b, size);
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

