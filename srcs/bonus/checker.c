/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:13:53 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 19:27:56 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stack.h"
#include "get_next_line_bonus.h"

static int	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = ft_stack_new();
	*b = ft_stack_new();
	if (!*a || !*b)
		return (0);
	return (1);
}

static int	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!execute_instruction(line, a, b))
		{
			free(line);
			return (handle_error(a, b));
		}
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		parse_result;
	char	*line;

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
	if (!process_instructions(a, b))
		return (EXIT_FAILURE);
	if (is_sorted(a) && ft_stack_is_empty(b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (EXIT_SUCCESS);
}
