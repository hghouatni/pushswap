/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:30:21 by macbook           #+#    #+#             */
/*   Updated: 2025/03/27 11:44:20 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>



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
            num = ft_atoi(split_args[k]);
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

    if (stack->head == NULL)
        return (1);
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

// void count_sort(t_stack *stack_a, t_stack *stack_b, int size) {
    
// }

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
    //else
    //    count_sort(stack_a, stack_b, size);
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

void convert_to_indices(t_stack* stack) {
  // Create a copy of the original stack
  t_node* current = stack->head;
  
  // Create an array to store original values
  int size = 0;
  t_node* count_node = current;
  while (count_node) {
      size++;
      count_node = count_node->next;
  }
  
  int* original_values = malloc(size * sizeof(int));
  int* sorted_values = malloc(size * sizeof(int));
  
  // Copy original values
  current = stack->head;
  for (int i = 0; current; i++) {
      original_values[i] = current->data;
      sorted_values[i] = current->data;
      current = current->next;
  }
  
  // Sort the copied array
  for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
          if (sorted_values[j] > sorted_values[j + 1]) {
              int temp = sorted_values[j];
              sorted_values[j] = sorted_values[j + 1];
              sorted_values[j + 1] = temp;
          }
      }
  }
  
  // Replace values with their indices
  current = stack->head;
  for (int i = 0; current; i++) {
      // Find index of original value in sorted array
      for (int j = 0; j < size; j++) {
          if (original_values[i] == sorted_values[j]) {
              current->data = j;
              break;
          }
      }
      current = current->next;
  }
  
  // Free temporary arrays
  free(original_values);
  free(sorted_values);
}

int get_max_bits(t_stack* stack) {
  int max_num = 0;
  t_node* current = stack->head;
  
  // Find max number
  while (current) {
      if (current->data > max_num) {
          max_num = current->data;
      }
      current = current->next;
  }
  
  // Calculate number of bits
  int max_bits = 0;
  while ((max_num >> max_bits) != 0) {
      max_bits++;
  }
  
  return max_bits;
}

int get_bit(int num, int pos) {
  return (num >> pos) & 1;
}

void radix_sort(t_stack* stack_a, t_stack* stack_b, int size) {
  convert_to_indices(stack_a);
  
  int max_bits = get_max_bits(stack_a);
  
  for (int bit = 0; bit < max_bits; bit++) {
      int moves = 0;
      
      // Process all elements in stack_a for current bit
      while (moves < size) {
          int top_num = stack_a->head->data;
          
          // Check current bit using bitwise operations
          if (((top_num >> bit) & 1) == 1) {
              ra(stack_a);
          } else {
              pb(stack_a, stack_b);
          }
          
          moves++;
      }
      
      while (stack_b->head) {
          pa(stack_b, stack_a);
      }
  }
}

int main(int argc, char **argv)
{
    int size;
    t_stack stack_a;
    t_stack stack_b;
    
    if (argc < 2)
        return (0);
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

