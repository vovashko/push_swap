/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 15:12:28 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 11:45:12 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_small_stack(t_stack **stack_a)
{
	t_stack	*biggest;
	t_stack	*smallest;

	biggest = find_biggest(*stack_a);
	smallest = find_smallest(*stack_a);
	if (biggest == *stack_a && (*stack_a)->next == smallest)
		ra(stack_a);
	else if ((*stack_a)->next == biggest && smallest == (*stack_a)->next->next)
		rra(stack_a);
	else if ((*stack_a)->next == biggest && smallest == (*stack_a)->next->prev)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (biggest == *stack_a && smallest == (*stack_a)->next->next)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next == smallest && (*stack_a)->next->next == biggest)
		sa(stack_a);
}

static void	smallest_on_top(t_stack **stack_a)
{
	t_stack	*smallest;

	smallest = find_smallest(*stack_a);
	while ((*stack_a)->num != smallest->num)
	{
		if (smallest->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

static void	set_target(t_stack *stack_a, t_stack *stack_b, char name)
{
	current_index(stack_a);
	current_index(stack_b);
	if (name == 'a')
		target_for_a(stack_a, stack_b);
	else
		target_for_b(stack_a, stack_b);
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	if (size_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (size_a-- > 3 && !stack_sorted(*stack_a))
	{
		set_target(*stack_a, *stack_b, 'a');
		find_cost(*stack_a, *stack_b);
		find_cheapest(*stack_a);
		push_cheapest_to_b(stack_a, stack_b);
	}
	sort_small_stack(stack_a);
	while (*stack_b)
	{
		set_target(*stack_a, *stack_b, 'b');
		push_back_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	smallest_on_top(stack_a);
}
