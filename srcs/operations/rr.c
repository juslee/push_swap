/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:02:24 by welee             #+#    #+#             */
/*   Updated: 2024/09/24 10:57:00 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rr.c
 * @brief ra and rb at the same time
 */

#include "operations.h"

/**
 * @brief ra and rb at the same time
 *
 * @param a stack a
 * @param b stack b
 */
void	rr(t_stack *a, t_stack *b)
{
	if (a->size > 1 && b->size > 1)
	{
		ft_stack_rotate(a);
		ft_stack_rotate(b);
		if (WRITE_FLAG)
			write(1, "rr\n", 3);
	}
}
