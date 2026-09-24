# HLLWKrnl Development Roadmap (or todo)

### Phase 1: Base boot
- [x] Setup QEMU target platform (`versatilepb` or Allwinner A10)
- [x] Write startup code (Assembly `boot.s` -> set stack -> jump to C)
- [x] Write simple polling UART driver (for `printf` debug output);; see docs/UARTwhat.md
- [x] Write somewhat usable makefile (for assembling everything)

### Phase 2: Driver/config
- [ ] Make driver model, thus dummy driver, registration, etc;;
- [ ] Implement DTI Parser;; see README.md#dti-devicetreeinf-sample
- [ ] Design Driver Registry (`drv_req_access`, `drv_write_fast` logic);; see README.md#driver-interaction
- [ ] Implement Device Tree instantiation from DTI at boot
- [ ] Add basic driver set (GPIO, Timers, I2C/SPI bus abstraction)
- [ ] Integrate RTOS core (FreeRTOS kernel allocation & task scheduler)

### Phase 3: Memory/Security
- [ ] Setup ARM MMU page tables (Flat mapping for Kernel, isolated space for App)
- [ ] Implement basic memory allocator (`kmalloc` / system pool)
- [ ] Implement User/Permission system (Root vs User access checking in `drv_req_access`);; see README.md#driver-interaction

### Phase 4: Userspace/ABI
- [ ] Define syscall ABI (Software Interrupts / `SVC` instruction)
- [ ] Create basic userspace app loader (flat binary or simple ELF parser)
- [ ] Write simple libc / SDK wrapper for apps (`libhllw`)

---
*Contributions are welcome! Pick any unchecked task, open an issue/PR or contact mobilepaq@disroot.org.*
