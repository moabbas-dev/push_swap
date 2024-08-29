/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:54 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:55 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_target_node_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node		*target_node;
	t_stack_node		*tmp_a;
	long				closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->nb > b->nb && tmp_a->nb < closest_bigger)
			{
				closest_bigger = tmp_a->nb;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target_node = get_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	get_metadata_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_node_b(a, b);
}

void	free_stack(t_stack_node **a)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		next = current->next;
		current->nb = 0;
		free(current);
		current = next;
	}
	*a = NULL;
}

void	init_stack(t_stack_node **a, int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push(a, nums[i]);
		i++;
	}
	free(nums);
}
