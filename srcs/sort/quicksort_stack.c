/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:16:49 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 19:45:34 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"
#include <stdio.h>

static int	*stack_to_array(t_stack *stack)
{
	int		*array;
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		array[i++] = current->value;
		current = current->next;
	}
	return (array);
}

static int	find_median(t_stack *stack)
{
	int	*values;
	int	median;

	if (!stack || stack->size == 0)
		return (INT_MIN);
	values = stack_to_array(stack);
	if (!values)
		return (INT_MIN);
	ft_quicksort(values, 0, stack->size - 1);
	median = values[stack->size / 2];
	free(values);
	return (median);
}

static void	partition_stack(t_stack *a, t_stack *b, int median)
{
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (a->top->value < median)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

// Recursive function to sort stack 'a' using a Quicksort-like approach
void	quicksort_stack(t_stack *a, t_stack *b)
{
	int	median;

	if (a->size <= 1)
		return ;
	median = find_median(a);
	if (median == INT_MIN)
		return ;
	partition_stack(a, b, median);
	quicksort_stack(a, b);
	while (b->size > 0)
		pa(a, b);
	quicksort_stack(a, b);
}
