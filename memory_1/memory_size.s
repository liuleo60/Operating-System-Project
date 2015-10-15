	.file	"memory_size.c"
	.text
	.globl	getTime
	.type	getTime, @function
getTime:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
#APP
# 9 "../headers/rdtsc.h" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -4(%rbp)
	movl	%edx, -8(%rbp)
	movl	-8(%rbp), %eax
	salq	$32, %rax
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	orq	%rdx, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	getTime, .-getTime
	.section	.rodata
.LC0:
	.string	"w"
.LC1:
	.string	"%llu\n"
	.text
	.globl	writeLLUArray
	.type	writeLLUArray, @function
writeLLUArray:
.LFB3:
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
	jmp	.L4
.L5:
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
.L4:
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jb	.L5
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	writeLLUArray, .-writeLLUArray
	.section	.rodata
.LC2:
	.string	"%d\t%d\t%f\n"
	.text
	.globl	writeXYZ
	.type	writeXYZ, @function
writeXYZ:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movl	%esi, -60(%rbp)
	movl	%edx, -64(%rbp)
	movq	%rcx, -72(%rbp)
	movq	%r8, -80(%rbp)
	movq	%r9, -88(%rbp)
	movl	-64(%rbp), %ebx
	movslq	%ebx, %rax
	subq	$1, %rax
	movq	%rax, -32(%rbp)
	movslq	%ebx, %rax
	movq	%rax, %r10
	movl	$0, %r11d
	movq	-56(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -40(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L7
.L10:
	movl	$0, -24(%rbp)
	jmp	.L8
.L9:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movslq	%ebx, %rax
	imulq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	movq	-88(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	cltq
	movss	(%rdx,%rax,4), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-40(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	fprintf
	addl	$1, -24(%rbp)
.L8:
	movl	-24(%rbp), %eax
	cmpl	-64(%rbp), %eax
	jl	.L9
	addl	$1, -20(%rbp)
.L7:
	movl	-20(%rbp), %eax
	cmpl	-60(%rbp), %eax
	jl	.L10
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	writeXYZ, .-writeXYZ
	.section	.rodata
.LC3:
	.string	"%d\n"
.LC5:
	.string	"array_size = %ld \n"
.LC6:
	.string	"array_stride = %ld \n"
.LC8:
	.string	"memory_size.txt"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1696, %rsp
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	movl	-4(%rbp), %eax
	leal	11(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -160(%rbp,%rax,4)
	addl	$1, -4(%rbp)
.L12:
	cmpl	$17, -4(%rbp)
	jle	.L13
	movl	$0, -4(%rbp)
	jmp	.L14
.L15:
	movl	-4(%rbp), %eax
	leal	3(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -240(%rbp,%rax,4)
	addl	$1, -4(%rbp)
.L14:
	cmpl	$19, -4(%rbp)
	jle	.L15
	movl	$0, -4(%rbp)
	jmp	.L16
.L25:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	cltq
	movl	-240(%rbp,%rax,4), %eax
	cvtsi2sd	%eax, %xmm0
	movabsq	$4611686018427387904, %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -1688(%rbp)
	movsd	-1688(%rbp), %xmm0
	call	pow
	cvttsd2siq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	shrq	$3, %rax
	movq	%rax, -40(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L17
.L24:
	movl	-8(%rbp), %eax
	cltq
	movl	-160(%rbp,%rax,4), %eax
	cvtsi2sd	%eax, %xmm0
	movabsq	$4611686018427387904, %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -1688(%rbp)
	movsd	-1688(%rbp), %xmm0
	call	pow
	cvttsd2siq	%xmm0, %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	shrq	$3, %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rsi
	movl	$8, %edi
	call	calloc
	movq	%rax, -64(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-40(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -12(%rbp)
	jmp	.L18
.L19:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-64(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	cqto
	idivq	-56(%rbp)
	movq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, (%rcx)
	movq	-40(%rbp), %rax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
.L18:
	movl	-12(%rbp), %eax
	cltq
	cmpq	-56(%rbp), %rax
	jl	.L19
	movq	-64(%rbp), %rax
	movq	%rax, -24(%rbp)
	movl	$0, -12(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -80(%rbp)
	movl	$0, %eax
	call	getTime
	movq	%rax, -72(%rbp)
	jmp	.L20
.L21:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	addl	$1, -12(%rbp)
.L20:
	cmpl	$999999, -12(%rbp)
	jle	.L21
	movl	$0, %eax
	call	getTime
	movq	%rax, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rdx
	subq	%rax, %rdx
	movq	%rdx, %rax
	testq	%rax, %rax
	js	.L22
	cvtsi2sdq	%rax, %xmm0
	jmp	.L23
.L22:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L23:
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	unpcklpd	%xmm0, %xmm0
	cvtpd2ps	%xmm0, %xmm0
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	movss	%xmm0, -1680(%rbp,%rax,4)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	free
	addl	$1, -8(%rbp)
.L17:
	cmpl	$17, -8(%rbp)
	jle	.L24
	addl	$1, -4(%rbp)
.L16:
	cmpl	$19, -4(%rbp)
	jle	.L25
	leaq	-1680(%rbp), %rcx
	leaq	-160(%rbp), %rdx
	leaq	-240(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rcx
	movl	$18, %edx
	movl	$20, %esi
	movl	$.LC8, %edi
	call	writeXYZ
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC7:
	.long	0
	.long	1093567616
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-7)"
	.section	.note.GNU-stack,"",@progbits
