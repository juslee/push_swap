/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:49:42 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 16:53:03 by welee            ###   ########.fr       */
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

void	test_sa(void)
{
	t_stack		*a;
	t_list		*current;
	const int	values[] = {3, 2, 1};
	const int	expected_values[] = {2, 3, 1};
	int			i;

	a = ft_stack_new(sizeof(int), NULL);
	i = 0;
	while (i < 3)
	{
		ft_stack_push(a, &values[i]);
		i++;
	}
	printf("Stack a before sa: ");
	print_stack(a);
	sa(a);
	printf("Stack a after sa: ");
	print_stack(a);
	current = a->top;
	i = 0;
	while (i < 3)
	{
		assert(*(int *)(current->content) == expected_values[i]);
		current = current->next;
		i++;
	}
	printf("Test sa passed!\n");
	ft_stack_clear(a);
}

int	main(void)
{
	test_sa();
	printf("All tests passed for sa!\n");
	return (0);
}
