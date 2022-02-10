/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:50 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:21:42 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "D_test.h"

static void	test_memory(void)
{
	int		ret;
	char	buf1[D_BUFFER_SIZE];
	char	buf2[D_BUFFER_SIZE];
	int		*ptr;

	memset(buf1, UCHAR_MAX, D_BUFFER_SIZE);
	strcpy(buf1 + 5, "%i %i %i %i");
	ptr = (void *)(buf1 + 30);
	*ptr = 42;
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, 0, -1, 1, *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %i\n", ret);
}

void	test_i(void)
{
	TEST("%i", 0);
	TEST("_%i_ _%i_", -1, 1);
	TEST("_%i_ _%i_ _%i_", -10, 0, 10);
	TEST("%i", INT_MAX);
	TEST("%i", INT_MIN);
	TEST("%i", INT_MAX - 10);
	TEST("%i", INT_MIN + 10);
	TEST("%i", INT_MAX - 17);
	TEST("%i", INT_MIN + 17);
	TEST("%i", INT_MAX / 10);
	TEST("%i", INT_MIN / 10);
	TEST("%i", INT_MAX / 100);
	TEST("%i", INT_MIN / 100);
	test_memory();
}
