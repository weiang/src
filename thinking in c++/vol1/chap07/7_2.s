	.file	"7_2.cpp"
.lcomm __ZStL8__ioinit,1,1
	.text
	.align 2
.globl __ZN7MessageC2ESs
	.def	__ZN7MessageC2ESs;	.scl	2;	.type	32;	.endef
__ZN7MessageC2ESs:
LFB1215:
	pushl	%ebp
LCFI0:
	movl	%esp, %ebp
LCFI1:
	pushl	%ebx
LCFI2:
	subl	$20, %esp
LCFI3:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB0:
	call	__ZNSsC1Ev
LEHE0:
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB1:
	call	__ZNSsaSERKSs
LEHE1:
	jmp	L4
L3:
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB2:
	call	__Unwind_Resume
LEHE2:
L4:
	addl	$20, %esp
	popl	%ebx
LCFI4:
	popl	%ebp
LCFI5:
	ret
LFE1215:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1215:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1215-LLSDACSB1215
LLSDACSB1215:
	.uleb128 LEHB0-LFB1215
	.uleb128 LEHE0-LEHB0
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 LEHB1-LFB1215
	.uleb128 LEHE1-LEHB1
	.uleb128 L3-LFB1215
	.uleb128 0x0
	.uleb128 LEHB2-LFB1215
	.uleb128 LEHE2-LEHB2
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1215:
	.text
.globl __ZN7MessageC1ESs
	.def	__ZN7MessageC1ESs;	.scl	2;	.type	32;	.endef
	.set	__ZN7MessageC1ESs,__ZN7MessageC2ESs
	.align 2
.globl __ZN7Message5printEv
	.def	__ZN7Message5printEv;	.scl	2;	.type	32;	.endef
__ZN7Message5printEv:
LFB1217:
	pushl	%ebp
LCFI6:
	movl	%esp, %ebp
LCFI7:
	subl	$24, %esp
LCFI8:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
LCFI9:
	ret
LFE1217:
	.align 2
.globl __ZN7Message5printESs
	.def	__ZN7Message5printESs;	.scl	2;	.type	32;	.endef
__ZN7Message5printESs:
LFB1218:
	pushl	%ebp
LCFI10:
	movl	%esp, %ebp
LCFI11:
	pushl	%ebx
LCFI12:
	subl	$20, %esp
LCFI13:
	movl	8(%ebp), %ebx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	addl	$20, %esp
	popl	%ebx
LCFI14:
	popl	%ebp
LCFI15:
	ret
LFE1218:
	.section	.text$_ZN7MessageD1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN7MessageD1Ev
	.def	__ZN7MessageD1Ev;	.scl	2;	.type	32;	.endef
__ZN7MessageD1Ev:
LFB1222:
	pushl	%ebp
LCFI16:
	movl	%esp, %ebp
LCFI17:
	subl	$24, %esp
LCFI18:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leave
LCFI19:
	ret
LFE1222:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Hello, World!\0"
LC1:
	.ascii "Weiang\0"
LC2:
	.ascii "\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1219:
	pushl	%ebp
LCFI20:
	movl	%esp, %ebp
LCFI21:
	andl	$-16, %esp
LCFI22:
	pushl	%ebx
LCFI23:
	subl	$76, %esp
