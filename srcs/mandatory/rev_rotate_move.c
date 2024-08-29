/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:39 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:40 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate(t_stack_node **s)
{
	t_stack_node	*last_node;

	if (!*s || !(*s)->next)
		return ;
	last_node = get_last_node(*s);
	last_node->prev->next = NULL;
	last_node->next = *s;
	last_node->prev = NULL;
	*s = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
