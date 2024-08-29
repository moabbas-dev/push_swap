/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:50:03 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:50:04 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	len1;
	int	len2;

	if ((*s1 == '-' && *s2 != '-') || (*s1 != '-' && *s2 == '-'))
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > len1)
		return (-1);
	else if (len2 < len1)
		return (1);
	else
		return (ft_strncmp(s1, s2, len1));
}

t_stack_node	*get_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
