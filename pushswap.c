/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:30:21 by macbook           #+#    #+#             */
/*   Updated: 2025/03/24 12:05:29 by hghoutan         ###   ########.fr       */
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

int validate_input(char **argv) {
  Stack stack;
  int i;
  int j;
  long num;
//   char **split_args;
//   int k;

  i = 1;
  init_stack(&stack);
  while (argv[i]) {
    //   if (strchr(argv[i], ' ') || strchr(argv[i], '\t')) {
    //       split_args = ft_split(argv[i], " \t");
    //       k = 0;
    //       while (split_args[k]) {
    //           j = 0;
    //           if (split_args[k][j] == '-')
    //               j++;
    //           if (split_args[k][j] == '\0')
    //               return 0;
    //           while (split_args[k][j]) {
    //               if ((split_args[k][j] < '0' || split_args[k][j] > '9'))
    //                   return 0;
    //               j++;
    //           }
    //           num = ft_atoi(split_args[k]);
    //           if (num > 2147483647 || num < -2147483648)
    //               return 0;
    //           if (ft_exist(&stack, num))
    //               return 0;
    //           push_stack(&stack, num);
    //           k++;
    //       }
    //       free_split(split_args);
    //   } else {
          j = 0;
          if (argv[i][j] == '-')
              j++;
          if (argv[i][j] == '\0')
              return 0;
          while (argv[i][j]) {
              if ((argv[i][j] < '0' || argv[i][j] > '9'))
                  return 0;
              j++;
          }
          num = ft_atoi(argv[i]);
          if (num > 2147483647 || num < -2147483648)
              return 0;
          if (ft_exist(&stack, num))
              return 0;
          push_stack(&stack, num);
    //   }
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
    
    node = createNode(data);
    if (node == NULL)
        return;
    node->next = stack->head;
    stack->head = node;
}

void print_stack(Node *head) {
  Node* current;

  current = head;
  while (current) {
    printf("%ld\n", (long)current->data);
    current = current->next;
  }
}

void init_stack(Stack *stack)
{
  stack->head = NULL;
}

int main(int argc, char **argv)
{
  int i;
  Stack stack_a;
  Stack stack_b;
  
  if (argc < 2)
    return (0);
  i = 1;
  init_stack(&stack_a);
  init_stack(&stack_b);
  if (validate_input(argv))
  {
    // while (argv[i] != NULL)
    // {
    //   push_stack(&stack_a, ft_atoi(argv[i]));
    //   i++;
    // }
    //sa(&stack_a);
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    // rra(&stack_a);
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    
    // print_stack((&stack_b)->head);
    // printf("\n");
    print_stack((&stack_a)->head);
  }
  else
    write(1, "Error\n", 6);
  return (0);
}

