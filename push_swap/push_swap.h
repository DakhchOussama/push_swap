/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:14 by odakhch           #+#    #+#             */
/*   Updated: 2022/03/28 16:01:19 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define OK 1
# define KO 0

typedef struct t_num
{
	int	*array;
	int	size;
	int	sizeadd;
}				t_num;

typedef struct t_stack
{
	t_num	stack_a;
	t_num	stack_b;
}				t_stack;

int		small_num(t_num *stack_a);
char	*arg_to_string(char *av);
char	*ft_get_line(char **av);
t_stack	create_stack(char *tab);
int		check_arg(char *av);
void	check_free(t_stack *stack, char *msg);
void	check_error(char *msg);
int		ft_check_duplicates(t_stack *stacks, int number);
void	three_number(t_num *stack);
void	push_five_number(t_stack *stack);
void	find_small_five(t_stack *stack);
void	push_ten_number(t_stack *stack);
int		check_sort(t_num *array);
void	push_one_hundred(t_stack *stack);
void	arrange_num_more_handred(t_stack *stack);
void	push_larger_one_handred(t_stack *stack);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
long	ft_atoi(const char *str);
int		count_words(const char *str, char c);
char	*word_dup(const char *str, int start, int finish);
char	**ft_split(char const *s, char c);
void	swap_num(int *a, int *b);
void	push_index(t_stack *stack, int num);
int		*push_list(t_stack *stack);
int		*get_list(t_stack *stack);
void	redu_stack_a(t_num *stack_a, int length);
void	magn_stack_a(t_num *stack_b, t_num *stack_a, int length);
void	move_top(t_stack *stack, int num);
void	rest_number(t_stack *stack, int size);
void	arrange_num(t_stack *stack);
void	sa_sb(t_num *stack, int type, char c);
void	rra_rrb(t_num *stack, int type, char c);
void	ra_rb(t_num *stack, int type, char c);
void	pb(t_num *stack_b, t_num *stack_a, int type);
void	pa(t_num *stack_b, t_num *stack_a, int type);
void	clear_first_element(int *array, int size);
void	remove_first_element(int *array, int size);
int		find_number(int *array, int size, int div, int chunks);
int		search_small(t_stack *stack, int num);
int		search_bigg(t_num *stack_b);
void	find_bigg_num(t_stack *stack);
void	find_small(t_stack *stack);
void	push_five_hundred(t_stack *stack);
void	sa_and_sb(t_stack *stack, int type);
void	rra_and_rrb(t_stack *stack, int type);
void	ra_and_rb(t_stack *stack, int type);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);
int		check_line(char *line, t_stack *stack);
void	ft_cheker(t_stack *stack);
char	*ft_strchr(const char *s, int c);
char	**split_string(char *string, t_stack *stack);

#endif
