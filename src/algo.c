/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:57:50 by njeanbou          #+#    #+#             */
/*   Updated: 2024/02/02 14:24:54 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rrb_for_push(t_list **stack_a, t_list **stack_b, int *pos, int *cal)
{
	if (cal[0] == 1 && cal[1] == 1)
	{
		while (pos[0] < ft_lstsize(*stack_a) && pos[1] < ft_lstsize(*stack_b))
		{
			rrr(stack_a, stack_b);
			pos[0]++;
			pos[1]++;
		}
	}
	while (pos[0] < ft_lstsize(*stack_a) && cal[0] == 1)
	{
		rra(stack_a);
		pos[0]++;
	}
	while (pos[1] < ft_lstsize(*stack_b) && cal[1] == 1)
	{
		rrb(stack_b);
		pos[1]++;
	}
}

static void	rb_for_push(t_list **stack_a, t_list **stack_b, int *pos, int *cal)
{
	if (cal[0] == -1 && cal[1] == -1)
	{
		while (pos[0] > 0 && pos[1] > 0)
		{
			rr(stack_a, stack_b);
			pos[0]--;
			pos[1]--;
		}
	}
	while (pos[0] > 0 && cal[0] == -1)
	{
		ra(stack_a);
		pos[0]--;
	}
	while (pos[1] > 0 && cal[1] == -1)
	{
		rb(stack_b);
		pos[1]--;
	}
}

static void	push_stack_b(t_list **stack_a, t_list **stack_b, int index)
{
	int	pos[2];
	int	cal[2];

	pos[0] = get_index(stack_a, index);
	pos[1] = get_pos_index(stack_b, index);
	cal[0] = nb_op(index, stack_a, 1, 'a');
	cal[1] = nb_op(index, stack_b, 1, 'b');
	rrb_for_push(stack_a, stack_b, pos, cal);
	rb_for_push(stack_a, stack_b, pos, cal);
	pb(stack_a, stack_b);
}

static void	cal_op(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		tmp[2];
	int		nbop[2];

	head = *stack_a;
	tmp[0] = head->index;
	while (head)
	{
		nbop[1] = nb_op(head->index, stack_b, 0, 'b');
		nbop[0] = nb_op(head->index, stack_a, 0, 'a');
		if (nbop[0] + nbop[1] < tmp[1] || tmp[1] == 0)
		{
			tmp[1] = nbop[0] + nbop[1];
			tmp[0] = head->index;
		}
		head = head->next;
	}
	push_stack_b(stack_a, stack_b, tmp[0]);
}

void	ft_algo(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		cal_op(stack_a, stack_b);
	}
	sort_3(stack_a);
	algo_fin(stack_a, stack_b);
}
