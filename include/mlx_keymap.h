/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keymap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:02:58 by susami            #+#    #+#             */
/*   Updated: 2022/08/27 22:20:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYMAP_H
# define MLX_KEYMAP_H

# if defined(LINUX) || defined(ARM)
// import from keysymdef.h
#  define MK_BACKSPACE		0xff08  /* Back space, back char */
#  define MK_TAB			0xff09
#  define MK_RETURN			0xff0d  /* Return, enter */
#  define MK_ESCAPE			0xff1b
#  define MK_DELETE			0xffff  /* Delete, rubout */
#  define MK_SHIFT_L		0xffe1  /* Left shift */
#  define MK_SHIFT_R		0xffe2  /* Right shift */
#  define MK_CONTROL_L		0xffe3  /* Left control */
#  define MK_CONTROL_R		0xffe4  /* Right control */
#  define MK_CAPS_LOCK		0xffe5  /* Caps lock */
#  define MK_COMMAND_L		0xffe7  /* Left meta */
#  define MK_COMMAND_R		0xffe8  /* Right meta */
#  define MK_OPTION			0xff7e  /* Alias for mode_switch */
#  define MK_BRACKETLEFT	0x005b  /* U+005B LEFT SQUARE BRACKET */
#  define MK_BACKSLASH		0x005c  /* U+005C REVERSE SOLIDUS */
#  define MK_BRACKETRIGHT	0x005d  /* U+005D RIGHT SQUARE BRACKET */
#  define MK_LEFT			0xff51  /* Move left, left arrow */
#  define MK_UP				0xff52  /* Move up, up arrow */
#  define MK_RIGHT			0xff53  /* Move right, right arrow */
#  define MK_DOWN			0xff54  /* Move down, down arrow */
#  define MK_F1				0xffbe
#  define MK_F2				0xffbf
#  define MK_F3				0xffc0
#  define MK_F4				0xffc1
#  define MK_F5				0xffc2
#  define MK_F6				0xffc3
#  define MK_F7				0xffc4
#  define MK_F8				0xffc5
#  define MK_F9				0xffc6
#  define MK_F10			0xffc7
#  define MK_F11			0xffc8
#  define MK_F12			0xffc9
#  define MK_A				0x0061  /* U+0061 LATIN SMALL LETTER A */
#  define MK_B				0x0062  /* U+0062 LATIN SMALL LETTER B */
#  define MK_C				0x0063  /* U+0063 LATIN SMALL LETTER C */
#  define MK_D				0x0064  /* U+0064 LATIN SMALL LETTER D */
#  define MK_E				0x0065  /* U+0065 LATIN SMALL LETTER E */
#  define MK_F				0x0066  /* U+0066 LATIN SMALL LETTER F */
#  define MK_G				0x0067  /* U+0067 LATIN SMALL LETTER G */
#  define MK_H				0x0068  /* U+0068 LATIN SMALL LETTER H */
#  define MK_I				0x0069  /* U+0069 LATIN SMALL LETTER I */
#  define MK_J				0x006a  /* U+006A LATIN SMALL LETTER J */
#  define MK_K				0x006b  /* U+006B LATIN SMALL LETTER K */
#  define MK_L				0x006c  /* U+006C LATIN SMALL LETTER L */
#  define MK_M				0x006d  /* U+006D LATIN SMALL LETTER M */
#  define MK_N				0x006e  /* U+006E LATIN SMALL LETTER N */
#  define MK_O				0x006f  /* U+006F LATIN SMALL LETTER O */
#  define MK_P				0x0070  /* U+0070 LATIN SMALL LETTER P */
#  define MK_Q				0x0071  /* U+0071 LATIN SMALL LETTER Q */
#  define MK_R				0x0072  /* U+0072 LATIN SMALL LETTER R */
#  define MK_S				0x0073  /* U+0073 LATIN SMALL LETTER S */
#  define MK_T				0x0074  /* U+0074 LATIN SMALL LETTER T */
#  define MK_U				0x0075  /* U+0075 LATIN SMALL LETTER U */
#  define MK_V				0x0076  /* U+0076 LATIN SMALL LETTER V */
#  define MK_W				0x0077  /* U+0077 LATIN SMALL LETTER W */
#  define MK_X				0x0078  /* U+0078 LATIN SMALL LETTER X */
#  define MK_Y				0x0079  /* U+0079 LATIN SMALL LETTER Y */
#  define MK_Z				0x007a  /* U+007A LATIN SMALL LETTER Z */

# else

