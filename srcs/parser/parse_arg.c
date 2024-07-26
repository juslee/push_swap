/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:12:25 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 19:41:43 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_int(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	parse_args(t_stack *a, int argc, char **argv)
{
	int		i;
	long	num;

	i = argc - 1;
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]) || !is_int(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		ft_stack_push(a, (int)num);
		i--;
	}
	return (1);
}
