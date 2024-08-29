/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:37 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:38 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int				*nums;
	int				size;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	size = argc - 1;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		nums = check_string(argv[1], &size);
	else
		nums = check_elements(argc, argv, 1, NULL);
	(check_duplicate(nums, size), init_stack(&a, nums, size));
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three_elements(&a);
		else
			sort_large_elements(&a, &b);
	}
	return (free_stack(&a), 0);
}
