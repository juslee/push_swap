/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:05:16 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 14:33:38 by welee            ###   ########.fr       */
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
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
