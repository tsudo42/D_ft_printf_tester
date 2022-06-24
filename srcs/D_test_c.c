/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:45:36 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:21:51 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "D_test.h"

static void	test_memory(void)
{
	int		ret;
	char	buf1[D_BUFFER_SIZE];
	char	buf2[D_BUFFER_SIZE];
	char	*ptr;

	memset(buf1, UCHAR_MAX, D_BUFFER_SIZE);
	strcpy(buf1 + 5, "%c %c %c %c");
	ptr = (void *)(buf1 + 30);
	*ptr = 'D';
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST((char *)buf1 + 5, 'A', 'B', 'C', *ptr);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %d\n", ret);
}

void	test_c(void)
{
	TEST("%c", 'a');
	TEST("%c", '0');
	TEST("%c", 0);
	TEST("%c", -1);
	TEST("%c", -10);
	TEST("%c", 0xFF);
	TEST("%c", 'A');
	TEST("%c %c %c %c", 'A', 'B', 'C', 'D');
	TEST("%c%c%c", 'a', 'b', 'c');
	test_memory();
}

void	test_c_bonus(void)
{
}
