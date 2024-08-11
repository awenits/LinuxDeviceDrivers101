# LinuxDeviceDrivers101
Contains codes used while learning Linux Device Driver Development

Makefiles
Basic components of the dirvers - init/exit
system calls file operations(proc)
creating proc entry, interating with it
interaction of serspace and kernel space

#### TODOs
1. create sample app to write to kernel buffer by binding the write operation with proc file
2. Add the process to compile the driver and injecting into the kernel

compilation
$ make

load
$ sudo insmod firstmodule.ko

unload
$ sudo rmmod firstmodule 

remove compiled temeporary files
$ make clean

Utilities
$ lsmod
$ sudo dmesg
$ sudo dmesg -c
$ clear

### TODOs Explore
character device drivers
/dev entries
system calls
controlling/interacting with hardware
Preloded Modules in the kernel image
device tree (linkage with module)


