# BeagleBone Black

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

