/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:46:24 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 14:30:37 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sa.c
 * @brief swap the first 2 elements at the top of stack a
 */

#include "operations.h"

/**
 * @brief swap the first 2 elements at the top of stack a
 * Do nothing if there is only one or no elements.
 *
 * @param a stack a
 */
void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}
