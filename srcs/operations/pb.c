/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:53:26 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 14:31:58 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pb.c
 * @brief Take the first element at the top of a and put it at the top of b.
 */

#include "operations.h"

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 *
 * @param a stack a
 * @param b stack b
 */
void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
