/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:17:21 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:02:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief handle error
 *
 * @param a stack a
 * @param b stack b
 * @return int  exit failure
 */
int	handle_error(t_stack *a, t_stack *b)
{
	if (a)
		ft_stack_clear(a);
	if (b)
		ft_stack_clear(b);
	ft_putstr_fd("Error\n", 2);
	return (EXIT_FAILURE);
}
