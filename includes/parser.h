/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:02:31 by welee             #+#    #+#             */
/*   Updated: 2024/07/29 13:51:22 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stack.h"
# include "libft.h"

int		parse_args(t_stack *a, int argc, char **argv);
int		parse_single_arg(t_stack *a, const char *arg);
int		has_duplicates(t_stack *a);
int		is_sorted(t_stack *a);
int		handle_error(t_stack *a, t_stack *b);
//void	print_stack(t_stack *stack);
void	print_stack(t_stack *stack, char *name);

#endif
