/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_insertion_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:47:29 by welee             #+#    #+#             */
/*   Updated: 2024/07/28 18:53:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <stdio.h>

int	find_bottom_position(t_stack *stack, int min, int max);
int	find_top_position(t_stack *stack, int min, int max);
int	has_elements_in_range(t_stack *stack, int min, int max);
void	move_to_top(t_stack *stack, int pos);
void	move_chunk_to_b(t_stack *a, t_stack *b, int min, int max);
void	move_back_to_a(t_stack *a, t_stack *b);
void	chunked_insertion_sort(t_stack *a, t_stack *b, int chunk_size);

int	find_bottom_position(t_stack *stack, int min, int max)
{
	t_node *current;
	int pos;

	current = stack->top->prev;
	pos = stack->size - 1;
	while (pos >= 0)
	{
		if (current->value >= min && current->value <= max)
			return (pos);
		current = current->prev;
		pos--;
	}
	return (-1);
}

int	find_top_position(t_stack *stack, int min, int max)
{
	t_node *current;
	int pos;

	current = stack->top;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->value >= min && current->value <= max)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

int	has_elements_in_range(t_stack *stack, int min, int max)
{
	t_node *current;
	int count;

	current = stack->top;
	count = stack->size;
	while (count-- > 0)
	{
		if (current->value >= min && current->value <= max)
			return (1);
		current = current->next;
	}
	return (0);
}

void	move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = stack->size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

void	move_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int pos_top;
	int pos_bottom;

	printf("min: %d, max: %d\n", min, max);
	while (has_elements_in_range(a, min, max))
	{
		pos_top = find_top_position(a, min, max);
		pos_bottom = find_bottom_position(a, min, max);
		if (pos_top <= a->size - pos_bottom)
			move_to_top(a, pos_top);
		else
			move_to_top(a, pos_bottom);
		pb(a, b); // Move the element from a to b
	}
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

void	chunked_insertion_sort(t_stack *a, t_stack *b, int chunk_size)
{
	int total_chunks;
	int min;
	int max;
	int i;

	total_chunks = (a->size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < total_chunks)
	{
		min = i * chunk_size;
		max = (i + 1) * chunk_size - 1;
		move_chunk_to_b(a, b, min, max);
		i++;
	}
	move_back_to_a(a, b);
}
