/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 19:39:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sort.h"
#include "stack.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		parse_result;

	if (argc < 2)
		return (0);
	a = ft_stack_new();
	b = ft_stack_new();
	if (!a || !b)
		return (handle_error(a, b));
	if (argc == 2)
		parse_result = parse_single_arg(a, argv[1]);
	else
		parse_result = parse_args(a, argc - 1, argv + 1);
	if (!parse_result || has_duplicates(a))
		return (handle_error(a, b));
	if (!is_sorted(a))
		sort_stack(a, b);
	print_stack(a);
	printf("------\n");
	print_stack(b);
	if (is_sorted(a) && b->size == 0)
		printf("OK\n");
	else
		printf("KO\n");
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (EXIT_SUCCESS);
}
