SUMMARY = "Qualcomm test packagegroup"
DESCRIPTION = "Package group to bring in packages required to test images"

inherit packagegroup

PACKAGES = "${PN}"

RDEPENDS:${PN} = "\
    igt-gpu-tools \
    iperf3 \
    libkcapi \
    lmbench \
    "
