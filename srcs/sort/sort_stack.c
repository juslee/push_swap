/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:48:55 by welee             #+#    #+#             */
/*   Updated: 2024/07/30 15:03:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "parser.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else
		turk_sort(a, b);
}
