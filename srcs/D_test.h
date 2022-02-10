/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_test.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:54:29 by tsudo             #+#    #+#             */
/*   Updated: 2022/02/10 16:19:47 by tsudo            ###   ##########        */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_TEST_H
# define D_TEST_H

# include <limits.h>
# include "D_compare.h"

# define D_BUFFER_SIZE 42

int		ft_printf(const char *fmt, ...);

void	test_no_convert(void);
void	test_c(void);
void	test_d(void);
void	test_i(void);
void	test_u(void);

#endif