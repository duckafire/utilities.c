## String.h

It provides some resouces of memory management to manipulate strings.



#### Topics

* [Types](#types)
* [Constants](#constants)
* [Macros](#macros)
* [Global variables](#global-variables)
* [Global functions](#global-functions)




### Types

* `String`: structure based type that it store a null terminated string and its length.
	* `const char *content`: null terminated string 
	* `size_t length`: quantity of characters that compound `content` less the null
	                   character.

> [!NOTE]
> Please, do not change manually the values of these properties. Only use them to
> reading.



### Constants

* `EOS`: *End Of String* represents the null character (`\0`).
* `EMPTY_STRING`: represents an empty null terminated string (`"\0"`).



### Macros

* `IS_VALID_STRING(str)`: expands to a boolean expression that it verifies if `str` is
                          not `NULL`, and if its content is not `NULL`.
	* `str`: a started `String` object that it will be verified.

* `IS_EMPTY_STRING(str)`: expands to a boolean expression that it verifies if `str` is
                          not `NULL`, if its content is equal `EMPTY_STRING`, and if
                          its length is equal `0`.
	* `str`: a started `String` object that it will be verified.



### Global functions

#### strstart
###### O(1)

* `String* strstart(void)`

* Behavior: allocates memory to a `String` instance, whose content will be equal
            `EMPTY_STRING`.
* Return: the created object address or `NULL` in case of error.



#### stralloc
###### O(n)

* `String* stralloc(const char *content)`
	* `*content`: a null terminated string that will be the content of the object that
	              will be instantiated.

* Behavior: allocates memory to a `String` instance, whose content will be a copy
            of `content` (allocated dynamically).
* Return: the created object address or `NULL` in case of error.

> [!NOTE]
> It gets the `content` length automatically.



#### strnalloc
###### O(n)

* `String* stralloc(const char *content, size_t n)`
	* `*content`: a null terminated string that will be the content of the object that
	              will be instantiated.
	* `n`: `content` length, in bytes.

* Behavior: allocates memory to a `String` instance, whose content will be a copy
            of `content` (allocated dynamically).
* Return: the created object address or `NULL` in case of error.



#### strfree
###### O(1)

* `String* strfree(String *str)`
	* `*str`: object instance whose memory address will be freed.

* Behavior: frees `str` memory address.
* Return: none.

> [!NOTE]
> Trying to access the address after of the freeing process it can cause undefined
> behavior.



#### strpushc
###### O(1)

* `String* strpushc(String *dest, char c)`
	* `*dest`: object whose content will be catenated with `c`.
	* `c`: character that will be catenated in `dest` content.

* Behavior: catenates `c` in the `dest` content, in the last index.
* Return: `dest` address or `NULL` in case of error.



#### strpushs
###### O(n)

* `String* strpushs(String *dest, const char *src)`
	* `*dest`: object whose content will be catenated with `src`.
	* `*content`: null terminated string that will be catenated in `dest` content.

* Behavior: catenates `src` content in the `dest` content, starting from the last index.
* Return: `dest` address or `NULL` in case of error.

> [!NOTE]
> It gets the `content` length automatically.



#### strnpushs
###### O(n)

* `String* strnpushs(String *dest, const char *src, size_t n)`
	* `*dest`: object whose content will be catenated with `src`.
	* `*content`: a null terminated string that will be catenated in `dest` content.
	* `n`: `src` length, in bytes (it do not include the null character).

* Behavior: catenates the first `n` bytes of `src` in the `dest` content, starting from
            the last index.
* Return: `dest` address or `NULL` in case of error.



#### strpushstr
###### O(n)

* `String* strpushstr(String *dest, const String *src)`
	* `*dest`: object whose content will be catenated with `src` content.
	* `*src`: object whose content will be catenated in `dest` content.

* Behavior: catenates `src` content in the `dest` content, starting from the last index.
* Return: `dest` address or `NULL` in case of error.



#### strmerge
###### O(n)

* `String* strmerge(const String *src0, const String *src1)`
	* `*src0`: object whore content will be used to created other `String` instance.
	* `*src1`: object whore content will be used to created other `String` instance.

* Behavior: creates a `String` object whose content is equal the catenation of the
            `src0` content and `src1` content.
* Return: the created object address or `NULL` in case of error.



#### strclone
###### O(n)

* `String* strclone(const String *src)`
	* `*src`: object that will be cloned.

* Behavior: creates a copy of `src`.
* Return: the created object address or `NULL` in case of error.



#### strsubstr
###### O(n)

* `String* strsubstr(const String *src, size_t index, size_t n)`
	* `*src`: object whose content will be extracted to create other object instance.
	* `index`: position of the first byte that will be extracted from `src` content.
	* `n`: quantity of bytes that will form the created object content.

* Behavior: extracted part of the `src` content and it uses it to create other `String`
            instance.
* Return: the created object address or `NULL` in case of error.



#### strpollc
###### O(n)

* `String* strpollc(String *str)`
	* `*str`: object whose content will be subtracted.

* Behavior: removes the first byte from `str` content.
* Return: `str` address or `NULL` in case of error.



#### strnpollc
###### O(n)

* `String* strnpollc(String *str, size_t n)`
	* `*str`: object whose content will be subtracted.
	* `n`: quantity of bytes that will be removed.

* Behavior: removes the first `n` bytes from `str` content.
* Return: `str` address or `NULL` in case of error.



#### strpopc
###### O(n)

* `String* strpopc(String *str)`
	* `*str`: object whose content will be subtracted.

* Behavior: removes the last byte from `str` content.
* Return: `str` address or `NULL` in case of error.



#### strnpopc
###### O(n)

* `String* strnpopc(String *str, size_t n)`
	* `*str`: object whose content will be subtracted.
	* `n`: quantity of bytes that will be removed.

* Behavior: removes the last `n` bytes from `str` content.
* Return: `str` address or `NULL` in case of error.



#### strcut
###### O(n)

* `String* strcut(String *str, size_t index, size_t n)`
	* `*str`: object whose content will be subtracted.
	* `index`: position of the first byte that will be removed from `src` content.
	* `n`: quantity of bytes that will be removed.

* Behavior: removes a chunk from `str` content, from `index` to `index + n`.
* Return: `str` address or `NULL` in case of error.

