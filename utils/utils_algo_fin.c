/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_fin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:09 by njeanbou          #+#    #+#             */
/*   Updated: 2024/02/01 12:32:16 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pos_fin(t_list **stack, int index)
{
	t_list	*head;
	int		pos;
	int		i;
	int		min_index;

	head = *stack;
	pos = -1;
	i = 0;
	min_index = 2147483647;
	while (head)
	{
		if ((head->index > index) && (head->index > min_index))
		{
			pos = i;
			min_index = head->index;
		}
		i++;
		head = head->next;
	}
	if (pos == -1)
	{
		return (get_min_index(stack, 'p'));
	}
	return (pos);
}

int	get_min_index(t_list **stack, char c)
{
	t_list	*head;
	int		index;
	int		i;
	int		pos;

	i = 0;
	index = 2147483647;
	head = *stack;
	while (head)
	{
		if (head->index < index)
		{
			index = head->index;
			pos = i;
		}
		head = head->next;
		i++;
	}
	if (c == 'i')
		return (index);
	return (pos);
}

int	abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}
