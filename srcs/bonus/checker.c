/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:22 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:49:23 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_empty(t_stack_node *s)
{
	return (s == NULL);
}

void	free_mem(t_stack_node **a, t_stack_node **b, char *instruction)
{
	free(instruction);
	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	free_stack(a);
	free_stack(b);
}

int	instruction_executed(t_stack_node **a, t_stack_node **b, char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		(swap(a), swap(b));
	else if (ft_strcmp(instruction, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		(rotate(a), rotate(b));
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rev_rotate(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rev_rotate(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		(rev_rotate(a), rev_rotate(b));
	else if (ft_strcmp(instruction, "pa\n") == 0)
		push_move(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		push_move(b, a);
	else
		return (free_mem(a, b, instruction), 0);
	return (1);
}

void	check_instructions(t_stack_node **a, t_stack_node **b)
{
	char	*instruction;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		if (!instruction_executed(a, b, instruction))
			exit(1);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(*a) && is_empty(*b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

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
		check_instructions(&a, &b);
	(free_stack(&a), free_stack(&b));
	return (0);
}
