/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:31:58 by welee             #+#    #+#             */
/*   Updated: 2024/07/26 19:36:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
long	ft_atol(const char *str);
int		ft_isnumber(const char *str);

#endif
