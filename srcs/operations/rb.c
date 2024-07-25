/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:55:56 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 14:32:43 by welee            ###   ########.fr       */
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
	rotate(b);
	write(1, "rb\n", 3);
}
