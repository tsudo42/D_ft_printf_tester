/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:50 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:27:32 by tsudo            ###   ##########        */
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
	strcpy(buf1 + 5, "%x %x %x %x");
	ptr = (void *)(buf1 + 30);
	*ptr = 42;
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, 0, -1, 1, *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %x\n", ret);
}

static void	test_uppercase(void)
{
	TEST("%X", 0);
	TEST("_%X_ _%X_", 30, 1);
	TEST("_%X_ _%X_ _%X_", 305010, 2147483648U, 10);
	TEST("%X", UINT_MAX);
	TEST("%X", 0);
	TEST("%X", UINT_MAX - 10);
	TEST("%X", 0 + 10);
	TEST("%X", UINT_MAX - 17);
	TEST("%X", 0 + 17);
	TEST("%X", UINT_MAX / 10);
	TEST("%X", UINT_MAX / 100);
}

static void	test_lowercase(void)
{
	TEST("%x", 0);
	TEST("_%x_ _%x_", 30, 1);
	TEST("_%x_ _%x_ _%x_", 305010, 2147483648U, 10);
	TEST("%x", UINT_MAX);
	TEST("%x", 0);
	TEST("%x", UINT_MAX - 10);
	TEST("%x", 0 + 10);
	TEST("%x", UINT_MAX - 17);
	TEST("%x", 0 + 17);
	TEST("%x", UINT_MAX / 10);
	TEST("%x", UINT_MAX / 100);
}

void	test_x(void)
{
	test_uppercase();
	test_lowercase();
	test_memory();
}
