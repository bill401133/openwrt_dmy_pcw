include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=hello_kernel
PKG_VERSION:=1.01

include $(INCLUDE_DIR)/package.mk

define KernelPackage/$(PKG_NAME)
  SUBMENU:=Other Modules
  CATEGORY:=Base system
  TITLE:=comp hello test code
  DEPENDS:=kmod-ipt-conntrack
  FILES:=$(PKG_BUILD_DIR)/hello_kernel.ko
  AUTOLOAD:=$(call AutoLoad,66,hello_kernel)
endef

define Build/Prepare
    mkdir -p $(PKG_BUILD_DIR)
    $(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
    $(MAKE) -C "$(LINUX_DIR)" \
        $(MAKE_OPTS) \
        modules
endef

$(eval $(call KernelPackage,$(PKG_NAME)))