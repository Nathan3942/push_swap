/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:46 by njeanbou          #+#    #+#             */
/*   Updated: 2024/01/24 11:16:06 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pos_index(t_list **stack, int index)
{
	t_list	*head;
	int		pos;
	int		i;
	int		max_index;

	head = *stack;
	pos = -1;
	i = 0;
	max_index = -1;
	while (head)
	{
		if ((head->index < index) && (head->index > max_index))
		{
			pos = i;
			max_index = head->index;
		}
		i++;
		head = head->next;
	}
	if (pos == -1)
	{
		return (get_max_index(stack));
	}
	return (pos);
}

int	get_index(t_list **stack, int index)
{
	t_list	*head;
	int		pos;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		if (head->index == index)
			pos = i;
		i++;
		head = head->next;
	}
	return (pos);
}

int	get_max_index(t_list **stack)
{
	t_list	*head;
	int		index;
	int		i;
	int		pos;

	i = 0;
	index = -1;
	head = *stack;
	while (head)
	{
		if (head->index > index)
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
