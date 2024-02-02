/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:50:01 by njeanbou          #+#    #+#             */
/*   Updated: 2024/02/02 14:25:12 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_list **stack_a, int argc, char **argv)
{
	char	**args;
	t_list	*head;
	int		i;

	head = *stack_a;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i++;
	}
	while (args[i])
	{
		head = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, head);
		i++;
	}
	init_index(stack_a);
	if (argc == 2)
		ft_free(args);
}

static void	ft_tri(t_list **stack_a, t_list **stack_b)
{
	if (!is_sort(stack_a))
	{
		if (ft_lstsize(*stack_a) <= 5)
			tri_simple(stack_a, stack_b);
		else
			ft_algo(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	ft_tri(stack_a, stack_b);
	if (is_sort(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	return (0);
}
