	.text
	.file	"main.cpp"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
                                        # kill: def $edi killed $edi def $rdi
	testl	%edi, %edi
	je	.LBB0_1
# %bb.2:
	movslq	%edi, %rax
	leaq	-1(%rax), %rcx
	andl	$7, %edi
	cmpq	$7, %rcx
	jae	.LBB0_4
# %bb.3:
	movl	$1, %esi
	testq	%rdi, %rdi
	jne	.LBB0_8
	jmp	.LBB0_9
.LBB0_1:
	movl	$1, %esi
	jmp	.LBB0_9
.LBB0_4:
	movq	%rax, %r8
	andq	$-8, %r8
	negq	%r8
	movl	$1, %esi
	xorl	%edx, %edx
	.p2align	4, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	leaq	(%rax,%rdx), %rcx
	imulq	%rsi, %rcx
	leaq	(%rax,%rdx), %r9
	addq	$-1, %r9
	leaq	(%rax,%rdx), %rsi
	addq	$-2, %rsi
	imulq	%r9, %rsi
	imulq	%rcx, %rsi
	leaq	(%rax,%rdx), %r9
	addq	$-3, %r9
	leaq	(%rax,%rdx), %r10
	addq	$-4, %r10
	imulq	%r9, %r10
	leaq	(%rax,%rdx), %rcx
	addq	$-5, %rcx
	imulq	%r10, %rcx
	imulq	%rsi, %rcx
	leaq	(%rax,%rdx), %r9
	addq	$-6, %r9
	leaq	(%rax,%rdx), %rsi
	addq	$-7, %rsi
	imulq	%r9, %rsi
	imulq	%rcx, %rsi
	addq	$-8, %rdx
	cmpq	%rdx, %r8
	jne	.LBB0_5
# %bb.6:
	addq	%rdx, %rax
	testq	%rdi, %rdi
	je	.LBB0_9
	.p2align	4, 0x90
.LBB0_8:                                # =>This Inner Loop Header: Depth=1
	imulq	%rax, %rsi
	addq	$-1, %rax
	addq	$-1, %rdi
	jne	.LBB0_8
.LBB0_9:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$.L.str, %edi
	xorl	%eax, %eax
	callq	printf
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%llu\n"
	.size	.L.str, 6

	.ident	"Ubuntu clang version 13.0.0-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
