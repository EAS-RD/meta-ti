DESCRIPTION = "TI SCI firmware"

LICENSE = "TI-TFL"
LIC_FILES_CHKSUM = "file://LICENCE.ti-keystone;md5=3a86335d32864b0bef996bee26cc0f2c"

PV = "0.1.1.4"
PR = "r0"

CLEANBROKEN = "1"

COMPATIBLE_MACHINE = "k2g-evm"

PACKAGE_ARCH = "${MACHINE_ARCH}"

SRCREV = "11c3f5df2276c542966c32e95289ec49d111a696"
BRANCH ?= "ti-linux-firmware-4.1.y"

SRC_URI = "git://git.ti.com/processor-firmware/ti-linux-firmware.git;protocol=git;branch=${BRANCH}"

S = "${WORKDIR}/git"
TARGET = "ti-sci-firmware-k2g.bin"

do_install() {
	install -d ${D}/boot
	install -m 0644 ${S}/ti-keystone/${TARGET} ${D}/boot/${TARGET}
}

FILES_${PN} = "/boot"

inherit deploy

do_deploy () {
	install -d ${DEPLOYDIR}
	install -m 0644 ${S}/ti-keystone/${TARGET} ${DEPLOYDIR}/${TARGET}
}

addtask deploy before do_build after do_compile
