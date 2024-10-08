/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:55:56 by welee             #+#    #+#             */
/*   Updated: 2024/09/24 10:56:51 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rb.c
 * @brief Shift up all elements of stack b by 1.
 */

#include "operations.h"

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 *
 * @param b stack b
 */
void	rb(t_stack *b)
{
	if (b->size > 1)
	{
		ft_stack_rotate(b);
		if (WRITE_FLAG)
			write(1, "rb\n", 3);
	}
}
