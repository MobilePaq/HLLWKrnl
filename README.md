# HLLWKrnl
MicroKernel/OSKernel Concept.
- **!! This is currently a design concept, not a working kernel. Contributions are welcome. !!**
# What is it
*HLLWKrnl - now your toaster on ARM926EJ can be a PC!*
- It should be RTOS based (e.g FreeRTOS)
- It should be distributed under GPLv3
- Device Tree is DTI (some mix of INF/INI and my hallucinations, see DTI example)
- It should not be a x86/PC OS , just embeddables like MIPS/ARM/RISC-V/ETC
- The drivers will be incompiled (like in linux, no driver module/.ko will be available. This will help avoid linker problems during initial development and save memory)
- This is planned to be a mini OS (simple permissions/users, protected memory (for apps))
- Drivers should be easy to write, have adequate documention and stabilized ABI/API in kernel (or it should be updated in a way which DOESNT break old drivers)
# Implementation details
## Driver interaction
### Writing from SW
```c
#include <hllw/drv.h>

void main(void) {
    device_h handle = drv_req_access("/gpio/led0", O_RW); //this takes some time

    if (handle < 0) {
        return;
    }
    while (1) {
        for (uint8_t bright = 0; bright < 255; bright++) {
            drv_write_fast(handle, bright); //basically lookup and writing, fast
            delay_ms(5);
        }
    }
} 
typedef enum {
    DEV_OK           =  0,
    DEV_ERR_NOT_FOUND= -1, // no such device, it wasnt registered at all
    DEV_ERR_BUSY     = -2, // busy
    DEV_ERR_PERM     = -3, //  (Permission Denied)
    DEV_ERR_HW_FAULT = -4  // error hw
} dev_err_t; (handle)
```
Slow getting of device handle(pointer) is only **done once, at the same time permissions are checked.**
Then you write fast, with minimal delay.
- Note 1: SysFS-like, no FS emulation actually exists. Thus why its not just opening/closing files.
- Note 2: only ONE program at a time can use a device for RW (O_RW), reading (O_RO) can use as many as you want.
- Note 3: You can customize permissions for devices (e.g everybody can read, but only programs ran as root or by user with permission can write to all/particular device)
### Info
You will be able to get some info on the driver
```c
device_h handle = drv_req_access("/disp/screen0", O_RO);
printf(drv_get_info(handle));
```
Out:
"sun4i_panel_rgb: rgb_(panelmodel)" (see the DTI Sample)
### Device registration
Boot-critical driver (UART) **does NOT need registration**, other devices do need it. UART is 'inside' the kernel, so its doesn't use the DTI (needed for reliability).
As you see in DTI Sample below, UART/CPU/Memory/Interrupt DO NOT require registration.
This is a compromise, allowing for some versatility(e.g, one kernel can be used on multiple boards with same SoC), while keeping things simple.

### DTI (DeviceTreeINF) Sample
No dependency solver, drivers are initialized from up to down in order, so keep that in mind.
```
[spicont0]
drv="sun4i-spi";
channel=0;
mount="/spi/cont0";

[i2ccont0]
drv="sun4i-i2c";
channel=0;
mount="/i2c/cont0";

[i2cdev0]
drv="axp209";
interface="/i2c/cont0";
mount="/pwr/axp209";

[regulator0]
drv="axp209";
interface="/pwr/axp209"
mount="/pwr/reg/example-reg-666";
axp_reg_channel=2;
axp_volt=6.66;

[spidev0]
drv="spi_ili9341";
res="320x240";
orientation=0;
interface="/spi/cont0";
mount="/disp/screen1";
cs="/gpio/pin34";
regulator="example-reg-666";

[screen0]
drv="sun4i_panel_rgb";
mount="/disp/screen0";
type="rgb_(panel model)";
orientation=0;
mode=24;(bit)
pins="...";
regulator="example-reg-666";

[sound0]
drv="sun4i-codec";
mount="/sound/codec0";
regulator="example-reg-666";
```
# Contacting/Contributing
Contributing is welcome (although you will need to create a PR).
- Email:Mobilepaq@disroot.org
