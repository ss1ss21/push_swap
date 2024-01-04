/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:45:06 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/28 15:53:51 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *stack)
{
    int tmp;
    int a_len;
    
    a_len = stack->len_a - 1;
    tmp = stack->a[a_len];
    while(a_len)
    {
        stack->a[a_len] = stack->a[a_len - 1];
        a_len--;
    }
        stack->a[0] = tmp;
    ft_printf("ra\n");
}

void rb(t_stack *stack)
{
    int tmp;
    int b_len;
    
    if(stack->len_b <= 1)
        return;
    b_len = stack->len_b;
    tmp = stack->b[b_len - 1];
    while(--b_len)
        stack->b[b_len] = stack->b[b_len - 1];
    stack->b[0] = tmp;
    ft_printf("rb\n");
}

void rra(t_stack *stack)
{
    int i;
    int tmp;
    int a_len;
    
    i = -1;
    if(stack->len_a <= 1)
        return;
    a_len = stack->len_a;
    tmp = stack->a[0];
    while(a_len - (i++ + 1))
        stack->a[i] = stack->a[i + 1];
    stack->a[a_len - 1] = tmp;
    ft_printf("rra\n");
}

void rrb(t_stack *stack)
{
    int i;
    int tmp;
    int b_len;

    i = -1;
    if(stack->len_b <= 1)
        return;
    b_len = stack->len_b;
    tmp = stack->b[0];
    while(b_len - (++i + 1))
        stack->b[i] = stack->b[i + 1];
    stack->b[b_len - 1] = tmp;
    ft_printf("rrb\n");
}

int a_median(t_stack *stack, int len)
{
    int *stc;
    int i;
    int tmp;
    int median;
    
    if(len <= 1)
        return(stack->a[stack->len_a - 1]);
    stc = ft_calloc(len, sizeof(int));
    stc = copy(stc, stack, mdn_a(stack), 1);    
    median = len / 2;
    tmp = 0;
    
    while(--len)
    {
        i = len - 1;
        while(i + 1)
        {
            if(stc[len] < stc[i])
            {
                tmp = stc[len];
                stc[len] = stc[i];
                stc[i] = tmp;
            }
            i--;
        }
    }
    tmp = stc[median];
    free(stc);
    return(tmp);
}

int b_median(t_stack *stack, int len)
{
    int *stc;
    int i;
    int tmp;
    int median;
    
    stc = ft_calloc(len, sizeof(int));
    stc = copy(stc, stack, stack->len_b, 0);
    median = len / 2;
    tmp = 0;
    while(--len)
    {
        i = len - 1;
        while(i + 1)
        {
            if(stc[len] < stc[i])
            {
                tmp = stc[len];
                stc[len] = stc[i];
                stc[i] = tmp;
            }
            i--;
        }
    }
    tmp = stc[median];
    free(stc);
    return(tmp);
}

