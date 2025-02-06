/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:48:09 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/30 02:16:11 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H
# define SIGN_MASK(value) ((value) >> (sizeof(int) * 8 - 1))
# define ABS(value) ((value) + SIGN_MASK(value) ^ SIGN_MASK(value))

#endif

// Bitwise Right Shift:

// -5 in binary (32-bit) is 11111111111111111111111111111011.
// Right shift by 31 positions: 11111111111111111111111111111111 (which is -1).
// Addition:

// -5 + (-1) = -6.
// Bitwise XOR:

// -6 in binary (32-bit) is 11111111111111111111111111111010.
// XOR with -1 (which is 11111111111111111111111111111111):
// 11111111111111111111111111111010
// XOR
// 11111111111111111111111111111111
// Result: 00000000000000000000000000000101 (which is 5).