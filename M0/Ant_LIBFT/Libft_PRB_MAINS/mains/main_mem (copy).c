/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:51:36 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/20 13:25:50 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#define SIGN_OK(e,g) (((e) == 0 && (g) == 0) || ((e) < 0 && (g) < 0) || ((e) > 0 && (g) > 0))



int	main (void)
{
	// {
    //     const unsigned char a[] = {0x7F, 0xFF};
    //     const unsigned char b[] = {0x7F, 0x7E};
    //     int exp = memcmp(a, b, 2);
    //     int got = ft_memcmp(a, b, 2);
    //     if (SIGN_OK(exp, got)) printf("OK\n");
    //     else printf("diff: expected=%d | got=%d", exp, got);
    // }

	// {
    //     const char *s = "abcdefgh";
    //     const char *exp = "cde";
    //     char *got = ft_substr(s, 2, 3);
    //     if (got && strcmp(exp, got) == 0) free_and_ok(got, NULL);
    //     else
	// 	{
	// 		printf("diff: expected='%s' | got='%s'", exp, got);
    // 		if (got) free(got);
    // 		printf("FAIL");
			
	// 	} 
    // }

	{
		
		char *str = "01234";
 	size_t size = 20;
 	char *ret = ft_substr(str, 400, size);
 
 	if (!strncmp(ret, "", 1))
 	{
 		printf("TEST_SUCCESS");
 	}
	else
 		printf("TEST_FAILED");
 	free(ret);
	}
	// {
	// 	int exp = memcmp("t\200", "t\0", 2);
	// 	printf("diff: expected=%d | got=%d\n", exp, ft_memcmp("t\200", "t\0", 2));
	// }
}
