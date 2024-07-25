/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/23 14:15:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Entry point of the program
 */

#include "main.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_stack_new();
	b = ft_stack_new();
	if (!a || !b)
		return (handle_error(a, b));
	if (parse_arguments(a, argc, argv) || handle_error(a, b))
		return (1);
	if (has_duplicate(a) || handle_error(a, b))
		return (1);
	if (is_sorted(a))
	{
		ft_stack_clear(a);
		ft_stack_clear(b);
		return (0);
	}
	sort_stack(a, b);
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (0);
}
