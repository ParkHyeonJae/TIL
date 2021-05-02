	.file	"VirtualFunction.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
LC0:
	.ascii "animal Constructor\0"
LC1:
	.ascii "\12\0"
	.section	.text$_ZN6AnimalC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6AnimalC2Ev
	.def	__ZN6AnimalC2Ev;	.scl	2;	.type	32;	.endef
__ZN6AnimalC2Ev:
LFB1446:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV6Animal+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1446:
	.section .rdata,"dr"
LC2:
	.ascii "animal Destructor\0"
	.section	.text$_ZN6AnimalD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6AnimalD2Ev
	.def	__ZN6AnimalD2Ev;	.scl	2;	.type	32;	.endef
__ZN6AnimalD2Ev:
LFB1449:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1449
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV6Animal+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1449:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1449:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1449-LLSDACSB1449
LLSDACSB1449:
LLSDACSE1449:
	.section	.text$_ZN6AnimalD2Ev,"x"
	.linkonce discard
	.section	.text$_ZN6AnimalD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6AnimalD1Ev
	.def	__ZN6AnimalD1Ev;	.scl	2;	.type	32;	.endef
__ZN6AnimalD1Ev:
LFB1450:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1450
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV6Animal+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1450:
	.section	.gcc_except_table,"w"
LLSDA1450:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1450-LLSDACSB1450
LLSDACSB1450:
LLSDACSE1450:
	.section	.text$_ZN6AnimalD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN6AnimalD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6AnimalD0Ev
	.def	__ZN6AnimalD0Ev;	.scl	2;	.type	32;	.endef
__ZN6AnimalD0Ev:
LFB1451:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN6AnimalD1Ev
	movl	$4, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1451:
	.section .rdata,"dr"
LC3:
	.ascii "Animal Sound\0"
	.section	.text$_ZN6Animal5speakEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6Animal5speakEv
	.def	__ZN6Animal5speakEv;	.scl	2;	.type	32;	.endef
__ZN6Animal5speakEv:
LFB1452:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1452:
	.section .rdata,"dr"
LC4:
	.ascii "Dog Constructor\0"
	.section	.text$_ZN3DogC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3DogC1Ev
	.def	__ZN3DogC1Ev;	.scl	2;	.type	32;	.endef
__ZN3DogC1Ev:
LFB1455:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1455
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
LEHB0:
	call	__ZN6AnimalC2Ev
LEHE0:
	movl	$__ZTV3Dog+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB1:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
LEHE1:
	jmp	L9
L8:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN6AnimalD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
L9:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1455:
	.section	.gcc_except_table,"w"
LLSDA1455:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1455-LLSDACSB1455
LLSDACSB1455:
	.uleb128 LEHB0-LFB1455
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB1455
	.uleb128 LEHE1-LEHB1
	.uleb128 L8-LFB1455
	.uleb128 0
	.uleb128 LEHB2-LFB1455
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE1455:
	.section	.text$_ZN3DogC1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
LC5:
	.ascii "Dog Destructor\0"
	.section	.text$_ZN3DogD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3DogD1Ev
	.def	__ZN3DogD1Ev;	.scl	2;	.type	32;	.endef
__ZN3DogD1Ev:
LFB1458:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1458
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV3Dog+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN6AnimalD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1458:
	.section	.gcc_except_table,"w"
LLSDA1458:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1458-LLSDACSB1458
LLSDACSB1458:
LLSDACSE1458:
	.section	.text$_ZN3DogD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN3DogD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3DogD0Ev
	.def	__ZN3DogD0Ev;	.scl	2;	.type	32;	.endef
__ZN3DogD0Ev:
LFB1459:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN3DogD1Ev
	movl	$4, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1459:
	.section .rdata,"dr"
LC6:
	.ascii "Dog Sound\0"
	.section	.text$_ZN3Dog5speakEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3Dog5speakEv
	.def	__ZN3Dog5speakEv;	.scl	2;	.type	32;	.endef
__ZN3Dog5speakEv:
LFB1460:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1460:
	.section .rdata,"dr"
LC7:
	.ascii "cat Constructor\0"
	.section	.text$_ZN3CatC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3CatC1Ev
	.def	__ZN3CatC1Ev;	.scl	2;	.type	32;	.endef
__ZN3CatC1Ev:
LFB1463:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1463
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
LEHB3:
	call	__ZN6AnimalC2Ev
LEHE3:
	movl	$__ZTV3Cat+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC7, 4(%esp)
	movl	$__ZSt4cout, (%esp)
LEHB4:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
LEHE4:
	jmp	L16
L15:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN6AnimalD2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB5:
	call	__Unwind_Resume
LEHE5:
L16:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1463:
	.section	.gcc_except_table,"w"
LLSDA1463:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1463-LLSDACSB1463
LLSDACSB1463:
	.uleb128 LEHB3-LFB1463
	.uleb128 LEHE3-LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB4-LFB1463
	.uleb128 LEHE4-LEHB4
	.uleb128 L15-LFB1463
	.uleb128 0
	.uleb128 LEHB5-LFB1463
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE1463:
	.section	.text$_ZN3CatC1Ev,"x"
	.linkonce discard
	.section .rdata,"dr"
