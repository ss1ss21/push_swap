/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:59:47 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/28 16:53:14 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_msg()
{
    ft_printf("Error");
    return(1);
}

void crat_a(int argc, char **argv,t_stack *a_stck)
{
    int i;

    i = 1;
    while(--argc)
    {
        a_stck->a[argc - 1] = ft_atoi(argv[i++]);
    }
}

int swap(t_stack *stack)
{
    int tmp;
    int ia;
    
    ia = stack->len_a - 1;
    tmp = stack->a[ia];
    stack->a[ia] = stack->a[ia - 1];
    stack->a[ia - 1] = tmp; 
    if (a_sequent(stack) > 0)
    {
       ft_printf("sa\n");
       return(1);   
    }
    else
    {
        tmp = stack->a[ia];
        stack->a[ia] = stack->a[ia - 1];
        stack->a[ia - 1] = tmp; 
        return (0);
    }
}

void a_searcher(t_stack *stack, int median)
{
    int ia;
    
    ia = stack->len_a - 1;

    while(stack->a[ia] >= median)
        ia--;
    if (ia > stack->len_a / 2)   
    {
        while(stack->len_a > (ia + 1))
        {
            ra(stack);
            ia++;
        }
    }    
    else
    {
        ia = 0;
        while(stack->a[ia] > median)
            ia++;
        while((ia--) + 1)
            rra(stack);
    }
    return;
}

void b_searcher(t_stack *stack)
{
    int ib;
    int mdn;
    
    mdn = b_median(stack, stack->len_b);
    ib = stack->len_b - 1; 
    while(stack->b[ib] < mdn)
        ib--;
    if (ib >= stack->len_b / 2)
    {
        while(stack->len_b - (++ib))
            rb(stack);
    }
    else if(ib < stack->len_a / 2)
    {
        while((ib--) + 1)
            rrb(stack);   
    }
    return;
}