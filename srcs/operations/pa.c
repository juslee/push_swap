/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:51:31 by welee             #+#    #+#             */
/*   Updated: 2024/09/24 11:12:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pa.c
 * @brief Take the first element at the top of b and put it at the top of a.
 */

#include "operations.h"

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 *
 * @param a stack a
 * @param b stack b
 */
void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		ft_stack_push(a, ft_stack_pop(b));
		if (WRITE_FLAG)
			write(1, "pa\n", 3);
	}
}
