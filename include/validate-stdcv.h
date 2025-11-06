/*
 * MIT License
 *
 * Copyright (c) 2024-2025 DuckAfire <duckafire.github.io/nest>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#ifndef _JUMP_STDCV_VALIDATION
#define _JUMP_STDCV_VALIDATION

/* VERSION: 0.1.1 */

/*
 * EXPECTED_STDCV ust be declared during the compilator call. They valid
 * values are, respectivelly (yyyymm):
 * - xxxxxx : C89/C90
 * - 199901 : C99
 * - 201112 : C11
 * - 201710 : C17/C18
 * */

#ifdef __STDC_VERSION__
#	ifdef EXPECTED_STDCV
#		if EXPECTED_STDCV >= 199001L && EXPECTED_STDCV <= 299912L
#			if __STDC_VERSION__ < EXPECTED_STDCV
#				error "Invalid C Standard version"
#			endif
#		else
#			error "Invalid value to EXPECTED_STDCV"
#		endif
#	else
#		error "Preprocessing constant not defined: EXPECTED_STDCV"
#	endif
#else
#	if EXPECTED_STDCV != 0
#		error "Invalid C Standard version"
#	else
#		ifdef __cplusplus
#			error "The constant `__STDC_VERSION__` was not defined. Maybe it is being related with anything C++ compiler option"
#		endif
#	endif
#endif

#ifdef EXPECTED_STDCV
#	undef EXPECTED_STDCV
#endif

#endif /* _JUMP_STDCV_VALIDATION */
