	.file	"procedure_call_overhead_3.c"
	.section	.rodata
.LC0:
	.string	"w"
.LC1:
	.string	"%llu\n"
	.text
	.globl	writeLLUArray
	.type	writeLLUArray, @function
writeLLUArray:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movq	-24(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jb	.L3
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	writeLLUArray, .-writeLLUArray
	.globl	func
	.type	func, @function
func:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func, .-func
	.section	.rodata
.LC2:
	.string	"procedure_call_overhead_3.txt"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8032, %rsp
	movq	$0, -16(%rbp)
	movq	$0, -24(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L6
.L7:
#APP
# 16 "procedure_call_overhead_3.c" 1
	cpuid
# 0 "" 2
# 17 "procedure_call_overhead_3.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -32(%rbp)
	movl	%edx, -28(%rbp)
	movl	-28(%rbp), %eax
	salq	$32, %rax
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	orq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movl	-4(%rbp), %edx
	movl	-4(%rbp), %ecx
	movl	-4(%rbp), %eax
	movl	%ecx, %esi
	movl	%eax, %edi
	call	func
#APP
# 20 "procedure_call_overhead_3.c" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -32(%rbp)
	movl	%edx, -28(%rbp)
	movl	-28(%rbp), %eax
	salq	$32, %rax
	movq	%rax, %rdx
	movl	-32(%rbp), %eax
	orq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	subq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movq	%rdx, -8032(%rbp,%rax,8)
	addl	$1, -4(%rbp)
.L6:
	cmpl	$999, -4(%rbp)
	jle	.L7
	leaq	-8032(%rbp), %rax
	movl	$1000, %edx
	movq	%rax, %rsi
	movl	$.LC2, %edi
	call	writeLLUArray
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-7)"
	.section	.note.GNU-stack,"",@progbits
