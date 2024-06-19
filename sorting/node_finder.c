/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_finder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 16:34:13 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 11:44:34 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;
	long	biggest_num;

	if (!stack)
		return (NULL);
	biggest_num = LONG_MIN;
	while (stack)
	{
		if (stack->num > biggest_num)
		{
			biggest = stack;
			biggest_num = stack->num;
		}
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	long	smallest_num;

	if (!stack)
		return (NULL);
	smallest_num = LONG_MAX;
	while (stack)
	{
		if (stack->num < smallest_num)
		{
			smallest_num = stack->num;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		(stack)->index = i;
		if (i <= median)
			(stack)->above_median = true;
		else
			(stack)->above_median = false;
		i++;
		stack = (stack)->next;
	}
}

void	target_for_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*target;
	long	closest;

	while (stack_b)
	{
		closest = LONG_MAX;
		current = stack_a;
		while (current)
		{
			if (current->num > stack_b->num && current->num < closest)
			{
				closest = current->num;
				target = current;
			}
			current = current->next;
		}
		if (closest == LONG_MAX)
			stack_b->target = find_smallest(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	target_for_a(t_stack *stack_a, t_stack *stack_b)
{
	long	closest;
	t_stack	*current;
	t_stack	*target;

	while (stack_a)
	{
		closest = LONG_MIN;
		current = stack_b;
		while (current)
		{
			if (current->num < stack_a->num && current->num > closest)
			{
				closest = current->num;
				target = current;
			}
			current = current->next;
		}
		if (closest == LONG_MIN)
			stack_a->target = find_biggest(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}
