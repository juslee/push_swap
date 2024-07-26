/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:02:31 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 19:38:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stack.h"
# include "utils.h"

int		parse_args(t_stack *a, int argc, char **argv);
int		has_duplicates(t_stack *a);
int		is_sorted(t_stack *a);
void	handle_error(void);

#endif
