/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:50:40 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/28 16:53:49 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int a_sequent(t_stack *stack)
{
    int a_len;
    int i;
    int b_len;

    b_len = stack->len_b;    
    a_len = stack->len_a;
    if(a_len <= 1)
        return(1);
    while(--a_len)
    {
        i = a_len - 1;
        while(i + 1)
        {
            if(stack->a[a_len] > stack->a[i--])
                return(0);
        }
    }
    if(!b_len)
        return (2);
    a_len = stack->len_a - 1;
    while(b_len--)
    {
        if(stack->a[a_len] < stack->b[b_len])
            return (0);
    }
    return(1);
}

int b_sequent(t_stack *stack)
{
    int b_len;
    int i;

    b_len = stack->len_b;
    if(b_len <= 1)
        return(0);
    while(--b_len)
    {
        i = b_len - 1;
        while(i + 1)
        {
            if(stack->b[b_len] < stack->b[i--])
                return(0);
        }
    }
    return(1);
}

void push_b(t_stack *stack)
{
    int i;
    int mdn;
    int push;
   
    while ((a_sequent(stack) < 1))
    {
        mdn = a_median(stack, mdn_a(stack));
        push = mdn_a(stack) / 2;
        
            ft_printf("push: %d ve median: %d\n", push, mdn);
        swap(stack);
        if(push == 0)
            return;
        
        while((push) && ((a_sequent(stack) < 1)))
        {
            ft_printf("push: %d ve median: %d\n", push, mdn);
            i = stack->len_a - 1;
            if(swap(stack))
            {   
                test(stack);
            }
            else if (stack->a[i] < mdn)
            {   
                ft_printf("pa için mdn %d\n\n", mdn);
                pb(stack);
                push--;
                test(stack);
            }
            else
            {   
                a_searcher(stack, mdn);
                test(stack);    
            }
        }
    }
        if(stack->a[0] < stack->a[1])
            rra(stack);
}

void push_a(t_stack *stack)
{
    int i;
    int mdn;
    int push;
    int mod;
    
    push = stack->len_b / 2;
    i = stack->len_b - 1;
    while ((stack->len_b != 1))
    {
        mod = stack->len_b % 2;
        mdn = b_median(stack, stack->len_b);
        while(--push + mod)
        {
            if(swap(stack));
            else if (stack->b[i] > mdn)
                {
                    pa(stack);
                }
            else
                b_searcher(stack);
        }       
    }
    pa(stack);
}

int *copy(int *dst, t_stack *stack, int len, int check)
{
    int	i;

	i = 0;
    if(check == 0)
    {
	    while (stack->len_a > i)
	    {
	    	dst[i] = stack->b[i];
	    	i++;
	    }
    }
    else
    {
        i = len - 1; 
        while (len--)
	    {
	    	dst[i] = stack->a[i];
	    	i--;
	    }
    }
	return (dst);
}
