/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:12:25 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:03:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

/**
 * @brief parse arguments
 *
 * @param a stack a
 * @param argc number of arguments
 * @param argv arguments
 * @return int 1 if success, 0 otherwise
 */
int	parse_args(t_stack *a, int argc, char **argv)
{
	int		i;
	long	num;

	i = argc - 1;
	while (i >= 0)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		ft_stack_push(a, (int)num);
		i--;
	}
	return (1);
}
