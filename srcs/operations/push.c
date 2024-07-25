/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:27:10 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 19:39:31 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	push(t_stack *from, t_stack *to)
{
	int	value;

	if (from->size == 0)
		return ;
	value = ft_stack_pop(from);
	ft_stack_push(to, value);
}
