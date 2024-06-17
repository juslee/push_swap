/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:35:27 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 12:36:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file has_duplicates.c
 * @brief Check if a stack has duplicates
 */

#include "libft.h"

/**
 * @brief Check if a stack has duplicates
 *
 * @param stack stack to check
 * @return int return 1 if the stack has duplicates, 0 otherwise
 */
int	has_duplicates(t_stack *stack)
{
	t_list	*current;
	t_list	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (*(int *)(current->content) == *(int *)(check->content))
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
