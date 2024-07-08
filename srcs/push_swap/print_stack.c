/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:07:40 by welee             #+#    #+#             */
/*   Updated: 2024/06/20 11:23:52 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
}
