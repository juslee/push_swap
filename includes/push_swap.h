/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:03:26 by welee             #+#    #+#             */
/*   Updated: 2024/06/20 15:19:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	sort_2_elements(t_stack *a, int *steps);
void	sort_3_elements(t_stack *a, int *steps);
void	sort_5_elements(t_stack *a, t_stack *b, int *steps);
void	sort_small_stack(t_stack *a, int *steps);
void	sort_large_stack(t_stack *a, int *steps);
void	execute_operations(t_stack *a, char *op, int *steps);
void	push_min_to_top(t_stack *a, int min_index, int *steps);
void	print_stack(t_stack *stack);
void	print_error(void);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
#endif
