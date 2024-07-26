/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:25 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:00:53 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Stack functions
t_stack	*ft_stack_new(void);
void	ft_stack_push(t_stack *stack, int value);
int		ft_stack_pop(t_stack *stack);
void	ft_stack_rotate(t_stack *stack);
void	ft_stack_reverse_rotate(t_stack *stack);
void	ft_stack_clear(t_stack *stack);
void	ft_stack_swap(t_stack *stack);

#endif
