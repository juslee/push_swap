/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 22:31:54 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sort.h"
#include "stack.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_stack_new();
	b = ft_stack_new();
	if (!a || !b)
	{
		handle_error();
		return (EXIT_FAILURE);
	}
	if (!parse_args(a, argc, argv) || has_duplicates(a))
	{
		handle_error();
		ft_stack_clear(a);
		ft_stack_clear(b);
		return (EXIT_FAILURE);
	}
	if (!is_sorted(a))
		sort_stack(a, b);
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (EXIT_SUCCESS);
}
