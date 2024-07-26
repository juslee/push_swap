/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:03:47 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 20:06:34 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rra.c
 * @brief Shift down all elements of stack a by 1.
 */

#include "operations.h"

/**
 * @brief Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 *
 * @param a stack a
 */
void	rra(t_stack *a)
{
	if (a->size > 1)
	{
		ft_stack_reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}
