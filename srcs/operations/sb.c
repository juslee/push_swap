/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:48:57 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 14:30:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sb.c
 * @brief swap the first 2 elements at the top of stack b
 */

#include "operations.h"

/**
 * @brief swap the first 2 elements at the top of stack b
 * Do nothing if there is only one or no elements.
 *
 * @param b stack b
 */
void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}
