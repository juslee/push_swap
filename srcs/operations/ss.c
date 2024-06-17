/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:50:24 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 10:51:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ss.c
 * @brief sa and sb at the same time
 */

#include "operations.h"

/**
 * @brief sa and sb at the same time
 *
 * @param a stack a
 * @param b stack b
 */
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
