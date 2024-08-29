/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:50:27 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/09 09:50:57 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"
# include <limits.h>

/* Boolean Datatype */
# define TRUE 1
# define FALSE 0

/* Error management */
int				*check_string(char *s, int *size);
void			perror_exit(char *msg, char **strs, int *nums);
int				*check_elements(int argc, char *argv[], int start, char **strs);
void			ft_free(char **strs);
void			check_duplicate(int *nums, int size);
int				ft_strcmp(const char *s1, const char *s2);

/* Stack Data Structue */
typedef struct s_stack_node
{
	int					nb;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* Stack Utils */
void			push(t_stack_node **stack, int data);
void			free_stack(t_stack_node **a);
int				stack_len(t_stack_node *stack);
int				stack_sorted(t_stack_node *stack);
t_stack_node	*get_max_node(t_stack_node *stack);
t_stack_node	*get_min_node(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);
void			init_stack(t_stack_node **a, int *nums, int size);

/* Sorting */
void			sort_three_elements(t_stack_node **a);
void			sort_large_elements(t_stack_node **a, t_stack_node **b);

/* Sorting Utils */
void			current_index(t_stack_node *stack);
void			get_metadata_a(t_stack_node *a, t_stack_node *b);
void			get_metadata_b(t_stack_node *a, t_stack_node *b);
void			prep_for_push(t_stack_node **stack, t_stack_node *top,
					char stack_name);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			move_min_to_top(t_stack_node **a);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);

/* moves */
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

/* Instructions for checker */
void			swap(t_stack_node	**s);
void			rotate(t_stack_node **s);
void			rev_rotate(t_stack_node **s);
void			push_move(t_stack_node **dst, t_stack_node **src);
#endif
