/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sawp_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:44 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:45 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack_node	**s)
{
	if (!*s || !(*s)->next)
		return ;
	*s = (*s)->next;
	(*s)->prev->prev = *s;
	(*s)->prev->next = (*s)->next;
	if ((*s)->next)
		(*s)->next->prev = (*s)->prev;
	(*s)->next = (*s)->prev;
	(*s)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
