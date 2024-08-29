/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:47 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:48 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = TRUE;
		else
			stack->above_median = FALSE;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node		*target_node;
	t_stack_node		*tmp_b;
	long				closest_smaller;

	while (a)
	{
		closest_smaller = LONG_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->nb < a->nb && tmp_b->nb > closest_smaller)
			{
				closest_smaller = tmp_b->nb;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target_node = get_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	set_cheapset(t_stack_node *stack)
{
	long				cheapest_val;
	t_stack_node		*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = TRUE;
}

void	get_metadata_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapset(a);
}
