/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:25:43 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 14:03:45 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

/**
 * @brief print stack
 *
 * @param stack stack
 * @param name name
 */
void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	current = stack->top;
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" ", 1);
	if (current)
	{
		while (current)
		{
			ft_putnbr_fd(current->value, 1);
			ft_putstr_fd(" ", 1);
			current = current->next;
			if (current == stack->top)
				break ;
		}
	}
	ft_putendl_fd("", 1);
}
