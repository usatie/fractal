/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keymap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:02:58 by susami            #+#    #+#             */
/*   Updated: 2022/08/27 21:09:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYMAP_H
# define MLX_KEYMAP_H

# if defined(LINUX) || defined(ARM)
// import from keysymdef.h
#  define MK_BACKSPACE		0xff08  /* Back space, back char */
#  define MK_TAB			0xff09
#  define MK_LINE_FEED		0xff0a  /* Linefeed, LF */
#  define MK_CLEAR			0xff0b
#  define MK_RETURN			0xff0d  /* Return, enter */
#  define MK_PAUSE 			0xff13  /* Pause, hold */
#  define MK_ESCAPE			0xff1b
#  define MK_DELETE			0xffff  /* Delete, rubout */
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
#  define MK_SHIFT_L		0xffe1  /* Left shift */
#  define MK_SHIFT_R		0xffe2  /* Right shift */
#  define MK_CONTROL_L		0xffe3  /* Left control */
#  define MK_CONTROL_R		0xffe4  /* Right control */
#  define MK_CAPS_LOCK		0xffe5  /* Caps lock */
#  define MK_LEFT			0xff51  /* Move left, left arrow */
#  define MK_UP				0xff52  /* Move up, up arrow */
#  define MK_RIGHT			0xff53  /* Move right, right arrow */
#  define MK_DOWN			0xff54  /* Move down, down arrow */
#  define MK_CMD_L			0xffe7  /* Left meta */
#  define MK_CMD_R			0xffe8  /* Right meta */
#  define MK_OPTION			0xff7e  /* Alias for mode_switch */
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
#  define MK_BRACKETLEFT	0x005b  /* U+005B LEFT SQUARE BRACKET */
#  define MK_BACKSLASH		0x005c  /* U+005C REVERSE SOLIDUS */
#  define MK_BRACKETRIGHT	0x005d  /* U+005D RIGHT SQUARE BRACKET */

# else
// # if defined(OSX)
#  define MK_BACKSPACE		0xff08  /* Back space, back char */
#  define MK_TAB			0xff09
#  define MK_LINE_FEED		0xff0a  /* Linefeed, LF */
#  define MK_CLEAR			0xff0b
#  define MK_RETURN			0xff0d  /* Return, enter */
#  define MK_PAUSE 			0xff13  /* Pause, hold */
#  define MK_ESCAPE			0xff1b
#  define MK_DELETE			0xffff  /* Delete, rubout */
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
#  define MK_SHIFT_L		0xffe1  /* Left shift */
#  define MK_SHIFT_R		0xffe2  /* Right shift */
#  define MK_CONTROL_L		0xffe3  /* Left control */
#  define MK_CONTROL_R		0xffe4  /* Right control */
#  define MK_CAPS_LOCK		0xffe5  /* Caps lock */
#  define MK_LEFT			0xff51  /* Move left, left arrow */
#  define MK_UP				0xff52  /* Move up, up arrow */
#  define MK_RIGHT			0xff53  /* Move right, right arrow */
#  define MK_DOWN			0xff54  /* Move down, down arrow */
#  define MK_CMD_L			0xffe7  /* Left meta */
#  define MK_CMD_R			0xffe8  /* Right meta */
#  define MK_OPTION			0xff7e  /* Alias for mode_switch */
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
#  define MK_BRACKETLEFT	0x005b  /* U+005B LEFT SQUARE BRACKET */
#  define MK_BACKSLASH		0x005c  /* U+005C REVERSE SOLIDUS */
#  define MK_BRACKETRIGHT	0x005d  /* U+005D RIGHT SQUARE BRACKET */
# endif
#endif
