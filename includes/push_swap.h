/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:03:26 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 22:34:55 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"
# include "operations.h"

void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_small_stack(t_stack *a, t_stack *b);
void	push_half_to_b(t_stack *a, t_stack *b, int *sorted, int size);
void	merge_stacks(t_stack *a, t_stack *b);
void	push_all_except_three(t_stack *a, t_stack *b);

#endif
