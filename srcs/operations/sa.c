/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:46:24 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 10:57:58 by welee            ###   ########.fr       */
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
	t_list	*first;
	t_list	*second;

	if (a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}
