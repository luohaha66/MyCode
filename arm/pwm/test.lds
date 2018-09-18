ENTRY(_start)
SECTIONS{
	. = 0x41000000;
	.text : {
        start.o(.text)
		*(.text)
	}
	.data : {
		*(.data)
	}
	.bss : {
		*(.bss)	
	}
}
