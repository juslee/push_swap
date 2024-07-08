/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:02:35 by welee             #+#    #+#             */
/*   Updated: 2024/06/20 16:38:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "operations.h"
#include "libft.h"

#define CHUNK_SIZE 20

static int	int_cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

static void	get_sorted_array(t_stack *a, int **sorted_array)
{
	int		i;
	t_list	*current;

	*sorted_array = malloc(sizeof(int) * ft_stack_size(a));
	if (!*sorted_array)
		print_error();
	current = a->top;
	i = 0;
	while (current != NULL)
	{
		(*sorted_array)[i] = *(int *)(current->content);
		current = current->next;
		i++;
	}
	ft_quicksort((void **)*sorted_array, 0, ft_stack_size(a) - 1, int_cmp);
}

static void	push_elements_to_b(t_stack *a, t_stack *b, int chunk_limit,
								int *steps)
{
	while (!ft_stack_is_empty(a) && *(int *)(a->top->content) <= chunk_limit)
	{
		pb(a, b);
		(*steps)++;
	}
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int *steps)
{
	int	*sorted_array;
	int	chunk_limit;
	int	i;
	int	chunk_size;
	int	stack_size;

	get_sorted_array(a, &sorted_array);
	chunk_size = CHUNK_SIZE;
	stack_size = ft_stack_size(a);
	i = chunk_size - 1;
	while (i < stack_size)
	{
		chunk_limit = sorted_array[i];
		push_elements_to_b(a, b, chunk_limit, steps);
		i += chunk_size;
	}
	free(sorted_array);
}

static int	find_max_index(t_stack *b)
{
	t_list	*current;
	int		max_value;
	int		max_index;
	int		i;

	current = b->top;
	max_value = *(int *)(current->content);
	max_index = 0;
	i = 0;
	while (current != NULL)
	{
		if (*(int *)(current->content) > max_value)
		{
			max_value = *(int *)(current->content);
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

static void	push_chunks_back_to_a(t_stack *a, t_stack *b, int *steps)
{
	int	max_index;

	while (!ft_stack_is_empty(b))
	{
		max_index = find_max_index(b);
		push_min_to_top(b, max_index, steps);
		pa(a, b);
		(*steps)++;
	}
}

void	sort_large_stack(t_stack *a, int *steps)
{
	t_stack	*b;

	b = ft_stack_new(sizeof(int), NULL);
	if (!b)
		print_error();
	push_chunks_to_b(a, b, steps);
	push_chunks_back_to_a(a, b, steps);
	ft_stack_clear(b);
}
