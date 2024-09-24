/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:54:56 by welee             #+#    #+#             */
/*   Updated: 2024/09/24 10:56:44 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ra.c
 * @brief Shift up all elements of stack a by 1.
 */

#include "operations.h"

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param a stack a
 */
void	ra(t_stack *a)
{
	if (a->size > 1)
	{
		ft_stack_rotate(a);
		if (WRITE_FLAG)
			write(1, "ra\n", 3);
	}
}
