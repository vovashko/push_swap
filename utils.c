/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vshkonda <vshkonda@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 16:35:31 by vshkonda      #+#    #+#                 */
/*   Updated: 2024/01/30 16:32:53 by vshkonda      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

static int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	add_to_stack(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!stack)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handler(stack);
	new->num = num;
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

static long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	init_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	while (i < ft_split_len(argv))
	{
		if (!arg_is_num(argv[i]))
			error_handler(stack_a);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_handler(stack_a);
		if (error_duplicate(*stack_a, num))
			error_handler(stack_a);
		add_to_stack(stack_a, num);
		i++;
	}
	if (argc == 2)
		free_split(argv);
}
