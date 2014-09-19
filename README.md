# BeagleBone Black
Linux Kernel & u-boot for the beagleboard.org boards

reference:

Please see https://github.com/beagleboard/linux for the latest official kernels.

## kernel 

### kernel patchset usage
======

beaglebone-3.11 patchset:
```
git checkout origin/3.11 -b 3.11
./patch.sh
```

beaglebone-3.12 patchset:
```
git checkout origin/3.12 -b 3.12
./patch.sh
```

beaglebone-3.13 patchset:
```
git checkout origin/3.13 -b 3.13
./patch.sh
```

beaglebone-3.14 patchset:
```
git checkout origin/3.14 -b 3.14
./patch.sh
```

## u-Boot
* [Reference](http://eewiki.net/display/linuxonarm/BeagleBone+Black#BeagleBoneBlack-Bootloader:U-Boot)

### Source code download

```
~/bbb/ $ git clone git:://git.denx.de/u-boot.git
~/bbb/ $ git u-boot/
```

### Source code patch

```
~/bbb/u-boot $ git checkout v2014.07 -b tmp
~/bbb/u-boot $ wget -c https://raw.githubusercontent.com/eewiki/u-boot-patches/master/v2014.07/0001-am335x_evm-uEnv.txt-bootz-n-fixes.patch
~/bbb/u-boot $ patch -p1 < 0001-am335x_evm-uEnv.txt-bootz-n-fixes.patch
```

### config & build

```
~/bbb/u-boot $ make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi- distclean
~/bbb/u-boot $ make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi- am335x_evm_config
Configuring for am335x_evm - Board: am335x_evm, Options: SERIAL1,CONS_INDEX=1,NAND
~/bbb/u-boot $ make -j2 ARCH=arm CROSS_COMPILE=armv7a-hardfloat-linux-gnueabi-
```

### check images

```
~/u-boot $ ls -l MLO
-rw-r--r-- 1 mscho mscho 83700  9월 19 13:42 MLO
~/u-boot $ ls -l u-boot.img
-rw-r--r-- 1 mscho mscho 450168  9월 19 13:42 u-boot.img
```


