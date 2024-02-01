/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:57:45 by njeanbou          #+#    #+#             */
/*   Updated: 2024/02/01 13:11:50 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_double(char **args, int num, int i)
{
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	char	**args;
	int		i;
	long	num;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (ft_num(args[i]) == 0 || ft_double(args, num, i + 1) == 0
			|| num < -2147483648 || num > 2147483648)
		{
			ft_error("Error");
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

void	ft_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}