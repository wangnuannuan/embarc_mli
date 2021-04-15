#
# Copyright 2020, Synopsys, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-3-Clause license found in
# the LICENSE file in the root directory of this source tree.
#

BACKSLASH=\$(nullstring)
ifneq ($(ComSpec)$(COMSPEC),)
	O_SYS=Windows
	RM=del /F /Q
	RMDIR=rmdir /Q /S
	MKDIR=mkdir
	CP=copy /Y
	CPR=xcopy /I /E /Y
	PS=$(BACKSLASH)
	fix_platform_path = $(subst /,$(PS), $(1))
else
	O_SYS=Linux
	RM=rm -rf
	RMDIR=rm -rf
	MKDIR=mkdir -p
	CP=cp
	CPR= cp -r
	PS=/
	fix_platform_path=$(1)
endif

ifeq ($(MLI_BUILD_REFERENCE),ON)
POSTFIX = _ref
else
POSTFIX =
endif

BUILD_DIR_BASE     ?= $(PUBLIC_DIR)$(PS)obj
LIBRARY_DIR_BASE   ?= $(PUBLIC_DIR)$(PS)bin
# we do not use CURDIR, since slashes in there cause problems on Windows
PUBLIC_DIR         ?= ..$(PS)..$(PS)

ifndef TCF_FILE
BUILD_DIR          ?= $(BUILD_DIR_BASE)$(PS)native$(POSTFIX)
LIBRARY_DIR        ?= $(LIBRARY_DIR_BASE)$(PS)native$(POSTFIX)
else
BUILD_DIR          ?= $(BUILD_DIR_BASE)$(PS)arc$(POSTFIX)
LIBRARY_DIR        ?= $(LIBRARY_DIR_BASE)$(PS)arc$(POSTFIX)
endif

ifeq ($(O_SYS),Windows)
BIN_EXT = .exe
else
BIN_EXT =
endif
