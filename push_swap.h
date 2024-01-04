/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssonmez <ssonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:21:27 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/28 11:09:48 by ssonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "utils/libft/libft.h"
#include "utils/ft_printf/printf.h"

typedef struct s_stack
{
    int *a;
    int *b;
    int len_a;
    int len_b;
    int push;
    
}   t_stack;

int     error_msg();
void    crat_a(int argc, char **argv,t_stack *a_stck);
void    pa(t_stack *stack);
void    pb(t_stack *stack);
void    sa(t_stack *stack);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
int     a_median(t_stack *stack, int len);
int     b_median(t_stack *stack, int len);
int     a_sequent(t_stack *stack);
int     b_sequent(t_stack *stack);
void    a_searcher(t_stack *stack, int median);
void    b_searcher(t_stack *stack);
void    push_b(t_stack *stack);
void    push_a(t_stack *stack);
int     *copy(int *dst, t_stack *stack, int len, int check);
void    test(t_stack *info);
int     swap(t_stack *stack);
void    r_searcher(t_stack *stack,int median);
int     mdn_a(t_stack *stack);

#endif
