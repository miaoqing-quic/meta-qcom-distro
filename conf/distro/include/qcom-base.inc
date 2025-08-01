DISTRO_VERSION = "2.0"

# SDK variables.
SDK_VERSION = "${DISTRO_VERSION}"
SDK_NAME = "${DISTRO}-${SDKMACHINE}-${IMAGE_BASENAME}-${TUNE_PKGARCH}-${MACHINE}"
SDK_VENDOR = "-qcomsdk"

TARGET_VENDOR = "-qcom"

DISTRO_FEATURES:append = " \
    bluetooth \
    efi \
    glvnd \
    overlayfs \
    pam \
    pni-names \
    ptest \
    wifi \
"

# Use systemd init manager for system initialization.
INIT_MANAGER = "systemd"

# Prepare a flat image directory structure suitable to flash with QDL
IMAGE_CLASSES += "image_types_qcom"
IMAGE_FSTYPES += "qcomflash"

# Set a default package class to avoid surprises
PACKAGE_CLASSES = "package_ipk"

# Avoid to duplicate the rootfs tarball by generating both tar.gz/tar.xz
IMAGE_FSTYPES:remove = "tar.gz"

# Pull in the initrd image by default
INITRAMFS_IMAGE = "initramfs-rootfs-image"

INHERIT += "buildhistory"
INHERIT += "image-buildinfo"
INHERIT += "recipe_sanity"

BUILDHISTORY_COMMIT = "1"

require conf/distro/include/security_flags.inc
require conf/distro/include/yocto-space-optimize.inc
require conf/distro/include/yocto-uninative.inc

INHERIT += "uninative"

# Enable OpenCL
PACKAGECONFIG:append:pn-mesa = " opencl libclc gallium-llvm"
PACKAGECONFIG:append:pn-mesa-native = " opencl libclc gallium-llvm"
PACKAGECONFIG:append:pn-nativesdk-mesa = " opencl libclc gallium-llvm"

# Disable weston idle timeout
PACKAGECONFIG:append:pn-weston-init = " no-idle-timeout"
