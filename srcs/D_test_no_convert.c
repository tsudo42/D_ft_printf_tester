/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_no_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:47:49 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/08 15:36:22 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "D_test.h"

static void	test_memory(void)
{
	int			ret;
	char		buf1[D_BUFFER_SIZE];
	char		buf2[D_BUFFER_SIZE];
	const char	*str = "abcdef %% ghijklmn %% opqrstu";

	memset(buf1, 'A', D_BUFFER_SIZE);
	strcpy(buf1 + 10, str);
	memcpy(buf2, buf1, D_BUFFER_SIZE);
	TEST_NC(buf1);
	ret = memcmp(buf1, buf2, D_BUFFER_SIZE);
	printf("\nmemcmp : %d\n", ret);
}

void	test_no_convert(void)
{
	TEST_NC(" ");
	TEST_NC("a");
	TEST_NC("%% %%");
	TEST_NC("abcdef %% ghijklmn %% opqrstu");
	test_memory();
}

void	test_no_convert_bonus(void)
{
	test_no_convert();
	test_memory();
}
