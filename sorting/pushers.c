/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 11:35:24 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 11:44:44 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	cheapest_on_top(t_stack **top_node, t_stack *cheapest, char stack)
{
	while (*top_node != cheapest)
	{
		if (stack == 'a')
		{
			if (cheapest->above_median)
				ra(top_node);
			else
				rra(top_node);
		}
		else if (stack == 'b')
		{
			if (cheapest->above_median)
				rb(top_node);
			else
				rrb(top_node);
		}
	}
}

void	push_cheapest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rr(stack_a, stack_b);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
	cheapest_on_top(stack_a, cheapest, 'a');
	cheapest_on_top(stack_b, cheapest->target, 'b');
	pb(stack_a, stack_b);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	cheapest_on_top(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}
