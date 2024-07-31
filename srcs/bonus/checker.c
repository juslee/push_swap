/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:13:53 by welee             #+#    #+#             */
/*   Updated: 2024/07/31 22:34:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "operations.h"
#include "stack.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

/**
 * @brief Initializes the stacks 'a' and 'b'.
 *
 * @param a The stack 'a'.
 * @param b The stack 'b'.
 * @return int 1 if successful, 0 if an error occurs.
 */
static int	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = ft_stack_new();
	*b = ft_stack_new();
	if (!*a || !*b)
		return (0);
	return (1);
}

/**
 * @brief Executes a stack operation based on the given instruction.
 *
 * @param line The instruction to execute.
 * @param a The stack 'a'.
 * @param b The stack 'b'.
 * @return int 1 if the instruction is valid and executed successfully,
 * 0 if invalid.
 */
static int	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

/**
 * @brief Process and execute instructions from standard input.
 *
 * @param a The stack 'a'.
 * @param b The stack 'b'.
 * @return int 1 if successful, 0 if an error occurs.
 */
static int	process_instructions(t_stack *a, t_stack *b)
{
	char	*line;
	int		result;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		result = execute_instruction(line, a, b);
		free(line);
		if (!result)
			return (handle_error(a, b));
		line = get_next_line(STDIN_FILENO);
	}
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
	if (!process_instructions(a, b))
		return (EXIT_FAILURE);
	if (is_sorted(a) && b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_stack_clear(a);
	ft_stack_clear(b);
	return (EXIT_SUCCESS);
}