// # if defined(OSX)
#  define MK_BACKSPACE		0x0033
#  define MK_TAB			0x0030
#  define MK_RETURN			0x0024
#  define MK_ESCAPE			0x0035
#  define MK_DELETE			0x0075

#  define MK_SHIFT_L		0x0101
#  define MK_SHIFT_R		0x0102
#  define MK_CONTROL_L		0x0100
#  define MK_CONTROL_R		0x010d
#  define MK_CAPSLOCK		0x0110
#  define MK_COMMAND_L		0x0103
#  define MK_COMMAND_R		0x0104
#  define MK_OPTION_LEFT	0x0105

#  define MK_BRACKETLEFT	0x0021
#  define MK_BACKSLASH		0x002a
#  define MK_BRACKETRIGHT	0x001e

#  define MK_LEFT			0x007b
#  define MK_UP				0x007e
#  define MK_RIGHT			0x007c
#  define MK_DOWN			0x007d

#  define MK_F1 			0x007a
#  define MK_F2				0x0078
#  define MK_F3				0x0063
#  define MK_F4				0x0076
#  define MK_F5				0x0060
#  define MK_F6				0x0061
#  define MK_F7				0x0062
#  define MK_F8				0x0064
#  define MK_F9				0x0065
#  define MK_F10			0x006d
#  define MK_F11			0x0067
#  define MK_F12			0x006f
#  define MK_F13			0x0069
#  define MK_F14			0x006b
#  define MK_F15			0x0071
#  define MK_F16			0x006a
#  define MK_F17			0x0040
#  define MK_F18			0x004f
#  define MK_F19			0x0050

#  define MK_1				0x0012
#  define MK_2				0x0013
#  define MK_3				0x0014
#  define MK_4				0x0015
#  define MK_5				0x0017
#  define MK_6				0x0016
#  define MK_7				0x001a
#  define MK_8				0x001c
#  define MK_9				0x0019
#  define MK_0				0x001d

#  define MK_A				0x0000
#  define MK_B				0x000b
#  define MK_C				0x0008
#  define MK_D				0x0002
#  define MK_E				0x000e
#  define MK_F				0x0003
#  define MK_G				0x0005
#  define MK_H				0x0004
#  define MK_I				0x0022
#  define MK_J				0x0026
#  define MK_K				0x0028
#  define MK_L				0x0025
#  define MK_M				0x002e
#  define MK_N				0x002d
#  define MK_O				0x001f
#  define MK_P				0x0023
#  define MK_Q				0x000c
#  define MK_R				0x000f
#  define MK_S				0x0001
#  define MK_T				0x0011
#  define MK_U				0x0020
#  define MK_V				0x0009
#  define MK_W				0x000d
#  define MK_X				0x0007
#  define MK_Y				0x0010
#  define MK_Z				0x0006
# endif
#endif

/*
# define MK_TILDE			0x0032
# define MK_MINUS			0x001b
# define MK_EQUAL			0x0018
# define MK_OPEN_BRACE		0x0021
# define MK_CLOSE_BRACE		0x001e
# define MK_PIPE			0x002a
# define MK_COLON			0x0029
# define MK_SEMI_COLON		0x0029
# define MK_SIMPLE_QUOTE	0x0027
# define MK_DOUBLE_QUOTES	0x0027
# define MK_LESS_THAN		0x002b
# define MK_COMMA			0x002b
# define MK_GREATER_THAN	0x002f
# define MK_DOT				0x002f
# define MK_SLASH			0x002c
# define MK_QUESTION_MARK	0x002c
# define MK_ALT				0x0105
# define MK_SPACE			0x0031
# define MK_ALT_GR			0x0106
# define MK_FN				0x0117
# define MK_HOME			0x0073
# define MK_END				0x0077
# define MK_PAGE_UP			0x0074
# define MK_PAGE_DOWN		0x0079
# define MK_CLEAR			0x0047
# define MK_PAD_1			0x0053
# define MK_PAD_2			0x0054
# define MK_PAD_3			0x0055
# define MK_PAD_4			0x0056
# define MK_PAD_5			0x0057
# define MK_PAD_6			0x0058
# define MK_PAD_7			0x0059
# define MK_PAD_8			0x005b
# define MK_PAD_9			0x005c
# define MK_PAD_0			0x0052
# define MK_PAD_EQUAL		0x0051
# define MK_PAD_DIVIDE		0x004b
# define MK_PAD_MULTIPLY	0x0043
# define MK_PAD_SUB			0x004e
# define MK_PAD_ADD			0x0045
# define MK_PAD_ENTER		0x004c
# define MK_PAD_DOT			0x0041
 */
