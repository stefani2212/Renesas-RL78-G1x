/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 * 
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 */

 
ENTRY(_PowerON_Reset)


MEMORY
{
	IVEC    : ORIGIN =     0x0, LENGTH = 0x80
	OPT     : ORIGIN =    0xC0, LENGTH =    4
	SEC_ID  : ORIGIN =    0xC4, LENGTH =   10
	ROM     : ORIGIN =    0xCE, LENGTH =  32K
	RAM     : ORIGIN = 0xFEF00, LENGTH = 4064
}

SECTIONS
{
	.vects 0x0 : AT (0x0)
	{
		KEEP(*(.vects))
	} > IVEC
    
	.option_bytes 0xC0 : AT (0xC0)
	{
		KEEP(*(.option_bytes))
	} > OPT
    
	.security_id 0xC4 : AT (0xC4)
	{
		KEEP(*(.security_id))
	} > SEC_ID
    
	.lowtext 0xCE : AT (0xCE)
	{
		*(.plt)
		*(.lowtext)
		. = ALIGN(2);
	} > ROM
    
	.tors : 
	{
		__CTOR_LIST__ = .;
		. = ALIGN(2);
		___ctors = .;
		*(.ctors)
		___ctors_end = .;
		__CTOR_END__ = .;
		__DTOR_LIST__ = .;
		___dtors = .;
		*(.dtors)
		___dtors_end = .;
		__DTOR_END__ = .;
		_mdata = .;
	} > ROM
    
	.text (. + __romdatacopysize) : 
	{
		*(.text)
		*(.text.*)
		etext = .;
		. = ALIGN(2);
	} > ROM
    
	.init : 
	{
		*(.init)
	} > ROM
    
	.fini : 
	{
		*(.fini)
	} > ROM
    
	.got : 
	{
		*(.got)
		*(.got.plt)
	} > ROM
    
	.rodata MAX(., 0x2000) : 
	{
		. = ALIGN(2);
		*(.rodata)
		*(.rodata.*)
		_erodata = .;
	} > ROM
    
	.eh_frame_hdr : 
	{
		*(.eh_frame_hdr)
	} > ROM
    
	.eh_frame : 
	{
		*(.eh_frame)
	} > ROM
    
	.jcr : 
	{
		*(.jcr)
		. = ALIGN(2);
	} > ROM
    
	.data 0xFEF00 : AT (_mdata)
	{
		. = ALIGN(2);
		_data = .;
		*(.data)
		*(.data.*)
		. = ALIGN(2);
		_edata = .;
	} > RAM

	PROVIDE (__romdatacopysize = SIZEOF(.data));

	.bss : 
	{
		. = ALIGN(2);
		_bss = .;
		*(.bss)
		*(.bss.**)
		. = ALIGN(2);
		*(COMMON)
		. = ALIGN(2);
		_ebss = .;
		_end = .;
	} > RAM
    
/*	.stack 0xFFE00 (NOLOAD)  : AT (0xFFE00)
	{
		_stack = .;
	} > RAM
*/
    _stack = ORIGIN(RAM) + LENGTH(RAM);
}
