/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:25:43 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:03:39 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief free split
 *
 * @param split split
 */
static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * @brief parse single argument
 *
 * @param a stack a
 * @param arg argument
 * @return int 1 if success, 0 otherwise
 */
int	parse_single_arg(t_stack *a, const char *arg)
{
	char	**numbers;
	int		result;
	int		argc;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	argc = 0;
	while (numbers[argc])
		argc++;
	result = parse_args(a, argc, numbers);
	free_split(numbers);
	return (result);
}
