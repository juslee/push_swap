/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:51:43 by welee             #+#    #+#             */
/*   Updated: 2024/06/20 17:28:43 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	execute_operations(t_stack *a, char *op, int *steps)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(a);
	else if (ft_strcmp(op, "ra") == 0)
		ra(a);
	else if (ft_strcmp(op, "rra") == 0)
		rra(a);
	(*steps)++;
}

void	sort_2_elements(t_stack *a, int *steps)
{
	int	first;
	int	second;

	first = *(int *)(a->top->content);
	second = *(int *)(a->top->next->content);
	if (first > second)
		execute_operations(a, "sa", steps);
}

void	sort_3_elements(t_stack *a, int *steps)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(a->top->content);
	second = *(int *)(a->top->next->content);
	third = *(int *)(a->top->next->next->content);

	if (first > second && second < third && first < third)
		execute_operations(a, "sa", steps);
	else if (first > second && second > third)
	{
		execute_operations(a, "sa", steps);
		execute_operations(a, "rra", steps);
	}
	else if (first > second && second < third && first > third)
		execute_operations(a, "ra", steps);
	else if (first < second && second > third && first < third)
	{
		execute_operations(a, "sa", steps);
		execute_operations(a, "ra", steps);
	}
	else if (first < second && second > third && first > third)
		execute_operations(a, "rra", steps);
}

void	push_min_to_top(t_stack *a, int min_index, int *steps)
{
	if (min_index <= a->size / 2)
	{
		while (min_index--)
			execute_operations(a, "ra", steps);
	}
	else
	{
		min_index = a->size - min_index;
		while (min_index--)
			execute_operations(a, "rra", steps);
	}
}

void	push_min_to_b(t_stack *a, t_stack *b, int *steps)
{
	int		min_index;
	int		min_value;
	int		i;
	t_list	*current;

	current = a->top;
	min_value = *(int *)(current->content);
	min_index = 0;
	i = 0;
	while (current)
	{
		if (*(int *)(current->content) < min_value)
		{
			min_value = *(int *)(current->content);
			min_index = i;
		}
		current = current->next;
		i++;
	}
	push_min_to_top(a, min_index, steps);
	pb(a, b);
	(*steps)++;
}

void	sort_5_elements(t_stack *a, t_stack *b, int *steps)
{
	while (ft_stack_size(a) > 3)
		push_min_to_b(a, b, steps);
	sort_3_elements(a, steps);
	while (!ft_stack_is_empty(b))
	{
		pa(a, b);
		(*steps)++;
	}
}

void	sort_small_stack(t_stack *a, int *steps)
{
	t_stack	*b;
	int		size;

	size = ft_stack_size(a);
	b = ft_stack_new(sizeof(int), NULL);
	if (!b)
		(ft_stack_clear(a), ft_stack_clear(b), print_error());
	if (size == 2)
		sort_2_elements(a, steps);
	else if (size <= 3)
		sort_3_elements(a, steps);
	else if (size <= 5)
		sort_5_elements(a, b, steps);
	ft_stack_clear(b);
}
