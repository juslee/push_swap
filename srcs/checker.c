/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:13:53 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 18:17:54 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stack.h"

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
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (EXIT_SUCCESS);
}
