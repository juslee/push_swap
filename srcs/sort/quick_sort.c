/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:59:39 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 18:22:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

t_node	*partition(t_stack *a, t_stack *b, t_node *end);
void	quicksort(t_stack *a, t_stack *b, t_node *start, t_node *end);
void	reassemble(t_stack *a, t_stack *b);
void	quick_sort(t_stack *a, t_stack *b);

t_node	*partition(t_stack *a, t_stack *b, t_node *end)
{
	t_node *pivot;
	t_node *current;
	t_node *next_node;

	pivot = end;
	current = a->top;
	while (current != pivot)
	{
		next_node = current->next;
		if (current->value < pivot->value)
			pb(a, b);
		else
			ra(a);
		current = next_node;
	}
	pb(a, b); // Move pivot to b to separate from lesser elements
	return (pivot);
}

void	quicksort(t_stack *a, t_stack *b, t_node *start, t_node *end)
{
	t_node *pivot;

	printf("start: %d, end: %d\n", start->value, end->value);
	printf("end->next: %d\n", end->next->value);
	if (!start || !end || start == end || start == end->next)
		return;

	pivot = partition(a, b, end);
	// Recursively sort the two halves
	if (pivot->prev)
	{
		pivot->prev->next = NULL; // Temporarily break the circular link
		quicksort(a, b, start, pivot->prev);
		pivot->prev->next = pivot; // Re-link after sorting
	}
	if (pivot->next)
	{
		pivot->next->prev = NULL; // Temporarily break the circular link
		quicksort(a, b, pivot->next, end);
		pivot->next->prev = pivot; // Re-link after sorting
	}
}

void	reassemble(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	if (!a || !a->top || a->size < 2)
		return ;
	quicksort(a, b, a->top, a->top->prev);
	reassemble(a, b);
}
