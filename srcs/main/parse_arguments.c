/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:12:25 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 20:28:38 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <limits.h>

void	parse_arguments(t_stack *a, int argc, char **argv)
{
	int	num;
	int	i;
	int	*arr;

	arr = malloc((argc - 1) * sizeof(int));
	if (!arr)
		print_error_and_exit(a, NULL);
	i = argc - 1;
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]) || ft_strlen(argv[i]) > 11)
			print_error_and_exit(a, NULL);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN
			|| is_duplicate(arr, argc - 1 - i, num))
			print_error_and_exit(a, NULL);
		arr[argc - 1 - i] = num;
		ft_stack_push(a, num);
		i--;
	}
	free(arr);
}
