/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:58:52 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 16:59:58 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "libft.h"
#include "operations.h"

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->top;
	while (current)
	{
		printf("%d ", *(int *)(current->content));
		current = current->next;
	}
	printf("\n");
}

void	test_ss(void)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*current;
	int		values_a[] = {3, 2, 1};
	int		values_b[] = {6, 5, 4};
	int		expected_values_a[] = {2, 3, 1};
	int		expected_values_b[] = {5, 6, 4};
	int		i;

	a = ft_stack_new(sizeof(int), NULL);
	b = ft_stack_new(sizeof(int), NULL);
	i = 0;
	while (i < 3)
	{
		ft_stack_push(a, &values_a[i]);
		ft_stack_push(b, &values_b[i]);
		i++;
	}

	printf("Stack a before ss: ");
	print_stack(a);
	printf("Stack b before ss: ");
	print_stack(b);

	ss(a, b);

	printf("Stack a after ss: ");
	print_stack(a);
	printf("Stack b after ss: ");
	print_stack(b);

	current = a->top;
	i = 0;
	while (i < 3)
	{
		assert(*(int *)(current->content) == expected_values_a[i]);
		current = current->next;
		i++;
	}

	current = b->top;
	i = 0;
	while (i < 3)
	{
		assert(*(int *)(current->content) == expected_values_b[i]);
		current = current->next;
		i++;
	}

	printf("Test ss passed!\n");
	ft_stack_clear(a);
	ft_stack_clear(b);
}

int	main(void)
{
	test_ss();
	printf("All tests passed for ss!\n");
	return (0);
}
