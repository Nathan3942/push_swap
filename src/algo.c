/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:57:50 by njeanbou          #+#    #+#             */
/*   Updated: 2024/01/24 11:29:04 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	cal_op(int index, t_list **stack, int op, char c)
{
	int	pos;
	int	nbop;
	int	cal;

	nbop = 0;
	if (c == 'a')
		pos = get_index(stack, index);
	else
		pos = get_pos_index(stack, index);
	while (pos >= 0 && pos < ft_lstsize(*stack))
	{
		if (pos > (ft_lstsize(*stack) / 2))
		{
			pos++;
			cal = 1;
		}
		else
		{
			pos--;
			cal = -1;
		}
		nbop++;
	}
	if (op == 1)
		return (cal);
	return (nbop);
}

static void	push_stack_b(t_list **stack_a, t_list **stack_b, int index)
{
	int	pos[2];
	int	cal[2];

	printf("%d\n", index);
	pos[0] = get_index(stack_a, index);
	pos[1] = get_pos_index(stack_b, index);
	cal[0] = cal_op(index, stack_a, 1, 'a');
	cal[1] = cal_op(index, stack_b, 1, 'b');
	printf("%d ", pos[0]);
	printf("%d\n", pos[1]);
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
	pb(stack_a, stack_b);
	print_lst(*stack_a);
	print_lst(*stack_b);
}


void	ft_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		nbopa;
	int		nbopb;
	int		tmp[2];
	int		cal[2];

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		head = *stack_a;
		tmp[0] = head->index;
		while (head)
		{
			nbopb = cal_op(head->index, stack_b, 0, 'b');
			nbopa = cal_op((head->index), stack_a, 0, 'a');
			cal[0] = cal_op((head->index), stack_a, 1, 'a');
			cal[1] = cal_op(head->index, stack_b, 1, 'b');
			if (cal[0] == cal[1])
				nbopa = abs(nbopa - nbopb);
			else
			nbopa = nbopa + nbopb;
			if (nbopa < tmp[1] || tmp[1] == 0)
			{
				tmp[1] = nbopa;
				tmp[0] = head->index;
			}
			head = head->next;
		}
		push_stack_b(stack_a, stack_b, tmp[0]);
	}
	sort_3(stack_a);
	print_lst(*stack_a);
	print_lst(*stack_b);
	algo_fin(stack_a, stack_b);
}
