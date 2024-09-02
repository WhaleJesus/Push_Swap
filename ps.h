/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:43 by sklaps            #+#    #+#             */
/*   Updated: 2024/09/02 14:53:47 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			papb(t_stack_node **a, t_stack_node **b, char target, bool msg);

void			rev_rotate_stack(t_stack_node **stack, char *target, bool msg);
void			rrr(t_stack_node **a, t_stack_node **b, bool msg);

void			rotate_stack(t_stack_node **stack, char *target, bool msg);
void			rr(t_stack_node **a, t_stack_node **b, bool msg);

void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

void			swap_stack(t_stack_node **stack, char *target, bool msg);
void			ss(t_stack_node **a, t_stack_node **b, bool msg);

void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

int				error_syntax(char *str_n);
int				error_dup(t_stack_node *a, int i);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			exit_program(char *msg);

void			init_a(t_stack_node **a, char **argv);
void			push_prep(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
t_stack_node	*get_cheapest(t_stack_node *stack);

void			check_input(char **argv);

int				stack_len(t_stack_node *stack);
t_stack_node	*get_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*get_min_max(t_stack_node *stack, int check);
t_stack_node	*get_max(t_stack_node *stack);

#endif
