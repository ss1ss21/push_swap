/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:37:07 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/27 23:59:38 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int mdn_a(t_stack *stack)
{
    int ia;
    int i;
    
    ia = 0;
    while(stack->len_a - ia - 1)
    {
            i = ia + 1;
        while (stack->a[i])
        {
            if(stack->a[ia] < stack->a[i])
                return(stack->len_a - ia);
                i++;
        }
    ia++;
    }
    return (1);
}
