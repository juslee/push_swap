/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:54:56 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 14:32:28 by welee            ###   ########.fr       */
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
	rotate(a);
	write(1, "ra\n", 3);
}
