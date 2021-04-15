#
# Copyright 2019-2021, Synopsys, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-3-Clause license found in
# the LICENSE file in the root directory of this source tree.
#

PUBLIC_DIR = ../..
include $(PUBLIC_DIR)/make/settings.mk

PLATFORMLIST = \
    vpx5_integer_full

# Not supported:
#   emsdp_em7d_em5d_dfss \
#   himax_arcem9d_r16 \
#   iotdk_arcem9d

JOBS    ?= 4
LIB_DIR  = $(PUBLIC_DIR)/bin
LIB_NAME = libmli.a
TCF_DIR  = $(PUBLIC_DIR)/hw
LIB_LIST = $(addsuffix /$(LIB_NAME), $(addprefix $(LIB_DIR)/, $(PLATFORMLIST)) )

PKG_NAME = embARC_MLI_package
PKG_TMP_FOLDER = $(PUBLIC_DIR)/$(PKG_NAME)
FILE_LIST = $(addsuffix .tcf, $(addprefix $(PKG_TMP_FOLDER)/hw/, $(PLATFORMLIST)) )
FILE_LIST += $(PKG_TMP_FOLDER)/LICENSE

$(LIB_LIST) : $(LIB_DIR)/%/$(LIB_NAME): $(TCF_DIR)/%.tcf
	$(MAKE) -C $(PUBLIC_DIR)/lib/make \
		TCF_FILE=$< \
		BUILD_DIR=$(PUBLIC_DIR)/obj/$*/debug \
		LIBRARY_DIR=$(LIB_DIR)/$*/debug \
		DEBUG_BUILD=ON \
		MLI_DEBUG_MODE=DBG_MODE_FULL \
		JOBS=$(JOBS)

	$(MAKE) -C $(PUBLIC_DIR)/lib/make \
		TCF_FILE=$< \
		BUILD_DIR=$(PUBLIC_DIR)/obj/$*/release \
		LIBRARY_DIR=$(LIB_DIR)/$*/release \
		DEBUG_BUILD=OFF \
		MLI_DEBUG_MODE=DBG_MODE_RELEASE \
		JOBS=$(JOBS)

	$(MAKE) -C $(PUBLIC_DIR)/user_tests/make test_all \
		TCF_FILE=$< \
		BUILD_DIR=$(PUBLIC_DIR)/obj/$*/release \
		LIBRARY_DIR=$(LIB_DIR)/$*/release \
		PERFORM_BUILD=OFF

	$(MAKE) -C $(PUBLIC_DIR)/user_tests/make test_all \
		TCF_FILE=$< \
		BUILD_DIR=$(PUBLIC_DIR)/obj/$*/debug \
		LIBRARY_DIR=$(LIB_DIR)/$*/debug \
		PERFORM_BUILD=OFF

$(PKG_TMP_FOLDER):
	$(MKDIR) $(call fix_platform_path,$@)
	$(MKDIR) $(call fix_platform_path,$@/hw)

package_libs: $(LIB_LIST) $(PKG_TMP_FOLDER)
	$(CPR) $(call fix_platform_path,$(PUBLIC_DIR)/bin) $(call fix_platform_path,$(PKG_TMP_FOLDER)/bin/)

package_includes: $(PKG_TMP_FOLDER)
	$(CPR) $(call fix_platform_path,$(PUBLIC_DIR)/include) $(call fix_platform_path,$(PUBLIC_DIR)/$(PKG_NAME)/include/)

$(FILE_LIST): $(PKG_TMP_FOLDER)/% : $(PUBLIC_DIR)/%
	$(CP) $(call fix_platform_path,$<) $(call fix_platform_path,$@)

package_content: package_libs package_includes $(FILE_LIST)

package: package_content
	cd ../.. & zip $(PKG_NAME).zip -r $(PKG_NAME)
	$(RMDIR) $(call fix_platform_path,$(PKG_TMP_FOLDER))

clean:
	@echo Cleaning package...
	-@$(RMDIR) $(call fix_platform_path,$(LIB_DIR))
	-@$(RMDIR) $(call fix_platform_path,$(PUBLIC_DIR)/obj)
	-@$(RM) $(call fix_platform_path,$(PUBLIC_DIR)/$(PKG_NAME).zip)


