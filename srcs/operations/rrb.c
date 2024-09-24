/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:16 by welee             #+#    #+#             */
/*   Updated: 2024/09/24 10:57:23 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rrb.c
 * @brief Shift down all elements of stack b by 1.
 */

#include "operations.h"

/**
 * @brief Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 *
 * @param b stack b
 */
void	rrb(t_stack *b)
{
	if (b->size > 1)
	{
		ft_stack_reverse_rotate(b);
		if (WRITE_FLAG)
			write(1, "rrb\n", 4);
	}
}
