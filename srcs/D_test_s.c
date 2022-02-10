/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:28:49 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:37:59 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "D_test.h"

static void	test_memory(void)
{
	int		ret;
	char	buf1[D_BUFFER_SIZE];
	char	buf2[D_BUFFER_SIZE];
	char	**ptr;

	memset(buf1, UCHAR_MAX, D_BUFFER_SIZE);
	strcpy(buf1 + 5, "%s %s %s %s");
	ptr = (void *)(buf1 + 30);
	*ptr = "string";
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, "a", "bcd", "01,\\%%2345", *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %x\n", ret);
}

void	test_s(void)
{
	TEST("%s", "");
	TEST("_%s_ _%s_", "a", "b");
	TEST("_%s_ _%s_ _%s_", "AB", "BC", "CA");
	TEST("%s", "01234567890123456789012345678901\
		2345678901234567890123456789012345678901\
		234567890123456789");
	test_memory();
}
