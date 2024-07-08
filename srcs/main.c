/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:43 by welee             #+#    #+#             */
/*   Updated: 2024/06/20 17:24:40 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Entry point of the program
 */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"
#include <stdio.h>

void	validate_and_push(t_stack *stack, char *arg)
{
	long	value;

	if (!ft_isnumber(arg))
		(ft_stack_clear(stack), print_error());
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX)
		(ft_stack_clear(stack), print_error());
	if (!ft_stack_push(stack, &value))
		(ft_stack_clear(stack), print_error());
}

void	process_single_arg(t_stack *stack, char *arg)
{
	char	**args;
	int		i;
	int		count;

	args = ft_split(arg, ' ');
	if (!args)
		(ft_stack_clear(stack), print_error());
	count = 0;
	while (args[count] != NULL)
		count++;
	i = count - 1;
	while (i >= 0)
	{
		validate_and_push(stack, args[i]);
		free(args[i]);
		i--;
	}
	free(args);
}

void	process_args(t_stack *stack, int argc, char **argv)
{
	int	i;

	if (argc == 2)
		process_single_arg(stack, argv[1]);
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			validate_and_push(stack, argv[i]);
			i--;
		}
	}
	if (has_duplicates(stack))
		(ft_stack_clear(stack), print_error());
}

void	sort_stack(t_stack *stack)
{
	int	steps;

	steps = 0;
	if (!is_sorted(stack))
	{
		if (ft_stack_size(stack) <= 5)
			sort_small_stack(stack, &steps);
		else
			sort_large_stack(stack, &steps);
	}
	printf("Total steps: %d\n", steps);
	print_stack(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = ft_stack_new(sizeof(int), NULL);
	if (!stack)
		(ft_stack_clear(stack), print_error());
	process_args(stack, argc, argv);
	sort_stack(stack);
	ft_stack_clear(stack);
	return (0);
}
