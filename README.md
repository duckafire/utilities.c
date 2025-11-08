[include-guard-c]: https://stackoverflow.com/questions/27810115/what-exactly-do-c-include-guards-do#27810143 "What exactly do C include guards do?"
[zlib-license]: https://www.zlib.net/zlib_license.html "zLib License header"

## utilities.c

A simple collection of useful libraries to C.



#### Topics

* [Available libraries](#available-libraries)
* [Subdirectories structure](#subdirectories-structure)
* [About libraries](#about-libraries)
	* [Text header](#text-header)
	* [Dependences](#dependences)
* [Writing conventions](#writing-conventions)
	* [Exported case styles](#exported-case-styles)
	* [Available matching patterns](#available-matching-patterns)
	* [Dictionary](#dictionary)
	* [Case styles](#case-styles)
		* [Libraries](#libraries)
		* [Code identifiers](#code-identifiers)



### Available libraries

[str]: ./src/String

> [String][str]: provides resources to manage null terminated string memory automatically.



### Subdirectories structure

* C file (`*.c`): contains the logical code.
* Header file (`*.h`): contains the declaration code.
* Wiki file (`README.md`): contains information about how to use the library.



### About libraries

#### Text header

As way to easily the compilation (mainly in different OS) and the understanding of the
licensing terms of the libraries from this project, both they must include the text
header below:

``` c
/*
 * AUTHORS:     <developer-name0> [... [developer-nameN]]
 * DESCRIPTION: <library-short-description>
 * C STANDARD:  cXX
 * LICENSE:     <license-name>
 *
 * <license-header
 * .
 * .
 * .>
 * */
```

> [!WARNING]
> After that a library license is chosen, it will not allow to change it.

> [!IMPORTANT]
> If you *publish* a library without to speficic a license, it will be licensed using
> the [*Zlib License*][zlib-license] (the same license of this project).

> [!NOTE]
> This header must be inside header file (`*.h`); and it is optional in C files (`*.c`).



#### Dependences

As way to easiler the compilation of the libraries from this project, both they must
depend only of libraries from C Standard chosen, and (optionally) of headers from
`./include/` (from this project repository).

> [!IMPORTANT]
> `./include/` is a *special subdirectory*, that it contains some header files made
> **only** with C preprocessor rules. Their content can be **optionally** required by
> libraries of this project.



### Writing conventions

#### Exported case styles

* *PascalCase*
* *SCREAMING\_SNAKE\_CASE*
* *UPPERCASE*
* *camelCase*
* *cobol-case*
* *lowercase*
* *snake\_case*



#### Available matching patterns

* [*Include guard*][include-guard-c]: preprocessor constants that will avoid that the
                                      headers content being posted multiple times in
                                      the same file. It is its structure:
                                      `__UTILITIES_C_<LIBRARY_NAME> __`
* *Shortened identifier*: identifiers formed by shortened words, like most functions
                          from C Standard, e.g.:
	* `string + catenate = strcat`;
	* `file + print + formated = fprintf`;
	* `is + alphabetic + number = isalnum`
* *`goto` label*: formed by a *lowercase* identifiers between two underscores
                  (`_<labelname>_`).
* `_*`: indicates that a identifier must not be manipulated (to read, to edit, ...)
        directly
        by the user code, only by the library code.
* `*_t`: indicates that the identifier is a type, that it did not based in a
         **`struct`**, defined with `typedef`.
* `u*`: indicates that the identifier is a type, that it was based in a **`union`**,
        defined with `typedef`.



#### Dictionary

* Functions:
	* *"Array like"*:
		* `*add*`: adds and returns an item from a specified position of an items chain.
		* `*get*`: gets an item from a specified position of an items chain.
		* `*rmv*`: removes and returns an item from a specified position of an items
		           chain.
	* Memory management:
		* `*start*`: allocates memory to an object, set the initial values of its
		              properties (it do not allocates to them) and it returns the object.
		* `*alloc*`: allocates memory to an object, it allocates memory to the values of
		             its properties and it returns the object.
		* `*free*`:  frees the memory allocated to an object.
	* Micenllaneous:
		* `*n*`: executes an operation based in the value of a parameter named as `n`.
		* `str*`:    manipulates resources based null terminated strings.
	* *"Queue like"*:
		* `*poll*`: removes and returns an item from the first position of an items
		            chain.
	* *"Stack like"*:
		* `*head*`: gets the first item of an items chain.
		* `*pop*`:  removes and returns an item from the last position of an items chain.
		* `*push*`: adds and returns an item from the last position of an items chain.
		* `*tail*`: gets the last  item of an items chain.
* No-functions:
	* Counting:
		* `i`, `j`, `l`, `t`: mainly used in *for-loops*.
	* Generic memory block:
		* `buffer`: used to store temporary information that they are necessary to
					execute a ***multiple****-function* process.
		* `temp`: used to store temporary information that they are necessary to execute
				  a ***single****-function* process.
	* Micenllaneous:
		* `content`: the main content of an object.
		* `index`: position of an element in a *list-like*.
		* `new*`: a value that will be created and used to replaced other.
		* `old*`: a value that will be replaced by other.
	* Parameters:
		* `dest`: will receive the values(s) resulting from the process.
		* `n`: represents a quantity, in bytes.
		* `src`: contains the value(s) that will be used during the process.
	* Properties:
		* `length`: quantity of **items** that compound an items list.
		* `next`: is the next item of a linked list.
		* `size`: quantity of **bytes** that compound an items list.

> [!IMPORTANT]
> `*` indicates that the word **can be** prefixed and/or suffixed.
> `*n*` must be between two, or more, (shortened) words. Similar: `strncat`; `strncpy`.



#### Case styles

##### Libraries

Below they are listed the case styles available to name the libraries directories:

* *cobol-case*: has functions destined to the execution of similar works or related.
* *PascalCase*: has functions to manipulate objects (based `struct`).

> [!IMPORTANT]
> The source files must be the same name of the library directory, with plus they
> specific extension. Therefore, if a library directory is named as `foo`, their source
> files must be named as `foo.c` and `foo.h`.



##### Code identifiers

* Identifiers:
	* Local:
		* Constants: *SCREAMING\_SNAKE\_CASE*
		* Functions: *snake\_case*
		* Variables: *camelCase*
	* Global:
		* *"Private"*:
			* Constants: *SCREAMING\_SNAKE\_CASE*
			* Functions: *snake\_case*
			* Variables: *camelCase*
		* *"Public"*:
			* Constants: *SCREAMING\_SNAKE\_CASE*
			* Functions: *lowercase*
			* Variables: *lowercase*
* Preprocessing:
	* Constants: *SCREAMING\_SNAKE\_CASE*
	* Macros:    *SCREAMING\_SNAKE\_CASE*
* Typing:
	* Defined with `typedef`:
		* Common type: *lowercase*
		* Enumerator:  *lowercase*
		* Structure:   *PascalCase*
		* Union:      *PascalCase*
	* No defined with `typedef`:
		* Enumerator: *lowercase*
		* Structure:  *PascalCase*
		* Union:      *PascalCase*
* Micellaneous:
	* Enumerators constants: *SCREAMING\_SNAKE\_CASE*

> [!NOTE]
> *Variables* also include:
>
> * `goto` labels
> * Parameters
> * Pointers (all)
> * Properties
