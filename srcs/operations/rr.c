/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:02:24 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 11:02:59 by welee            ###   ########.fr       */
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
	ra(a);
	rb(b);
}