LC8:
	.ascii "cat Destructor\0"
	.section	.text$_ZN3CatD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3CatD1Ev
	.def	__ZN3CatD1Ev;	.scl	2;	.type	32;	.endef
__ZN3CatD1Ev:
LFB1466:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1466
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$__ZTV3Cat+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	$LC8, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN6AnimalD2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1466:
	.section	.gcc_except_table,"w"
LLSDA1466:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1466-LLSDACSB1466
LLSDACSB1466:
LLSDACSE1466:
	.section	.text$_ZN3CatD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN3CatD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3CatD0Ev
	.def	__ZN3CatD0Ev;	.scl	2;	.type	32;	.endef
__ZN3CatD0Ev:
LFB1467:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN3CatD1Ev
	movl	$4, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPvj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1467:
	.section .rdata,"dr"
LC9:
	.ascii "Cat Sound\0"
	.section	.text$_ZN3Cat5speakEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN3Cat5speakEv
	.def	__ZN3Cat5speakEv;	.scl	2;	.type	32;	.endef
__ZN3Cat5speakEv:
LFB1468:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC9, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1468:
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1469:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1469
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	subl	$44, %esp
	call	___main
	movl	$0, -32(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
LEHB6:
	call	__ZNSirsERi
	subl	$4, %esp
	movl	-32(%ebp), %eax
	testl	%eax, %eax
	jne	L21
	movl	$4, (%esp)
	call	__Znwj
LEHE6:
	movl	%eax, %ebx
	movl	%ebx, %ecx
LEHB7:
	call	__ZN3CatC1Ev
LEHE7:
	movl	%ebx, -28(%ebp)
	jmp	L22
L21:
	movl	$4, (%esp)
LEHB8:
	call	__Znwj
LEHE8:
	movl	%eax, %ebx
	movl	%ebx, %ecx
LEHB9:
	call	__ZN3DogC1Ev
LEHE9:
	movl	%ebx, -28(%ebp)
L22:
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	movl	%edx, %ecx
LEHB10:
	call	*%eax
	cmpl	$0, -28(%ebp)
	je	L23
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	movl	%edx, %ecx
	call	*%eax
L23:
	movl	$0, %eax
	jmp	L29
L27:
	movl	%eax, %esi
	movl	$4, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
L28:
	movl	%eax, %esi
	movl	$4, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE10:
L29:
	leal	-12(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1469:
	.section	.gcc_except_table,"w"
LLSDA1469:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1469-LLSDACSB1469
LLSDACSB1469:
	.uleb128 LEHB6-LFB1469
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB7-LFB1469
	.uleb128 LEHE7-LEHB7
	.uleb128 L27-LFB1469
	.uleb128 0
	.uleb128 LEHB8-LFB1469
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB1469
	.uleb128 LEHE9-LEHB9
	.uleb128 L28-LFB1469
	.uleb128 0
	.uleb128 LEHB10-LFB1469
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
LLSDACSE1469:
	.text
	.globl	__ZTV3Cat
	.section	.rdata$_ZTV3Cat,"dr"
	.linkonce same_size
	.align 4
__ZTV3Cat:
	.long	0
	.long	__ZTI3Cat
	.long	__ZN3CatD1Ev
	.long	__ZN3CatD0Ev
	.long	__ZN3Cat5speakEv
	.globl	__ZTV3Dog
	.section	.rdata$_ZTV3Dog,"dr"
	.linkonce same_size
	.align 4
__ZTV3Dog:
	.long	0
	.long	__ZTI3Dog
	.long	__ZN3DogD1Ev
	.long	__ZN3DogD0Ev
	.long	__ZN3Dog5speakEv
	.globl	__ZTV6Animal
	.section	.rdata$_ZTV6Animal,"dr"
	.linkonce same_size
	.align 4
__ZTV6Animal:
	.long	0
	.long	__ZTI6Animal
	.long	__ZN6AnimalD1Ev
	.long	__ZN6AnimalD0Ev
	.long	__ZN6Animal5speakEv
	.globl	__ZTI3Cat
	.section	.rdata$_ZTI3Cat,"dr"
	.linkonce same_size
	.align 4
__ZTI3Cat:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS3Cat
	.long	__ZTI6Animal
	.globl	__ZTS3Cat
	.section	.rdata$_ZTS3Cat,"dr"
	.linkonce same_size
	.align 4
__ZTS3Cat:
	.ascii "3Cat\0"
	.globl	__ZTI3Dog
	.section	.rdata$_ZTI3Dog,"dr"
	.linkonce same_size
	.align 4
__ZTI3Dog:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS3Dog
	.long	__ZTI6Animal
	.globl	__ZTS3Dog
	.section	.rdata$_ZTS3Dog,"dr"
	.linkonce same_size
	.align 4
__ZTS3Dog:
	.ascii "3Dog\0"
	.globl	__ZTI6Animal
	.section	.rdata$_ZTI6Animal,"dr"
	.linkonce same_size
	.align 4
__ZTI6Animal:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS6Animal
	.globl	__ZTS6Animal
	.section	.rdata$_ZTS6Animal,"dr"
	.linkonce same_size
	.align 4
__ZTS6Animal:
	.ascii "6Animal\0"
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1897:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1897:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1896:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L33
	cmpl	$65535, 12(%ebp)
	jne	L33
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L33:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1896:
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1898:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1898:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
