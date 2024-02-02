/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:46 by njeanbou          #+#    #+#             */
/*   Updated: 2024/02/02 14:19:49 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_pos(int index, t_list **stack, char c)
{
	int	pos;

	if (c == 'a')
		pos = get_index(stack, index);
	else
		pos = get_pos_index(stack, index);
	return (pos);
}

int	nb_op(int index, t_list **stack, int op, char c)
{
	int	pos;
	int	nbop;
	int	cal;

	nbop = 0;
	pos = get_pos(index, stack, c);
	if (pos > ft_lstsize(*stack) / 2)
	{
		nbop = ft_lstsize(*stack) - pos;
		cal = 1;
	}
	else
	{
		nbop = pos;
		cal = -1;
	}
	if (op == 1)
		return (cal);
	return (nbop);
}

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
		return (get_max_index(stack, 0));
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

int	get_max_index(t_list **stack, int ind)
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
	if (ind == 1)
		return (index);
	return (pos);
}
