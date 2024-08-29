/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:57 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:58 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three_elements(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = get_max_node(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

void	sort_large_elements(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		get_metadata_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three_elements(a);
	while (*b)
	{
		get_metadata_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	move_min_to_top(a);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	move_min_to_top(t_stack_node **a)
{
	while ((*a)->nb != get_min_node(*a)->nb)
	{
		if (get_min_node(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
