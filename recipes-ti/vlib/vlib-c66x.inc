DESCRIPTION = "TI Vision Library (VLIB) for C66x"
HOMEPAGE = "http://software-dl.ti.com/libs/vlib/latest/index_FDS.html"
SECTION = "devel"
LICENSE = "TI-TSPA & BSD-3-Clause"

require ../includes/ti-paths.inc
require ../includes/ti-staging.inc
require ../includes/ti-eula-unpack.inc

COMPATIBLE_MACHINE = "omap-a15|keystone"

SRC_URI = "http://software-dl.ti.com/libs/vlib/${PV}//exports/vlib_c66x_obj_${PV}_Linux.bin;name=vlibbin"

S = "${WORKDIR}/vlib_c66x_${PV}"

BINFILE="vlib_c66x_obj_${PV}_Linux.bin"
TI_BIN_UNPK_ARGS = "--mode silent --prefix ${S}"
TI_BIN_UNPK_CMDS=""

do_install() {
    install -d ${D}${VLIB_C66_INSTALL_DIR_RECIPE}
    cp -pPrf ${S}/* ${D}${VLIB_C66_INSTALL_DIR_RECIPE}
}

ALLOW_EMPTY_${PN} = "1"
FILES_${PN}-dev += "${VLIB_C66_INSTALL_DIR_RECIPE}"

INSANE_SKIP_${PN}-dev = "installed-vs-shipped arch"
