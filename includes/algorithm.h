/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:33:40 by welee             #+#    #+#             */
/*   Updated: 2024/07/04 13:49:37 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

void	ft_quicksort(int *arr, int low, int high);
void	ft_insertionsort(int *arr, int n);
void	ft_bubblesort(int *arr, int n);
void	ft_selectionsort(int *arr, int n);
void	ft_mergesort(int *arr, int l, int r);
void	ft_heapsort(int *arr, int n);
void	ft_countingsort(int *arr, int n);
void	ft_radixsort(int *arr, int n);
void	ft_shellsort(int *arr, int n);
void	ft_timsort(int *arr, int n);
#endif
