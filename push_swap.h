/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hghoutan <hghoutan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:14 by macbook           #+#    #+#             */
/*   Updated: 2025/03/27 16:23:47 by hghoutan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
}					t_stack;

void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_b, t_stack *stack_a);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_a);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_a);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				print_stack(t_node *head);
void				init_stack(t_stack *stack);
void				push_stack(t_stack *stack, int data);
void				ft_push(t_stack *from, t_stack *to);
void				ft_rotate(t_stack *stack);
void				ft_rrotate(t_stack *stack);
void				ft_swap(t_stack *stack);
int					*ft_copy(t_stack *stack, int size);
int					*ft_copy_and_sort(t_stack *stack, int size);
void				radix_sort(t_stack *stack_a, t_stack *stack_b, int size);
void				small_sort(t_stack *stack_a, t_stack *stack_b, int arg_num);
int					get_size(t_stack *stack);
int					is_sorted(t_stack *stack);
int					validate_input(char **argv, t_stack *stack);
void				free_all(char **split_args);
int					ft_exist(t_stack *stack, int num);
t_node				*createt_node(int data);

#endif