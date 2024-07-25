/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:11:03 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 20:11:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_error_and_exit(t_stack *a, t_stack *b)
{
	if (a)
		ft_stack_clear(a);
	if (b)
		ft_stack_clear(b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
