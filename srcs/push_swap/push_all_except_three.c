/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_except_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:26 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 23:25:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push_all_except_three(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		write(1, "testing\n", 8);
		pb(a, b);
	}
}
