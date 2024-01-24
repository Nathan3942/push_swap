/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_fin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:09 by njeanbou          #+#    #+#             */
/*   Updated: 2024/01/24 14:47:11 by njeanbou         ###   ########.fr       */
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
	min_index = INT32_MAX;
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
		return (get_min_index(stack));
	}
	return (pos);
}

int	get_min_index(t_list **stack)
{
	t_list	*head;
	int		index;
	int		i;
	int		pos;

	i = 0;
	index = INT32_MAX;
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
	return (pos);
}

int	abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}
