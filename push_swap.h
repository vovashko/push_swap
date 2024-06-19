/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 13:26:16 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 16:32:38 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				cost;
	bool			is_cheapest;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

// Algorithm
int					stack_sorted(t_stack *stack);
void				sort_small_stack(t_stack **stack_a);
void				sort_big_stack(t_stack **stack_a, t_stack **stack_b);

// Cheapest search
t_stack				*get_cheapest(t_stack *stack);
void				find_cheapest(t_stack *stack);
void				find_cost(t_stack *stack_a, t_stack *stack_b);

// Pushers
void				push_cheapest_to_b(t_stack **stack_a, t_stack **stack_b);
void				push_back_to_a(t_stack **stack_a, t_stack **stack_b);

// Node finder
t_stack				*find_biggest(t_stack *stack);
t_stack				*find_smallest(t_stack *stack);
void				current_index(t_stack *stack);
void				target_for_b(t_stack *stack_a, t_stack *stack_b);
void				target_for_a(t_stack *stack_a, t_stack *stack_b);

// Error handling
int					arg_is_num(char *str);
int					error_duplicate(t_stack *stack, int num);
void				error_handler(t_stack **stack);
void				free_stack(t_stack **stack);
void				free_split(char **split);

// Utils
int					stack_size(t_stack *stack);
void				init_stack_a(t_stack **stack_a, int argc, char **argv);

// Commands
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif