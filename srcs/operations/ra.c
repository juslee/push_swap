/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:54:56 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 11:01:02 by welee            ###   ########.fr       */
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
	t_list	*first;
	t_list	*last;

	if (a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while (last->next)
		last = last->next;
	a->top = first->next;
	first->next = NULL;
	last->next = first;
}
