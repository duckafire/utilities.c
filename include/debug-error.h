/*
 * AUTHORS:     DuckAfire
 * DESCRIPTION: macros to debugging in runtime.
 * C STANDARD:  c89, c90
 * LICENSE:     Zlib License
 *
 * Copyright (C) 2025 DuckAfire <https://duckafire.gitlab.io>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 * */

/* VERSION: 0.0.1 */

#ifndef _DISABLE_DEBUG_ERROR
#define _DISABLE_DEBUG_ERROR

#	ifdef __cplusplus
extern "C" {
#	endif

#	ifdef _ENABLE_UTILITIES_C_DEBUG
#		include <stdio.h>

#		ifndef __FILE__
#			define __FILE__ "???.?"
#		endif

#		ifndef __LINE__
#			define __LINE__ -1
#		endif

		/** [ERROR]
		 ** Line: x | File: /path/to/file.c
		 ** 	Error message. */
#		define DEBUG_ERROR(msg) printf("\e[31;1m[ERROR]\n\e[0m\e[31mLine: %lld | File: %s\n\t%s\e[0m\n", __LINE__, __FILE__, msg)

#	else
#		define DEBUG_ERROR(msg)
#	endif

#	ifdef __cplusplus
}
#	endif

#endif /* _DISABLE_DEBUG_ERROR */
