ENTRY(_start)
SECTIONS
{
    . = 0x10000;
    .text : { *(.text) }
    .data : { *(.data) }
    .bss  : { *(.bss) }
    
    . = ALIGN(8);
    . += 0x1000; /* 4KB STACK */
    stack_top = .;
}
