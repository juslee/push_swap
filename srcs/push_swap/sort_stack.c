/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:03:53 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 23:16:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "main.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	int			*sorted;
	int			size;
	int			i;
	t_stacknode	*node;

	size = a->size;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		print_error_and_exit(a, b);
	node = a->top;
	i = 0;
	while (i < size)
	{
		sorted[i] = node->value;
		node = node->next;
		i++;
	}
	ft_sort_int_tab(sorted, size);
	push_half_to_b(a, b, sorted, size);
	sort_small_stack(a, b);
	merge_stacks(a, b);
	free(sorted);
}
