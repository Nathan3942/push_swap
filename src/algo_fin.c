/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:28:14 by njeanbou          #+#    #+#             */
/*   Updated: 2024/02/02 14:25:00 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	tri_stack_b(t_list **stack_b)
{
	int	pos;

	pos = get_max_index(stack_b, 0);
	while (pos > 0 && pos < ft_lstsize(*stack_b))
	{
		if (pos > (ft_lstsize(*stack_b) / 2))
		{
			rrb(stack_b);
			pos++;
		}
		else
		{
			rb(stack_b);
			pos--;
		}
	}
}

static void	push_b_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		i;

	i = 0;
	while (ft_lstsize(*stack_b) > 0)
	{
		head_a = *stack_a;
		head_b = *stack_b;
		if (i == 0 && (head_a->index == 0
				|| (head_a->index == get_min_index(stack_a, 'i')
					&& head_b->index > get_max_index(stack_a, 1))))
		{
			pa(stack_a, stack_b);
			i++;
		}
		else if (head_b->index == head_a->index - 1)
		{
			pa(stack_a, stack_b);
			i++;
		}
		else
			rra(stack_a);
	}
}

static void	put_first_index(t_list **stack_a)
{
	int	pos;

	pos = get_min_index(stack_a, 'p');
	while (pos > 0 && pos < ft_lstsize(*stack_a))
	{
		if (pos > (ft_lstsize(*stack_a)))
		{
			pos++;
			rra(stack_a);
		}
		else
		{
			pos--;
			ra(stack_a);
		}
	}
}

void	algo_fin(t_list **stack_a, t_list **stack_b)
{
	tri_stack_b(stack_b);
	push_b_to_a(stack_a, stack_b);
	put_first_index(stack_a);
}
