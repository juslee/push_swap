/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:31:00 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:13:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/**
 * @brief do rr
 *
 * @param a a
 * @param b b
 * @param cost cost
 */
static void	do_rr(t_stack *a, t_stack *b, t_cost *cost)
{
	while (cost->ra > 0 && cost->rb > 0)
	{
		rr(a, b);
		cost->ra--;
		cost->rb--;
	}
}

/**
 * @brief do rrr
 *
 * @param a a
 * @param b b
 * @param cost cost
 */
static void	do_rrr(t_stack *a, t_stack *b, t_cost *cost)
{
	while (cost->rra > 0 && cost->rrb > 0)
	{
		rrr(a, b);
		cost->rra--;
		cost->rrb--;
	}
}

/**
 * @brief rotate stacks
 *
 * @param a a
 * @param b b
 * @param cost cost
 */
static void	rotate_stacks(t_stack *a, t_stack *b, t_cost *cost)
{
	while (cost->ra > 0)
	{
		ra(a);
		cost->ra--;
	}
	while (cost->rra > 0)
	{
		rra(a);
		cost->rra--;
	}
	while (cost->rb > 0)
	{
		rb(b);
		cost->rb--;
	}
	while (cost->rrb > 0)
	{
		rrb(b);
		cost->rrb--;
	}
}

/**
 * @brief move element from a to b
 *
 * @param a a
 * @param b b
 * @param cost cost
 */
void	move_element(t_stack *a, t_stack *b, t_cost cost)
{
	t_cost	move;

	move = determine_operation(cost);
	do_rr(a, b, &move);
	do_rrr(a, b, &move);
	rotate_stacks(a, b, &move);
	pb(a, b);
}
