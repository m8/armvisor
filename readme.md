# armvisor
simple bare-metal armv8 (aarch64) hypervisor for learning purposes.

* vm, vcpu arch
* stage 2 address translation
* hypervisor interrupts, gicv3
* timer (el2, el1), uart

## environment
- qemu-system-aarch64
- arm toolchain: aarch64-linux-gnu
- gdb-multiarch


## use
```
> make
```


```
--------------------------
                            _                
                           (_)               
   __ _ _ __ _ __ _____   ___ ___  ___  _ __ 
  / _` | '__| '_ ` _ \ \ / / / __|/ _ \| '__|
 | (_| | |  | | | | | \ V /| \__ \ (_) | |   
  \__,_|_|  |_| |_| |_|\_/ |_|___/\___/|_|   
                                             
                                             
~~ armvisor started ~~
application: 
Exception level: 0000000000000008
--------------------------
> HYP:Init Success
> HYP:TIMER2 init
> HYP:UART init
> HYP:VM regiter start
> HYP:VM id: 0000000000000001
> HYP:VM start addr: 0000000060000000
> HYP:Interrupts enabled
--------------------------
> IRQ: 000000000000001A
> IRQ: Cleared
--------------------------

hello vm 1
```


for debugging
```
> make debug
$ gdb target remote localhost:1234
```

## to-do
- [] hypervisor: loader should be changed
- [] hypervisor: virtual interrupt routing
- [] debugging: dump guest memory

