/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:25:06 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/28 16:36:40 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *stack)
{
    int a_len;
    int b_len;
    
    a_len = stack->len_a;
    b_len = stack->len_b;
    if(!b_len)
        return;
    stack->a[a_len] = stack->b[b_len - 1];
    stack->b[b_len - 1] = '\0';
    stack->len_b--;
    stack->len_a++;
    ft_printf("pa\n");
}

void pb(t_stack *stack)
{
    int a_len;
    int b_len;
    
    a_len = stack->len_a;
    b_len = stack->len_b;
    if(!a_len)
        return;
    stack->b[b_len] = stack->a[a_len - 1];
    stack->a[a_len - 1] = '\0';
    stack->len_a--;
    stack->len_b++;
    ft_printf("pb\n");
}

void sa(t_stack *stack)
{
    int a_len;
    int tmp;
    
    a_len = stack->len_a;
    if(a_len == 1)
        return;
    tmp = stack->a[a_len - 1];
    stack->a[a_len - 1] = stack->a[a_len -2];
    stack->a[a_len - 2] = tmp;
    ft_printf("sa\n");
}

void r_searcher(t_stack *stack, int median)
{
    int i;
    
    i = 0;
    while(stack->a[i] > median)
        i++;
    while(i + 1)
    {
        rra(stack);
        i--;
    }
}