/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cheapest_search.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 15:12:24 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 11:35:17 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	long	cheapest_cost;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->is_cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	find_cost(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->cost = stack_size(stack_a) - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += stack_size(stack_b) - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}
