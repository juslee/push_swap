/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:25 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 19:36:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_stacknode
{
	int					value;
	struct s_stacknode	*next;
	struct s_stacknode	*prev;
}	t_stacknode;

typedef struct s_stack
{
	t_stacknode	*top;
	t_stacknode	*bottom;
	int			size;
}	t_stack;

t_stack		*ft_stack_new(void);
void		ft_stack_clear(t_stack *stack);
void		ft_stack_push(t_stack *stack, int value);
int			ft_stack_pop(t_stack *stack);
int			ft_stack_size(t_stack *stack);
int			ft_stack_top(t_stack *stack);

#endif
