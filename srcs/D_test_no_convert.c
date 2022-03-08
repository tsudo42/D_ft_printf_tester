/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test_no_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:47:49 by tsudo             #+#    #+#             */
/*   Updated: 2022/03/08 16:25:19 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#include "D_test.h"

void	test_no_convert(void)
{
	TEST_NC(" ");
	TEST_NC("a");
	TEST_NC("%% %%");
	TEST_NC("abcdef %% ghijklmn %% opqrstu");
}

void	test_no_convert_bonus(void)
{
	TEST_NC("%3%");
	TEST_NC("%0%");
	TEST_NC("%-%");
	TEST_NC("%.10%");
	test_no_convert();
}
