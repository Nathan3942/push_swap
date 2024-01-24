/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:39:31 by njeanbou          #+#    #+#             */
/*   Updated: 2024/01/24 11:52:42 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}						t_list;

//algo
void	ft_algo(t_list **stack_a, t_list **stack_b);

//algo_fin
void	algo_fin(t_list **stack_a, t_list **stack_b);

//tri_simple
void	tri_simple(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);

//swap
int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

//push
int		push(t_list **stack_from, t_list **stack_to);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

//rotate
int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);

//reverse_rotate
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

//check_args
void	check_args(int argc, char **argv);

//t_list
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);
void	print_lst(t_list *head);

//index
void	init_index(t_list **stack);

//utils
int		is_sort(t_list **stack);
void	free_stack(t_list **stack);
void	ft_error(char *msg);
int		get_min(t_list **stack, int val);
int		get_distance(t_list **stack, int index);

//util_algo
int		get_pos_index(t_list **stack, int index);
int		get_index(t_list **stack, int index);
int		get_max_index(t_list **stack);
int		abs(int i);

//utils_algo_fin
int		get_pos_fin(t_list **stack, int index);
int		get_min_index(t_list **stack);

#endif