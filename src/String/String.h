/*
 * Zlib License
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

/* VERSION: 0.0.2 */

#ifndef __UTILITITES_C__STRING_EXTRA__

#include "validate-stdcv.h"
#include "debug-error.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

/* they are used when
 * __ENABLE_UTILITITES_C_DEBUG
 * is defined */
#define _MALLOC_FAILURE   "Malloc failure."
#define _REALLOC_FAILURE  "Realloc failure."
#define _INVALID_STRING   "Invalid String object."
#define _INVALID_INTERVAL "Invalid interval."

/* End Of String */
#define EOS '\0'
#define EMPTY_STRING "\0"

#define IS_VALID_STRING(str) \
	((str) != NULL && (str)->content != NULL)

#define IS_EMPTY_STRING(str) \
	((str) != NULL && ((str)->content)[0] == EOS && (str)->length == 0)

typedef struct
{
	char *content;
	size_t length;
} String;

/*
 * All function are listed below, separed in "groups".
 * Each group has a "master function" that is used in
 * the other functions from the same group.
 * This avoids the hard code and it improves the code
 * security, because it reduces the code quantity.
 * */

String* strstart(void); /* main */

String* stralloc (const char *content);
String* strnalloc(const char *content, size_t n); /* main */

void strfree(String *str); /* main */

String* strpushc(String *str, char c);
String* strpushs(String *str, const char *s);
String* strnpushs(String *dest, const char *src, size_t n); /* main */
String* strpushstr(String *dest, const String *src);
String* strmerge(const String *src0, const String *src1);
String* strclone(const String *src);
String* strsubstr(const String *src, size_t index, size_t n);

String* strpollc(String *str);
String* strnpollc(String *str, size_t n);
String* strpopc(String *str);
String* strnpopc(String *str, size_t n);
String* strcut(String *str, size_t index, size_t n); /* main */

#ifdef __cplusplus
}
#endif

#endif /* __UTILITITES__STRING_EXTRA__ */
