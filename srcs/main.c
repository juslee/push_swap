/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:43 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 12:53:22 by welee            ###   ########.fr       */
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

/**
 * @brief Print error message
 */
void	print_error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

void	sort_stack(t_stack *a)
{
	t_stack	*b;

	b = ft_stack_new(sizeof(int), NULL);
	if (!b)
		print_error();
	while (!ft_stack_is_empty(a))
		pb(a, b);
	while (!ft_stack_is_empty(b))
		pa(a, b);
	ft_stack_clear(b);
}

/**
 * @brief Sort stacks
 *
 * @param argc number of arguments
 * @param argv array of arguments
 * @return int return 0 if success
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	long	value;

	if (argc < 2)
		return (0);
	a = ft_stack_new(sizeof(int), NULL);
	if (a == NULL)
		print_error();
	while (--argc > 0)
	{
		if (!ft_isnumber(argv[argc]))
			print_error();
		value = ft_atol(argv[argc]);
		if (value < INT_MIN || value > INT_MAX)
			print_error();
		if (!ft_stack_push(a, &value))
			print_error();
	}
	if (has_duplicates(a))
		print_error();
	if (!is_sorted(a))
		sort_stack(a);
	ft_stack_clear(a);
	return (0);
}
