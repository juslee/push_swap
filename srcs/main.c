/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 22:05:34 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sort.h"
#include "stack.h"
#include "libft.h"

static int	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = ft_stack_new();
	*b = ft_stack_new();
	if (!*a || !*b)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		parse_result;

	if (argc < 2)
		return (0);
	if (!initialize_stacks(&a, &b))
		return (handle_error(a, b));
	if (argc == 2)
		parse_result = parse_single_arg(a, argv[1]);
	else
		parse_result = parse_args(a, argc - 1, argv + 1);
	if (!parse_result || has_duplicates(a))
		return (handle_error(a, b));
	if (!is_sorted(a))
		sort_stack(a, b);
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (EXIT_SUCCESS);
}
