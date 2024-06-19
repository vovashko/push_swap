/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 16:34:17 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 16:40:00 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error_handler(&stack_a);
	init_stack_a(&stack_a, argc, argv);
	size = stack_size(stack_a);
	if (!stack_sorted(stack_a))
	{
		if (size <= 3)
			sort_small_stack(&stack_a);
		else
			sort_big_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