LCFI24:
	call	___main
	leal	39(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	39(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	leal	32(%esp), %eax
	movl	%eax, (%esp)
LEHB3:
	call	__ZNSsC1EPKcRKSaIcE
LEHE3:
	leal	32(%esp), %eax
	movl	%eax, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
LEHB4:
	call	__ZN7MessageC1ESs
LEHE4:
	leal	32(%esp), %eax
	movl	%eax, (%esp)
LEHB5:
	call	__ZNSsD1Ev
LEHE5:
	leal	39(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	28(%esp), %eax
	movl	%eax, (%esp)
LEHB6:
	call	__ZN7Message5printEv
LEHE6:
	leal	47(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	47(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
LEHB7:
	call	__ZNSsC1EPKcRKSaIcE
LEHE7:
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
LEHB8:
	call	__ZN7Message5printESs
LEHE8:
	leal	40(%esp), %eax
	movl	%eax, (%esp)
LEHB9:
	call	__ZNSsD1Ev
LEHE9:
	leal	47(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	55(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	55(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC2, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
LEHB10:
	call	__ZNSsC1EPKcRKSaIcE
LEHE10:
	leal	48(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
LEHB11:
	call	__ZN7MessageC1ESs
LEHE11:
	leal	48(%esp), %eax
	movl	%eax, (%esp)
LEHB12:
	call	__ZNSsD1Ev
LEHE12:
	leal	55(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	24(%esp), %eax
	movl	%eax, (%esp)
LEHB13:
	call	__ZN7Message5printEv
LEHE13:
	leal	63(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	63(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	leal	56(%esp), %eax
	movl	%eax, (%esp)
LEHB14:
	call	__ZNSsC1EPKcRKSaIcE
LEHE14:
	leal	56(%esp), %eax
	movl	%eax, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
LEHB15:
	call	__ZN7Message5printESs
LEHE15:
	leal	56(%esp), %eax
	movl	%eax, (%esp)
LEHB16:
	call	__ZNSsD1Ev
LEHE16:
	leal	63(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	$0, %ebx
	leal	24(%esp), %eax
	movl	%eax, (%esp)
LEHB17:
	call	__ZN7MessageD1Ev
LEHE17:
	leal	28(%esp), %eax
	movl	%eax, (%esp)
LEHB18:
	call	__ZN7MessageD1Ev
LEHE18:
	movl	%ebx, %eax
	addl	$76, %esp
	popl	%ebx
LCFI25:
	movl	%ebp, %esp
LCFI26:
	popl	%ebp
LCFI27:
	ret
L23:
LCFI28:
	movl	%eax, %ebx
	leal	32(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L11
L24:
	movl	%eax, %ebx
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN7MessageD1Ev
	jmp	L11
L22:
	movl	%eax, %ebx
L11:
	leal	39(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
L27:
	movl	%eax, %ebx
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L14
L26:
	movl	%eax, %ebx
L14:
	leal	47(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L15
L29:
	movl	%eax, %ebx
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L17
L30:
	movl	%eax, %ebx
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN7MessageD1Ev
	jmp	L17
L28:
	movl	%eax, %ebx
L17:
	leal	55(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L15
L33:
	movl	%eax, %ebx
	leal	56(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	jmp	L20
L32:
	movl	%eax, %ebx
L20:
	leal	63(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L21
L31:
	movl	%eax, %ebx
L21:
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN7MessageD1Ev
	jmp	L15
L25:
	movl	%eax, %ebx
L15:
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	__ZN7MessageD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB20:
	call	__Unwind_Resume
LEHE20:
LFE1219:
	.section	.gcc_except_table,"w"
LLSDA1219:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1219-LLSDACSB1219
LLSDACSB1219:
	.uleb128 LEHB3-LFB1219
	.uleb128 LEHE3-LEHB3
	.uleb128 L22-LFB1219
	.uleb128 0x0
	.uleb128 LEHB4-LFB1219
	.uleb128 LEHE4-LEHB4
	.uleb128 L23-LFB1219
	.uleb128 0x0
	.uleb128 LEHB5-LFB1219
	.uleb128 LEHE5-LEHB5
	.uleb128 L24-LFB1219
	.uleb128 0x0
	.uleb128 LEHB6-LFB1219
	.uleb128 LEHE6-LEHB6
	.uleb128 L25-LFB1219
	.uleb128 0x0
	.uleb128 LEHB7-LFB1219
	.uleb128 LEHE7-LEHB7
	.uleb128 L26-LFB1219
	.uleb128 0x0
	.uleb128 LEHB8-LFB1219
	.uleb128 LEHE8-LEHB8
	.uleb128 L27-LFB1219
	.uleb128 0x0
	.uleb128 LEHB9-LFB1219
	.uleb128 LEHE9-LEHB9
	.uleb128 L26-LFB1219
	.uleb128 0x0
	.uleb128 LEHB10-LFB1219
	.uleb128 LEHE10-LEHB10
	.uleb128 L28-LFB1219
	.uleb128 0x0
	.uleb128 LEHB11-LFB1219
	.uleb128 LEHE11-LEHB11
	.uleb128 L29-LFB1219
	.uleb128 0x0
	.uleb128 LEHB12-LFB1219
	.uleb128 LEHE12-LEHB12
	.uleb128 L30-LFB1219
	.uleb128 0x0
	.uleb128 LEHB13-LFB1219
	.uleb128 LEHE13-LEHB13
	.uleb128 L31-LFB1219
	.uleb128 0x0
	.uleb128 LEHB14-LFB1219
	.uleb128 LEHE14-LEHB14
	.uleb128 L32-LFB1219
	.uleb128 0x0
	.uleb128 LEHB15-LFB1219
	.uleb128 LEHE15-LEHB15
	.uleb128 L33-LFB1219
	.uleb128 0x0
	.uleb128 LEHB16-LFB1219
	.uleb128 LEHE16-LEHB16
	.uleb128 L32-LFB1219
	.uleb128 0x0
	.uleb128 LEHB17-LFB1219
	.uleb128 LEHE17-LEHB17
	.uleb128 L25-LFB1219
	.uleb128 0x0
	.uleb128 LEHB18-LFB1219
	.uleb128 LEHE18-LEHB18
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 LEHB19-LFB1219
	.uleb128 LEHE19-LEHB19
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 LEHB20-LFB1219
	.uleb128 LEHE20-LEHB20
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1219:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1273:
	pushl	%ebp
LCFI29:
	movl	%esp, %ebp
LCFI30:
	subl	$24, %esp
LCFI31:
	cmpl	$1, 8(%ebp)
	jne	L35
	cmpl	$65535, 12(%ebp)
	jne	L35
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
L35:
	cmpl	$0, 8(%ebp)
	jne	L34
	cmpl	$65535, 12(%ebp)
	jne	L34
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
L34:
	leave
LCFI32:
	ret
LFE1273:
	.def	__GLOBAL__I__ZN7MessageC2ESs;	.scl	3;	.type	32;	.endef
__GLOBAL__I__ZN7MessageC2ESs:
LFB1274:
	pushl	%ebp
LCFI33:
	movl	%esp, %ebp
LCFI34:
	subl	$24, %esp
LCFI35:
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
LCFI36:
	ret
LFE1274:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I__ZN7MessageC2ESs
	.text
	.def	__GLOBAL__D__ZN7MessageC2ESs;	.scl	3;	.type	32;	.endef
__GLOBAL__D__ZN7MessageC2ESs:
LFB1275:
	pushl	%ebp
LCFI37:
	movl	%esp, %ebp
LCFI38:
	subl	$24, %esp
LCFI39:
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
LCFI40:
	ret
LFE1275:
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D__ZN7MessageC2ESs
	.section	.eh_frame,"w"
Lframe1:
	.long	LECIE1-LSCIE1
LSCIE1:
	.long	0x0
	.byte	0x1
	.ascii "zPL\0"
	.uleb128 0x1
	.sleb128 -4
	.byte	0x8
	.uleb128 0x6
	.byte	0x0
	.long	___gxx_personality_v0
	.byte	0x0
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x88
	.uleb128 0x1
	.align 4
LECIE1:
LSFDE1:
	.long	LEFDE1-LASFDE1
LASFDE1:
	.long	LASFDE1-Lframe1
	.long	LFB1215
	.long	LFE1215-LFB1215
	.uleb128 0x4
	.long	LLSDA1215
	.byte	0x4
	.long	LCFI0-LFB1215
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI1-LCFI0
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI3-LCFI1
	.byte	0x83
	.uleb128 0x3
	.byte	0x4
	.long	LCFI4-LCFI3
	.byte	0xc3
	.byte	0x4
	.long	LCFI5-LCFI4
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE1:
LSFDE3:
	.long	LEFDE3-LASFDE3
LASFDE3:
	.long	LASFDE3-Lframe1
	.long	LFB1217
	.long	LFE1217-LFB1217
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	LCFI6-LFB1217
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI7-LCFI6
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI9-LCFI7
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE3:
LSFDE5:
	.long	LEFDE5-LASFDE5
LASFDE5:
	.long	LASFDE5-Lframe1
	.long	LFB1218
	.long	LFE1218-LFB1218
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	LCFI10-LFB1218
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI11-LCFI10
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI13-LCFI11
	.byte	0x83
	.uleb128 0x3
	.byte	0x4
	.long	LCFI14-LCFI13
	.byte	0xc3
	.byte	0x4
	.long	LCFI15-LCFI14
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE5:
LSFDE7:
	.long	LEFDE7-LASFDE7
LASFDE7:
	.long	LASFDE7-Lframe1
	.long	LFB1222
	.long	LFE1222-LFB1222
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	LCFI16-LFB1222
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI17-LCFI16
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI19-LCFI17
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE7:
LSFDE9:
	.long	LEFDE9-LASFDE9
LASFDE9:
	.long	LASFDE9-Lframe1
	.long	LFB1219
	.long	LFE1219-LFB1219
	.uleb128 0x4
	.long	LLSDA1219
	.byte	0x4
	.long	LCFI20-LFB1219
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI21-LCFI20
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI24-LCFI21
	.byte	0x10
	.byte	0x3
	.uleb128 0x8
	.byte	0x75
	.sleb128 0
	.byte	0x9
	.byte	0xf0
	.byte	0x1a
	.byte	0x9
	.byte	0xfc
	.byte	0x22
	.byte	0x4
	.long	LCFI25-LCFI24
	.byte	0xa
	.byte	0xc3
	.byte	0x4
	.long	LCFI26-LCFI25
	.byte	0xd
	.uleb128 0x4
	.byte	0x4
	.long	LCFI27-LCFI26
	.byte	0xc5
	.byte	0xe
	.uleb128 0x4
	.byte	0x4
	.long	LCFI28-LCFI27
	.byte	0xb
	.align 4
LEFDE9:
LSFDE11:
	.long	LEFDE11-LASFDE11
LASFDE11:
	.long	LASFDE11-Lframe1
	.long	LFB1273
	.long	LFE1273-LFB1273
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	LCFI29-LFB1273
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI30-LCFI29
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI32-LCFI30
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE11:
LSFDE13:
	.long	LEFDE13-LASFDE13
LASFDE13:
	.long	LASFDE13-Lframe1
	.long	LFB1274
	.long	LFE1274-LFB1274
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	LCFI33-LFB1274
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI34-LCFI33
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI36-LCFI34
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE13:
LSFDE15:
	.long	LEFDE15-LASFDE15
LASFDE15:
	.long	LASFDE15-Lframe1
	.long	LFB1275
	.long	LFE1275-LFB1275
	.uleb128 0x4
	.long	0x0
	.byte	0x4
	.long	LCFI37-LFB1275
	.byte	0xe
	.uleb128 0x8
	.byte	0x85
	.uleb128 0x2
	.byte	0x4
	.long	LCFI38-LCFI37
	.byte	0xd
	.uleb128 0x5
	.byte	0x4
	.long	LCFI40-LCFI38
	.byte	0xc5
	.byte	0xc
	.uleb128 0x4
	.uleb128 0x4
	.align 4
LEFDE15:
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsaSERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
