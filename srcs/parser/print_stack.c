/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:25:43 by welee             #+#    #+#             */
/*   Updated: 2024/07/29 15:55:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;
// 	int		first_pass;
// 	char	*value_str;

// 	if (!stack || !stack->top)
// 		return ;
// 	current = stack->top;
// 	first_pass = 1;
// 	while (first_pass || current != stack->top)
// 	{
// 		first_pass = 0;
// 		value_str = ft_itoa(current->value);
// 		if (value_str)
// 		{
// 			ft_putendl_fd(value_str, 1);
// 			free(value_str);
// 		}
// 		current = current->next;
// 	}
//}


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
