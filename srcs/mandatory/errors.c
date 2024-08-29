/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:31 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:32 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	perror_exit(char *msg, char **strs, int *nums)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_free(strs);
	free(nums);
	exit(1);
}

void	check_isvalid(char *s, char **strs)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		perror_exit("Error\n", strs, 0);
	if (s[i] == '-' && ft_strlen(s) == 1)
		perror_exit("Error\n", strs, 0);
	if (s[i] == '+' && ft_strlen(s) == 1)
		perror_exit("Error\n", strs, 0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			perror_exit("Error\n", strs, 0);
		i++;
	}
}

int	*check_elements(int argc, char *argv[], int start, char **strs)
{
	int		*nums;
	int		i;
	int		len;

	i = start;
	while (argv[i])
		check_isvalid(argv[i++], strs);
	nums = (int *)malloc(sizeof (int) * (argc - 1));
	if (!nums)
		perror_exit("Error\n", strs, 0);
	i = 0;
	while (argv[start])
	{
		len = ft_strlen(argv[start]);
		if (len >= 10 && ft_strcmp("2147483647", argv[start]) < 0)
			perror_exit("Error\n", strs, nums);
		if (len >= 11 && ft_strcmp("-2147483648", argv[start]) < 0)
			perror_exit("Error\n", strs, nums);
		nums[i] = ft_atoi(argv[start]);
		start++;
		i++;
	}
	return (nums);
}

int	*check_string(char *s, int *size)
{
	char	**strs;
	int		*nums;
	int		len;

	strs = ft_split(s, ' ');
	if (!strs)
		perror_exit("Error\n", 0, 0);
	len = 0;
	while (strs[len])
		len++;
	*size = len;
	nums = check_elements(len + 1, strs, 0, strs);
	ft_free(strs);
	return (nums);
}

void	check_duplicate(int *nums, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (nums[i] == nums[j])
				count++;
			j++;
		}
		if (count >= 2)
		{
			free(nums);
			perror_exit("Error\n", 0, 0);
		}
		count = 0;
		i++;
	}
}
