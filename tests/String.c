#include <stdio.h>
#include <string.h>
#include "String.h"

#define BREAK puts("")
#define ERROR   "\e[31;1m"
#define SUCCESS "\e[32;1m"
#define END     "\e[0m"

static void expect(const char *name, const char *excontent, String *str)
{
	/* EXpected COntent LENgth */
	const size_t EXCOLEN = strlen(excontent);

	printf(
		/* name: [content == excontent] | [length == exlength] | [it is null terminated] */
		"%s: %s[%s == %s]" END " | %s[%lld == %lld]" END " | %s[it is null terminated]" END "\n",
		name,
		(strcmp(excontent, str->content) == 0 ? SUCCESS : ERROR),
		str->content,
		excontent,
		(EXCOLEN == str->length ? SUCCESS : ERROR),
		str->length,
		EXCOLEN,
		((str->content)[str->length] == EOS ? SUCCESS : ERROR)
	);

	strfree(str);
}

int main(void)
{
	/*******************************************/
	String *a, *b, *c, *d, *e;
	/*******************************************/
	a = strstart();
	b = stralloc("a");
	c = strnalloc("ab", 2);

	expect("strstart",  "",   a);
	expect("stralloc",  "a",  b);
	expect("strnalloc", "ab", c);

	BREAK;
	/*******************************************/
	a = stralloc("abcde");
	b = stralloc("abcde");
	c = stralloc("abcde");
	d = stralloc("abcde");
	e = stralloc("ABCDE");

	strpushc(a, 'A');
	strpushs(b, e->content);
	strnpushs(c, e->content, e->length);
	strpushstr(d, e);

	expect("strpushc",   "abcdeA" ,    a);
	expect("strpushs",   "abcdeABCDE", b);
	expect("strnpushs",  "abcdeABCDE", c);
	expect("strpushstr", "abcdeABCDE", d);
	strfree(e);

	BREAK;
	/*******************************************/
	a = stralloc("abcd");
	b = stralloc("ABCD");

	c = strmerge(a, b);
	d = strclone(a);
	e = strsubstr(b, 1, 2);

	expect("[ARG]",     "abcd",     a);
	expect("[ARG]",     "ABCD",     b);
	expect("strmerge",  "abcdABCD", c);
	expect("strclone",  "abcd",     d);
	expect("strsubstr", "BC",       e);

	BREAK;
	/*******************************************/
	a = stralloc("abcde");
	b = stralloc("abcde");
	c = stralloc("abcde");
	d = stralloc("abcde");
	e = stralloc("abcde");

	strpollc(a);
	strnpollc(b, 2);
	strpopc(c);
	strnpopc(d, 2);
	strcut(e, 1, 2);

	expect("strpollc",  "bcde", a);
	expect("strnpollc", "cde",  b);
	expect("strpopc",   "abcd", c);
	expect("strnpopc",  "abc",  d);
	expect("strcut",    "ade",  e);

	BREAK;
	/*******************************************/
	return 0;
}
