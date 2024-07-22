/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:43 by sklaps            #+#    #+#             */
/*   Updated: 2024/07/22 16:44:25 by sklaps           ###   ########.fr       */
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
	struct s_stack_node *target_node;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
}	t_stack_node;

char			**split(char *s, char c);
void			init_stack_a(t_stack_node **a, char **argv);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *a);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			free_stack(t_stack_node **stack);
void			swap_top(t_stack_node *stack);
void			push_to_top(t_stack_node *stack);
void			push_to_bottom(t_stack_node *stack);
void			ra(t_stack_node **a, bool check);
void			rb(t_stack_node **b, bool check);
void			sa(t_stack_node **a, bool check);
void			rra(t_stack_node **a, bool check);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

#endif
