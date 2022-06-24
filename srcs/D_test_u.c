/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:59:50 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:21:28 by tsudo            ###   ##########        */
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
	strcpy(buf1 + 5, "%u %u %u %u");
	ptr = (void *)(buf1 + 30);
	*ptr = 42;
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, 0, -1, 1, *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %u\n", ret);
}

void	test_u(void)
{
	TEST("%u", 0);
	TEST("_%u_ _%u_", 30, 1);
	TEST("_%u_ _%u_ _%u_", 305010, 2147483648U, 10);
	TEST("%u", UINT_MAX);
	TEST("%u", 0);
	TEST("%u", UINT_MAX - 10);
	TEST("%u", 0 + 10);
	TEST("%u", UINT_MAX - 17);
	TEST("%u", 0 + 17);
	TEST("%u", UINT_MAX / 10);
	TEST("%u", UINT_MAX / 100);
	test_memory();
}

void	test_u_bonus(void)
{
}
