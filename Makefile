##############################################################################

# MIT License
#
# Copyright (c) 2025 DuckAfire <duckafire.gitlab.io>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.



##############################################################################
# CALL OPTIONS

C    ?=90#        C Standard version
CC   ?=gcc#       C compiler
SRC  ?=./src#     source code directory
DEST ?=./build#   directory of the output files
TEST ?=./tests#   directory of the files of test
INCL ?=./include# directory that has common headers

# to use them, both must be defined and not empty:
# NO_VALI  : disables Standard C version validation
# NO_DEBUG : disables macro DEBUG_ERROR (prints error messages in runtime)
# AUTO_STD : disables C Standard definition



##############################################################################
# GLOBAL SCOPE

ROOT_DEST :=$(DEST)# root directory of the destine directory
CC_FLAGS  :=#        flags used in the compiler
PP_VARS   :=#        preprocessor variables required by header files from `./include`
CCO       :=#        CC_FLAGS + PP_VARS (defined below)



##############################################################################
# VALIDATION VARIABLES VALUES

ifdef NO_VALI
  PP_VARS +=_JUMP_STDCV_VALIDATION=
endif

ifdef AUTO_STD
  ifndef NO_VALI
    PP_VARS +=_JUMP_STDCV_VALIDATION=
    C       :=-1
  endif

else
  ifeq ($(C), 89)
    STDCV :=0L

  else ifeq ($(C), 90)
    STDCV :=0L

  else ifeq ($(C), 99)
    STDCV :=199901L

  else ifeq ($(C), 11)
    STDCV :=201112L

  else ifeq ($(C), 17)
    STDCV :=201710L

  else ifeq ($(C), 18)
    STDCV :=201710L

  else ifeq ($(C), 23)
    STDCV :=202311L

  else
    $(error Invalid C Standard version: C$(C))
  endif

  PP_VARS +=EXPECTED_STDCV=$(STDCV)
endif


ifdef NO_DEBUG
  PP_VARS +=_DISABLE_DEBUG_ERROR=
endif



##############################################################################
# SET VALUES BASED OUTPUT TYPE

OUT_EXT :=

ifdef LIB
  # dynamic libraries
  ifeq ($(LIB), 0)
    DEST    :=$(addsuffix /libs/dynamic, $(DEST))
    OUT_EXT :=.so

  # static libraries
  else
    DEST    :=$(addsuffix /libs/static, $(DEST))
    OUT_EXT :=.a
  endif

# tests binaries
else
  DEST          :=$(addsuffix /tests/bin, $(DEST))
  CC_FLAGS      +=-g

  # add test file that has
  # the `main` function
  SRC_STRING :=$(addsuffix tests/String.c, $(SRC_STRING))
endif



##############################################################################
# TARGETS SOURCE FILES

SRC_EXT :=.c .h

# $(foreach ext, $(SRC_EXT),$(addprefix $(SRC)/, $(addprefix $(NAME_FOO)/, $(NAME_FOO)))$(ext))
# foo -> foo/foo -> bar/foo/foo -> bar/foo/foo.a bar/foo/foo.b

# $(addprefix $(TARGETS_PREFIX), $(addsuffix $(TARGETS_SUFFIX), $(NAME_STRING)))
# foo --> bar/libfoo -> bar/libfoo.so
#     +-> bar/libfoo -> bar/libfoo.a
#     +-> bar/foo    -> bar/foo

NAME_STRING := String
SRC_STRING  :=$(foreach ext, $(SRC_EXT),$(addprefix $(SRC)/, $(addprefix $(NAME_STRING)/, $(NAME_STRING)))$(ext))
DEST_STRING :=$(addprefix $(DEST)/, $(addsuffix $(OUT_EXT), $(NAME_STRING)))

ifndef LIB
  SRC_STRING +=$(addprefix $(TEST)/, $(addsuffix .c, $(NAME_STRING)))
endif



##############################################################################
# VARIABLES WORKMANSHIP

PP_VARS :=$(addprefix -D, $(PP_VARS))

ifneq ($(C), -1)
  CC_FLAGS += -std=c$(C)
endif

CCO :=$(CC_FLAGS) $(PP_VARS)



##############################################################################
# PHONY TARGETS

.PHONY: all test

all: $(DEST) $(DEST_STRING)

test: $(DEST)
	@$(foreach exec, $(wildcard $(DEST)/*), ./$(exec))



##############################################################################
# FILE/DIRECTORY TARGETS

$(DEST):
	@mkdir --parents $@

$(DEST_STRING): $(SRC_STRING)
	@$(CC) $+ -o $@ -I $(INCL) -I $(dir $<) $(CCO)



##############################################################################
