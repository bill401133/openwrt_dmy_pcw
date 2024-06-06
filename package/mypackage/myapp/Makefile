##############################################
# 
# OpenWrt Makefile for mycode program
#
##############################################
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME := mycode
PKG_VERSION := 0.2
PKG_RELEASE := 1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=utils
  CATEGORY:=Other build Package
  SUBMENU:=Software Testing modules
  TITLE:=This is dmy's self-start test project.
  MAINTAINER:=Other build
endef

define Package/$(PKG_NAME)/description
    If you can't figure out what this program does, you're probably
    brain-dead and need immediate medical attention.
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
        CFLAGS="$(TARGET_CFLAGS) -Wall" \
        LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/app $(1)/etc/init.d/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/app/
	$(INSTALL_BIN) ./files/mycode $(1)/etc/init.d/
endef

define Package/$(PKG_NAME)/preinst
	#!/bin/bash
	echo 'installing $(PKG_NAME) which made by dmy'
endef

define Package/$(PKG_NAME)/postinst
	#!/bin/bash
	# check if we are on real system
	if [ -z "$${IPKG_INSTROOT}" ]; then
		echo "Enabling rc.d symlink for $(PKG_NAME)"
		/etc/init.d/mycode enable
	fi

	echo '$(PKG_NAME) installed successed which made by dmy !'
	exit 0
endef

define Package/$(PKG_NAME)/prerm
	#!/bin/bash
	# check if we are on real system
	if [ -z "$${IPKG_INSTROOT}" ]; then
		echo "Removing rc.d symlink for $(PKG_NAME)"
		/etc/init.d/mycode disable
	fi

	echo 'removeing $(PKG_NAME) which made by dmy'
	exit 0
endef

define Package/$(PKG_NAME)/postrm
	#!/bin/bash
	echo '$(PKG_NAME) remove successed which made by dmy !'
endef


$(eval $(call BuildPackage,$(PKG_NAME)))
