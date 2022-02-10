/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:50 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:21:47 by tsudo            ###   ##########        */
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
	strcpy(buf1 + 5, "%d %d %d %d");
	ptr = (void *)(buf1 + 30);
	*ptr = 42;
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, 0, -1, 1, *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %d\n", ret);
}

void	test_d(void)
{
	TEST("%d", 0);
	TEST("_%d_ _%d_", -1, 1);
	TEST("_%d_ _%d_ _%d_", -10, 0, 10);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%d", INT_MAX - 10);
	TEST("%d", INT_MIN + 10);
	TEST("%d", INT_MAX - 17);
	TEST("%d", INT_MIN + 17);
	TEST("%d", INT_MAX / 10);
	TEST("%d", INT_MIN / 10);
	TEST("%d", INT_MAX / 100);
	TEST("%d", INT_MIN / 100);
	test_memory();
}
