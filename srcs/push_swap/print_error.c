/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:59:37 by welee             #+#    #+#             */
/*   Updated: 2024/06/20 17:22:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/**
 * @brief Print error message
 */
void	print_error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}
