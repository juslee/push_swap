/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:16:33 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 21:54:14 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"
# include "operations.h"

// Main sorting function
void	sort_stack(t_stack *a, t_stack *b);

// Helper sorting functions
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
int		get_max_bits(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b);

#endif
