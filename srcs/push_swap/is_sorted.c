/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:37:27 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 12:38:09 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file is_sorted.c
 * @brief Check if a stack is sorted
 */

#include "libft.h"

/**
 * @brief Check if a stack is sorted
 *
 * @param stack stack to check
 * @return int return 1 if the stack is sorted, 0 otherwise
 */
int	is_sorted(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}
