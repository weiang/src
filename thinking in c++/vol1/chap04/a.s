	.file	"a.c"
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.text
.globl _fun
	.def	_fun;	.scl	2;	.type	32;	.endef
_fun:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leave
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
