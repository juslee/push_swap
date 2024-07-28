/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:25:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/27 22:06:32 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;
	int		first_pass;
	char	*value_str;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	first_pass = 1;
	while (first_pass || current != stack->top)
	{
		first_pass = 0;
		value_str = ft_itoa(current->value);
		if (value_str)
		{
			ft_putendl_fd(value_str, 1);
			free(value_str);
		}
		current = current->next;
	}
}
