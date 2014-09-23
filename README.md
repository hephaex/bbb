# BeagleBone Black
Linux Kernel & u-boot for the beagleboard.org boards

reference:

Please see https://github.com/beagleboard/linux for the latest official kernels.

## kernel 
======

### kernel patchset usage
* beaglebone-3.11 patchset:
```
git checkout origin/3.11 -b 3.11
./patch.sh
```

* beaglebone-3.12 patchset:
```
git checkout origin/3.12 -b 3.12
./patch.sh
```

* beaglebone-3.13 patchset:
```
git checkout origin/3.13 -b 3.13
./patch.sh
```

* beaglebone-3.14 patchset:
```
git checkout origin/3.14 -b 3.14
./patch.sh
```

## u-Boot
=====
* u-boot (univertial boot loader)
* [http://www.denx.de/wiki/U-Boot](http://www.denx.de/wiki/U-Boot)
* [Ref.](http://eewiki.net/display/linuxonarm/BeagleBone+Black#BeagleBoneBlack-Bootloader:U-Boot)

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

## dtb
=====

dtc : device tree compiler

[Reference](http://eewiki.net/display/linuxonarm/BeagleBone+Black#BeagleBoneBlack-Upgradedistro)

```
$ wget -c https://github.com/hephaex/toolchain/tree/master/arm/dtc.sh
$ chmod +x dtc.sh
$ ./dtc.sh
```

# microSD card install
1. Insert the microSD Card into build machine. 
 - ls /dev/sdX
2. Begin partioning the microSD Card by typing fdisk /dev/sdX
 - fdisk /dev/sdX
 - a. Initialize a new partition table by selecting o,
      then verify the partition table is empty by selecting p.
 - b. Create a boot partition by selecting n for ‘new’,
      then p for ‘primary’, and 1 to specify the first partition.
	  Press enter to accept the default first sector and specify 4095
	  for the last sector.
 - c. Change the partition type to FAT16 by selecting t
      for ‘type’ and e for ‘W95 FAT16 (LBA)’.
 - d. Set the partition bootable by selecting a then 1.
 - e. Create the data partition for the root filesystem by selecting n
      for ‘new’, then p for ‘primary’,and 2 to specify the second partition.
	  Accept the default values for the first and last sectors by pressing enter twice.
 - f. Press p to ‘print’ the partition table.
 - g. Finally, commit the changes by selecting w to ‘write’ the partition table and exit fdisk.

```
root@ubuntu-armhf:/home/ubuntu# fdisk /dev/mmcblk1

Command (m for help): o
Building a new DOS disklabel with disk identifier 0xef30879d.
Changes will remain in memory only, until you decide to write them.
After that, of course, the previous content won't be recoverable.

Warning: invalid flag 0x0000 of partition table 4 will be corrected by w(rite)

Command (m for help): n
Partition type:
   p   primary (0 primary, 0 extended, 4 free)
      e   extended
	  Select (default p): p
	  Partition number (1-4, default 1): 1
	  First sector (2048-31116287, default 2048):
	  Using default value 2048
	  Last sector, +sectors or +size{K,M,G} (2048-31116287, default 31116287): 4095

Command (m for help): t
Selected partition 1
Hex code (type L to list codes): e
Changed system type of partition 1 to e (W95 FAT16 (LBA))

Command (m for help): a
Partition number (1-4): 1

Command (m for help): n
Partition type:
   p   primary (1 primary, 0 extended, 3 free)
      e   extended
	  Select (default p): p
	  Partition number (1-4, default 2):
	  Using default value 2
	  First sector (4096-31116287, default 4096):
	  Using default value 4096
	  Last sector, +sectors or +size{K,M,G} (4096-31116287, default 31116287):
	  Using default value 31116287

Command (m for help): w
The partition table has been altered!

Calling ioctl() to re-read partition table.

WARNING: If you have created or modified any DOS 6.x
partitions, please see the fdisk manual page for additional
information.
Syncing disks.
```

3. Format the Partitions
 - Format partition 1 as FAT
```
mkfs.vfat /dev/sdX1
```
 - Format partition 2 as ext4
```
mkfs.ext4 /dev/sdX2
```

4. install u-boot to the microSD card
```
mkdir boot
mount /dev/sdX1 boot
tar xJvf uboot.tar.xz -C boot
umount boot
```

5. Install the desired root filesystem to the microSD Card.
```
mkdir rootfs
mount /dev/sdX2 rootfs
tar xJvf ubuntu-trusty-14.04-rootfs-3.14.4.1.tar.xz -C rootfs
umount rootfs
```

6. The microSD Card is ready to boot. 
