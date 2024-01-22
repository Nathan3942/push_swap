/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:14:19 by njeanbou          #+#    #+#             */
/*   Updated: 2024/01/22 19:00:59 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	nb_operation(int index, t_list **stack, char c, int cal)
{
	int	pos;
	int	nbop;
	int	op;

	nbop = 0;
	if (c == 'a')
		index++;
	pos = get_pos_index(stack, index);
	while (pos > ft_lstsize(*stack) / 2)
	{
		if (pos > (ft_lstsize(*stack) / 2))
		{
			pos--;
			op = 1;
		}
		nbop++;
	}
	while (pos > 0)
	{
		pos--;
		op = -1;
		nbop++;
	}
	if (cal == 1)
		return (op);
	return (nbop);
}

static void	push_stack_b(t_list **stack_a, t_list **stack_b, int index)
{
	int	op[2];
	int	cal[2];

	op[0] = nb_operation(index + 1, stack_a, 'a', 0);
	op[1] = nb_operation(index, stack_b, 'b', 0);
	cal[0] = nb_operation(index + 1, stack_a, 'a', 1);
	cal[1] = nb_operation(index, stack_b, 'b', 1);
	if (cal[0] == 1 && cal[1] == 1)
	{
		while (op[0] < ft_lstsize(*stack_a) && op[1] < ft_lstsize(*stack_b))
		{
			rrr(stack_a, stack_b);
			op[0]++;
			op[1]++;
		}
	}
	else if (cal[0] == -1 && cal[1] == -1)
	{
		while (op[0] > 0 && op[1] > 0)
		{
			rr(stack_a, stack_b);
			op[0]--;
			op[1]--;
		}
	}
	while (op[0] < ft_lstsize(*stack_a) && cal[0] == 1)
	{
		rra(stack_a);
		op[0]++;
	}
	while (op[1] < ft_lstsize(*stack_b) && cal[1] == 1)
	{
		rrb(stack_b);
		op[1]++;
	}
	while (op[0] > 0 && cal[0] == -1)
	{
		ra(stack_a);
		op[0]--;
	}
	while (op[1] > 0 && cal[1] == -1)
	{
		rb(stack_b);
		op[1]--;
	}
	pb(stack_a, stack_b);
	print_lst(*stack_b);
}

void	ft_algo(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		opa;
	int		opb;
	int		op[2];
	int		tmp[2];

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		head = *stack_a;
		tmp[0] = head->index;
		while (head)
		{
			opa = nb_operation(head->index, stack_a, 'a', 0);
			opb = nb_operation(head->index, stack_b, 'b', 0);
			op[0] = nb_operation(head->index, stack_a, 'a', 1);
			op[1] = nb_operation(head->index, stack_b, 'b', 1);
			if (op[0] == op[1])
				opa = abs(opa - opb);
			else
				opa = opa + opb;
			if (opa < tmp[1] || tmp[1] == 0)
			{
				tmp[1] = opa;
				tmp[0] = head->index;
			}
			head = head->next;
		}
		push_stack_b(stack_a, stack_b, tmp[0]);
	}
}
