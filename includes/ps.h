/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:25:58 by sklaps            #+#    #+#             */
/*   Updated: 2025/06/25 22:25:59 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "limits.h"

typedef struct s_stack
{
	int				num;
	int				rank;
	struct s_stack	*target;
	int				cost;
	int				median;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				op_count;
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				debug;
}	t_data;

//input
void	check_input(char **av);
char	**split_args(char **av);
long	ft_atol(const char *str);

//init stack
void	init_stack(t_stack **a, char **av);
int		stacklen(t_stack **stack);
t_stack	*get_last(t_stack **stack);

//exit
void	exit_msg(char *msg);
void	free_args(char **av);
void	free_stack(t_stack **stack, int error, char *msg);
void	exit_program(t_data *data, char **av);

// stack operations
void	opmsg(t_data *data, char *msg);
// swap
void	swap_a(t_data *data, t_stack **stack, int print);
void	swap_b(t_data *data, t_stack **stack, int print);
void	swap_both(t_data *data);
// push
void	push(t_data *data, t_stack **src, t_stack **dest, char *type);
// rotate
void	rotate(t_data *data, t_stack **stack, char *type);
void	rotate_both(t_data *data);
void	reverse_rotate(t_data *data, t_stack **stack, char *type);
void	rrr(t_data *data);

//chunk sort
void	chunk_sort(t_data *data, int chunk_count);
void	push_back_to_a2(t_data *data);

//turk algo
void	turk_algo(t_data *data);
void	rotate_min_top(t_data *data, t_stack *stack);
void	get_median(t_stack *s, t_stack *node);
t_stack	*get_cheapest(t_stack *stack);
void	push_to_a_extended(t_data *data, t_stack *cheapest);
void	push_to_b_extended(t_data *data, t_stack *cheapest);
int		get_cost(t_stack *stack1, t_stack *stack2, int i1, int i2);
int		get_index(t_stack *stack, t_stack *node);
t_stack	*get_max(t_stack *head);
t_stack	*get_min(t_stack *head);

// algo
int		find_min_index(t_stack *head);
void	sort_five(t_data *data);

// print list
void	print_rank(t_stack **stack);
void	print_stack(t_stack **stack);
void	print_list_all(t_stack *stack, char type);

//sort
void	sort_three(t_data *data);

//misc
int		is_sorted(t_stack **s);
int		circle_sort(t_stack *stack);
void	algo(t_data *data);

#endif
