##############################################
# 
# OpenWrt Makefile for my-core-dump-test-error-code program
#
##############################################
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME := my-core-dump-test-error-code
PKG_VERSION := 1.0
PKG_RELEASE := 1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=utils
  CATEGORY:=Other build Package
  SUBMENU:=Software Testing modules
  TITLE:=This is dmy's core-dump study test project.
  MAINTAINER:=Other build
endef

define Package/$(PKG_NAME)/description
    This package is using for learn how to make a core dump in OpenWrt,
    so program have a mistake which will terminated the program and make a core dump if all is well.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Configure
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		ARCH="$(LINUX_KARCH)" \
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/app $(1)/etc/init.d/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/app/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
