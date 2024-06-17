/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:03:47 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 12:51:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rra.c
 * @brief Shift down all elements of stack a by 1.
 */

#include "operations.h"

/**
 * @brief Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 *
 * @param a stack a
 */
void	rra(t_stack *a)
{
	t_list	*second_last;
	t_list	*last;

	if (a->size < 2)
		return ;
	second_last = a->top;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}
