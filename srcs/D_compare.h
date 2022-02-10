/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_compare.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:35:26 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:11:21 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_COMPARE_H
# define D_COMPARE_H

# include <errno.h>
# include <stdio.h>
# include <string.h>


# ifdef ORIGINAL_ONLY
# define TEST(fmt, ...) { \
	printf("\n(\"%s\") : ", fmt); \
	errno = 0; \
	int ret_original = printf(fmt, __VA_ARGS__); \
	int err_original = errno; \
	printf("\nreturn value : %d", ret_original); \
	printf("\nerror : %s\n", strerror(err_original)); \
}
# else
#  ifdef FT_ONLY
# define TEST(fmt, ...) { \
	printf("\n(\"%s\") : ", fmt); \
	fflush(stdout); \
	errno = 0; \
	int ret_ft = ft_printf(fmt, __VA_ARGS__); \
	int err_ft = errno; \
	printf("\nreturn value : %d", ret_ft); \
	printf("\nerror : %s\n", strerror(err_ft)); \
}
#  else
# define TEST(fmt, ...) { \
	printf("\ntesting (\"%s\")\n", fmt); \
	printf("original printf: "); \
	errno = 0; \
	int ret_original = printf(fmt, __VA_ARGS__); \
	int err_original = errno; \
	printf("\nft_printf      : "); \
	fflush(stdout); \
	errno = 0; \
	int ret_ft = ft_printf(fmt, __VA_ARGS__); \
	int err_ft = errno; \
	printf("\noriginal  return value : %d", ret_original); \
	printf("\nft_printf return value   : %d\n", ret_ft); \
	printf("\noriginal  error : %s\n", strerror(err_original)); \
	printf("\nft_printf error : %s\n", strerror(err_ft)); \
}
#  endif
# endif

# define TEST_WITH_VAL(fmt, val) TEST(fmt ", " #val, val)

# ifdef ORIGINAL_ONLY
# define TEST_NC(fmt) { \
	printf("\n(\"%s\") : ", fmt); \
	errno = 0; \
	int ret_original = printf(fmt); \
	int err_original = errno; \
	printf("\nreturn value : %d", ret_original); \
	printf("\nerror : %s\n", strerror(err_original)); \
}
# else
#  ifdef FT_ONLY
# define TEST_NC(fmt) { \
	printf("\n(\"%s\") : ", fmt); \
	errno = 0; \
	fflush(stdout); \
	int ret_ft = ft_printf(fmt); \
	int err_ft = errno; \
	printf("\nreturn value : %d", ret_ft); \
	printf("\nerror : %s\n", strerror(err_ft)); \
}
#  else
# define TEST_NC(fmt) { \
	printf("\ntesting (\"%s\")\n", fmt); \
	printf("original printf: "); \
	errno = 0; \
	int ret_original = printf(fmt); \
	int err_original = errno; \
	printf("\nft_printf      : "); \
	fflush(stdout); \
	errno = 0; \
	int ret_ft = ft_printf(fmt); \
	int err_ft = errno; \
	printf("\noriginal  return value : %d", ret_original); \
	printf("\nft_printf return value   : %d\n", ret_ft); \
	printf("\noriginal  error : %s\n", strerror(err_original)); \
	printf("\nft_printf error : %s\n", strerror(err_ft)); \
}
#  endif
# endif

#endif