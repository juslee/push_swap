/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:33:24 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:10:44 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

/**
 * @brief reset cost
 *
 * @param ra ra
 * @param rb rb
 * @param rra rra
 * @param rrb rrb
 * @return t_cost cost
 */
static t_cost	reset_cost(int ra, int rb, int rra, int rrb)
{
	t_cost	cost;

	cost.ra = ra;
	cost.rb = rb;
	cost.rra = rra;
	cost.rrb = rrb;
	return (cost);
}

/**
 * @brief determine operation
 *
 * @param cost cost
 * @return t_cost cost
 */
t_cost	determine_operation(t_cost cost)
{
	int	total_ra_rb;
	int	total_rra_rrb;
	int	total_ra_rrb;
	int	total_rra_rb;
	int	total;

	total_ra_rb = ft_max(cost.ra, cost.rb);
	total_rra_rrb = ft_max(cost.rra, cost.rrb);
	total_ra_rrb = cost.ra + cost.rrb;
	total_rra_rb = cost.rra + cost.rb;
	total = ft_min(
			ft_min(total_ra_rb, total_rra_rrb),
			ft_min(total_ra_rrb, total_rra_rb));
	if (total_ra_rb <= total)
		return (reset_cost(cost.ra, cost.rb, 0, 0));
	else if (total_rra_rrb <= total)
		return (reset_cost(0, 0, cost.rra, cost.rrb));
	else if (total_ra_rrb <= total)
		return (reset_cost(cost.ra, 0, 0, cost.rrb));
	else if (total_rra_rb <= total)
		return (reset_cost(0, cost.rb, cost.rra, 0));
	return (reset_cost(0, 0, 0, 0));
}
