/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:46 by njeanbou          #+#    #+#             */
/*   Updated: 2024/01/22 18:05:56 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pos_index(t_list **stack, int index)
{
	t_list	*head;
	int		pos;
	int		i;
	int		ind;

	pos = -1;
	while (index > 0)
	{
		index--;
		i = 0;
		head = *stack;
		while (head)
		{
			if (head->index == index)
				pos = i;
			i++;
			head = head->next;
		}
	}
	if (pos == -1)
	{
		head = *stack;
		ind = head->index;
		i = 0;
		while (head)
		{
			if (head->index > ind)
			{
				ind = head->index;
				pos = i;
			}
			i++;
			head = head->next;
		}
	}
	return (pos);
}

int	abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}
