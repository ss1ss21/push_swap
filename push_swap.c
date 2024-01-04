/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:03:44 by dontgu            #+#    #+#             */
/*   Updated: 2023/07/28 16:58:26 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arg_chck3(int argc, char **argv)
{
    while(--argc)
    {
            if((argv[argc][1] == '\0') &&
            ((argv[argc][0] == '+') || (argv[argc][0] == '-')))
                return (error_msg());
    }
    return(0);
}

int arg_chck2(int argc, char **argv)
{
    int i;
    
    while ((--argc) - 1)
    {
        i = argc;
        while ((--i))
        {
            if (ft_atoi(argv[argc]) == ft_atoi(argv[i]))
                return (error_msg());
        }
    }
    return (0);
}

int arg_chck(int argc, char **argv)
{
    int n;
    int i;

    if (argc <= 1)
        return(1);
    i = 0;
    while (argv[++i])
    {
        n = -1;
        if(argv[i][0] == '+' || argv[i][0] == '-')
            n++;
        while (argv[i][++n])
        {
            if (!(ft_isdigit(argv[i][n])) && argv[i][n] != '\0')
                return (error_msg());
        }
        if (((ft_atoi(argv[i]) == -1) && (n != 2)) ||
         ((ft_atoi(argv[i]) == 0) && (n != 1 && n != 2)))
            return (error_msg());
    }
    return (0);
}

void test(t_stack *info)
{
    int a;
    int b;
    
    a = info->len_a;
    b = info->len_b;
    ft_printf("a stack %d---------- \n", a);
    while(a--)
    ft_printf("%d\n",info->a[a]);
    ft_printf("b stack %d---------- \n", b);
    while(b--)
    ft_printf("%d\n",info->b[b]);
    ft_printf("\n\n");
}

int main(int argc, char **argv)
{
    if ((arg_chck(argc, argv)) || (arg_chck2(argc, argv))
        || arg_chck3(argc, argv))
            return (1);
    int count;
    t_stack *stack;
    
    count = argc - 1;
    stack = ft_calloc(1, sizeof(t_stack));
    stack->a = ft_calloc(count, sizeof(int));
    stack->b = ft_calloc(count, sizeof(int));
    stack->len_a = count;
    stack->len_b = 0;
    crat_a(argc, argv, stack);

    if(count == 1)
        return (0);
    
    ft_printf("%d\n", a_median(stack, mdn_a(stack)));
    // test(stack);
    push_b(stack);
    //  test(stack);
    
    // ft_printf("mdn%d ,median %d\n", mdn_a(stack), a_median(stack, mdn_a(stack)));
    // ft_printf("%d\n", mdn_a(stack));
    // ft_printf("ortana%d\n", a_median(stack, mdn_a(stack)));
    //  a_searcher(stack, a_median(stack, mdn_a(stack)));
    //  test(stack);
    return (0);
}
