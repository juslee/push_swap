/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:54:58 by welee             #+#    #+#             */
/*   Updated: 2024/06/17 19:26:43 by welee            ###   ########.fr       */
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

void	test_sb(void)
{
	t_stack		*b;
	t_list		*current;
	int			values[] = {3, 2, 1};
	int			expected_values[] = {2, 3, 1};
	int			i;

	b = ft_stack_new(sizeof(int), NULL);
	i = 0;
	while (i < 3)
	{
		ft_stack_push(b, &values[i]);
		i++;
	}
	printf("Stack b before sb: ");
	print_stack(b);
	sb(b);
	printf("Stack b after sb: ");
	print_stack(b);
	current = b->top;
	i = 0;
	while (i < 3)
	{
		assert(*(int *)(current->content) == expected_values[i]);
		current = current->next;
		i++;
	}
	printf("Test sb passed!\n");
	ft_stack_clear(b);
}

int	main(void)
{
	test_sb();
	printf("All tests passed for sb!\n");
	return (0);
}
