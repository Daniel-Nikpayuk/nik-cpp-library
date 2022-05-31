	.file	"main.cpp"
# GNU C++17 (Ubuntu 11.2.0-7ubuntu2) version 11.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.0, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O2 -std=c++17 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%llu\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB45:
	.cfi_startproc
	endbr64	
# main.cpp:275: 		printf("%llu\n", factorial(argc));
	movslq	%edi, %rdi	# tmp89, n
# main.cpp:274: 	{
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
# main.cpp:262: 		if (n == 0) return p;
	movl	$1, %edx	#, p
	testq	%rdi, %rdi	# n
	je	.L3	#,
	.p2align 4,,10
	.p2align 3
.L2:
# main.cpp:263: 		else        return pair_factorial(n-1, p*n);
	imulq	%rdi, %rdx	# n, p
# main.cpp:262: 		if (n == 0) return p;
	subq	$1, %rdi	#, n
	jne	.L2	#,
.L3:
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:112:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	leaq	.LC0(%rip), %rsi	#, tmp87
	movl	$1, %edi	#,
	xorl	%eax, %eax	#
	call	__printf_chk@PLT	#
# main.cpp:281: 	}
	xorl	%eax, %eax	#
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE45:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-7ubuntu2) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
