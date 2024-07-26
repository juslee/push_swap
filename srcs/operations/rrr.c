/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:06:57 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 20:06:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rrr.c
 * @brief rra and rrb at the same time
 */

#include "operations.h"

/**
 * @brief rra and rrb at the same time
 *
 * @param a stack a
 * @param b stack b
 */
void	rrr(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		ft_stack_reverse_rotate(a);
		ft_stack_reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}
