/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:50 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:37:37 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "D_test.h"

static void	test_memory(void)
{
	int					ret;
	char				buf1[D_BUFFER_SIZE];
	char				buf2[D_BUFFER_SIZE];
	unsigned int		*ptr;

	memset(buf1, UCHAR_MAX, D_BUFFER_SIZE);
	strcpy(buf1 + 5, "%p %p %p %p");
	ptr = (void *)(buf1 + 30);
	*ptr = 42;
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, (void *)0, (void *) -1, (void *)1, *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %x\n", ret);
}

void	test_p(void)
{
	TEST("%p", (void *)0);
	TEST("_%p_ _%p_", (void *)30, (void *)1);
	TEST("_%p_ _%p_ _%p_", (void *)305010, (void *)2147483648U, (void *)10);
	TEST("%p", (void *)UINT_MAX);
	TEST("%p", (void *)0);
	TEST("%p", (void *)(UINT_MAX - 10));
	TEST("%p", (void *)(0 + 10));
	TEST("%p", (void *)(UINT_MAX - 17));
	TEST("%p", (void *)(0 + 17));
	TEST("%p", (void *)(UINT_MAX / 10));
	TEST("%p", (void *)(UINT_MAX / 100));
	test_memory();
}
