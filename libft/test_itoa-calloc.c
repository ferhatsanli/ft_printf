/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa-calloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanli <fsanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:08:54 by fsanli            #+#    #+#             */
/*   Updated: 2024/12/18 13:09:14 by fsanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h" // Include your libft header

void test_ft_itoa()
{
    char *str = ft_itoa(12345);
    printf("ft_itoa(12345) = %s\n", str);
    free(str); // Ensure to free the allocated memory
}

void test_ft_calloc()
{
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr); // Ensure to free the allocated memory
}

int main()
{
    test_ft_itoa();
    test_ft_calloc();
    return 0;
}
