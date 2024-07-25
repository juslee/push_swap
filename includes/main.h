/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:02:31 by welee             #+#    #+#             */
/*   Updated: 2024/07/22 20:17:01 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "stack.h"

void	print_error_and_exit(t_stack *a, t_stack *b);
int		is_duplicate(int *arr, int size, int num);
void	parse_arguments(t_stack *a, int argc, char **argv);

void	ft_sort_int_tab(int *tab, int size);

#endif
