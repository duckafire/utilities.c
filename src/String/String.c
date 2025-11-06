/*

Zlib License

Copyright (C) 2025 DuckAfire <https://duckafire.gitlab.io>

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required. 
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "String.h"



String* strstart(void)
{
	String *str = malloc( sizeof(String) );

	if(str == NULL)
	{
		DEBUG_ERROR( _MALLOC_FAILURE );
		return NULL;
	}

	str->length  = 0;
	str->content = EMPTY_STRING;

	return str;
}



String* stralloc(const char *content)
{
	return strnalloc(content, strlen(content));
}

String* strnalloc(const char *content, size_t n)
{
	String *str = strstart();

	if(str == NULL)
		return NULL;

	char *tmp = malloc(n + 1);

	if(tmp == NULL)
	{
		DEBUG_ERROR( _MALLOC_FAILURE );
		return NULL;
	}

	strcpy(tmp, content);

	str->length  = n;
	str->content = tmp;

	return str;
}



void strfree(String *str)
{
	if(str == NULL)
		return;

	if(!IS_EMPTY_STRING(str))
		free(str->content);

	free(str);
}



String* strpushc(String *str, char c)
{
	char src[2] = "\0\0";
	src[0] = c;

	return strnpushs(str, src, 1);
}

String* strpushs(String *str, const char *s)
{
	return strnpushs(str, s, strlen(s));
}

String* strnpushs(String *dest, const char *src, size_t n)
{
	if(!IS_VALID_STRING(dest))
	{
		DEBUG_ERROR( _INVALID_STRING );
		return NULL;
	}

	const size_t NEW_LENGTH = dest->length + n;
	const bool IS_EMPTY = IS_EMPTY_STRING(dest);
	char *newcontent;
	
	if(IS_EMPTY)
		newcontent = malloc(NEW_LENGTH + 1);
	else
		newcontent = realloc(dest->content, NEW_LENGTH + 1);

	if(newcontent == NULL)
	{
		DEBUG_ERROR( (IS_EMPTY ? _MALLOC_FAILURE : _REALLOC_FAILURE) );
		return NULL;
	}

	for(size_t i = 0; true; i++)
	{
		newcontent[ dest->length + i ] = src[i];

		if(src[i] == EOS)
			break;
	}

	dest->length  = NEW_LENGTH;
	dest->content = newcontent;
	return dest;
}

String* strpushstr(String *dest, const String *src)
{
	return strnpushs(dest, src->content, src->length);
}

String* strmerge(const String *src0, const String *src1)
{
	if(!IS_VALID_STRING(src0) || !IS_VALID_STRING(src1))
	{
		DEBUG_ERROR( _INVALID_STRING );
		return NULL;
	}

	String *dest;

	for(short i = 0; i < 2; i++)
	{
		if(i == 0)
			 dest = strclone(src0);
		else
			strpushstr(dest, src1);

		if(dest == NULL)
		{
			strfree(dest);
			return NULL;
		}
	}


	return dest;
}

String* strclone(const String *src)
{
	if(!IS_VALID_STRING(src))
	{
		DEBUG_ERROR( _INVALID_STRING );
		return NULL;
	}

	return strnalloc(src->content, src->length);
}

String* strsubstr(const String *str, size_t index, size_t n)
{
	if(!IS_VALID_STRING(str))
	{
		DEBUG_ERROR( _INVALID_STRING );
		return NULL;
	}

	if(n == 0 || index > str->length || index + n > str->length)
	{
		DEBUG_ERROR( _INVALID_INTERVAL );
		return NULL;
	}

	if(index == 0 && n == str->length)
		return strclone(str);

	char *tmp = malloc(n + 1);

	if(tmp == NULL)
	{
		DEBUG_ERROR( _MALLOC_FAILURE );
		return NULL;
	}

	for(size_t i = 0; i < n; i++)
		tmp[i] = (str->content)[index + i];

	tmp[n] = EOS;
	return strnalloc(tmp, n);
}



String* strpollc(String *str)
{
	return strcut(str, 0, 1);
}

String* strnpollc(String *str, size_t n)
{
	return strcut(str, 0, n);
}

String* strpopc(String *str)
{
	return strcut(str, str->length - 1, 1);
}

String* strnpopc(String *str, size_t n)
{
	return strcut(str, str->length - n, n);
}

String* strcut(String *str, size_t index, size_t n)
{
	if(!IS_VALID_STRING(str))
	{
		DEBUG_ERROR( _INVALID_STRING );
		return NULL;
	}

	if(n == 0 || index > str->length || index + n > str->length)
	{
		DEBUG_ERROR( _INVALID_INTERVAL );
		return NULL;
	}

	if(index == 0 && n == str->length)
	{
		strfree(str);
		return strstart();
	}

	char *newcontent = malloc(n + 1);

	if(newcontent == NULL)
	{
		DEBUG_ERROR( _MALLOC_FAILURE );
		return NULL;
	}

	// `i` to `newcontent`
	// `j` to `str`
	for(size_t i = 0, j = 0; true; i++, j++)
	{
		if(j == index)
			j += n;

		newcontent[i] = (str->content)[j];

		if((str->content)[j] == EOS)
			break;
	}

	free(str->content);

	(str->length)-= n;
	str->content = newcontent;

	return str;
}
