# BeagleBone Black
Linux Kernel & u-boot for the beagleboard.org boards

reference:

Please see https://github.com/beagleboard/linux for the latest official kernels.

## kernel 

### kernel patchset usage
======

beaglebone-3.11 patchset:
```
git checkout 3.11
./patch.sh
```

kenerl build
```
cd kernel/
wget "http://arago-project.org/git/projects/?p=am33x-cm3.git;a=blob_plain;f=bin/am335x-pm-firmware.bin;hb=HEAD" -O firmware/am335x-pm-firmware.bin
cp ../configs/beaglebone .config
make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi- LOADADDR=0x80008000 uImage dtbs
```

## u-Boot
* [Reference](http://eewiki.net/display/linuxonarm/BeagleBone+Black#BeagleBoneBlack-Bootloader:U-Boot)

### Source code download

```
mscho@gen ~/bbb/ $ git clone git:://git.denx.de/u-boot.git
mscho@gen ~/bbb/ $ git u-boot/
```

### Source code patch

```
mscho@gen ~/bbb/u-boot $ git checkout v2014.07 -b tmp
mscho@gen ~/bbb/u-boot $ wget -c https://raw.githubusercontent.com/eewiki/u-boot-patches/master/v2014.07/0001-am335x_evm-uEnv.txt-bootz-n-fixes.patch
mscho@gen ~/bbb/u-boot $ patch -p1 < 0001-am335x_evm-uEnv.txt-bootz-n-fixes.patch
```

### config & build

```
mscho@gen ~/bbb/u-boot $ make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi- distclean
mscho@gen ~/bbb/u-boot $ make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi- am335x_evm_config
Configuring for am335x_evm - Board: am335x_evm, Options: SERIAL1,CONS_INDEX=1,NAND
mscho@gen ~/bbb/u-boot $ make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi-
```

### check images

```
mscho@gen ~/u-boot $ ls -l MLO
-rw-r--r-- 1 mscho mscho 83700  9월 19 13:42 MLO
mscho@gen ~/u-boot $ ls -l u-boot.img
-rw-r--r-- 1 mscho mscho 450168  9월 19 13:42 u-boot.img
```


