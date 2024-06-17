/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:06:57 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 11:07:15 by welee            ###   ########.fr       */
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
	rra(a);
	rrb(b);
}
