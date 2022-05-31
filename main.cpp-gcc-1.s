	.file	"main.cpp"
# GNU C++17 (Ubuntu 11.2.0-7ubuntu2) version 11.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.0, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O2 -std=c++17 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.text._ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_,"axG",@progbits,_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_,comdat
	.p2align 4
	.weak	_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_
	.type	_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_, @function
_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_:
.LFB59:
	.cfi_startproc
	endbr64	
	movq	(%rdi), %rcx	# MEM[(long long unsigned int &)t_4(D)], t__lsm.24
	movq	8(%rdi), %rdx	# MEM[(long long unsigned int &)t_4(D) + 8], t__lsm.25
# main.cpp:118: 			constexpr static tuple<T, Ts...> & result(tuple<T, Ts...> & t)
	movq	%rdi, %rax	# tmp89, t
.L3:
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rdx, %rcx	# t__lsm.25, t__lsm.24
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-1(%rdx), %rsi	#, _10
# main.cpp:154: 				if (cond) return label(t);
	cmpq	$1, %rdx	#, t__lsm.25
	jne	.L12	#,
.L2:
	movq	%rcx, (%rax)	# t__lsm.24, MEM[(long long unsigned int &)t_4(D)]
	movq	$0, 8(%rax)	#, MEM[(long long unsigned int &)t_4(D) + 8]
# main.cpp:123: 			}
	ret	
	.p2align 4,,10
	.p2align 3
.L12:
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rsi, %rcx	# _10, t__lsm.24
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-2(%rdx), %rsi	#, _18
# main.cpp:154: 				if (cond) return label(t);
	cmpq	$2, %rdx	#, t__lsm.25
	je	.L2	#,
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rsi, %rcx	# _18, t__lsm.24
# main.cpp:154: 				if (cond) return label(t);
	subq	$3, %rdx	#, t__lsm.25
	je	.L2	#,
	jmp	.L3	#
	.cfi_endproc
.LFE59:
	.size	_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_, .-_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%llu\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB74:
	.cfi_startproc
	endbr64	
	subq	$40, %rsp	#,
	.cfi_def_cfa_offset 48
# main.cpp:262: 		printf("%llu\n", factorial(argc));
	movslq	%edi, %rdi	# tmp99, _1
	movl	$1, %edx	#, _20
# main.cpp:261: 	{
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp101
	movq	%rax, 24(%rsp)	# tmp101, D.4355
	xorl	%eax, %eax	# tmp101
# main.cpp:89: 		constexpr tuple(const T & v, const Ts &... vs) : value(v), tuple<Ts...>(vs...) { }
	movq	%rdi, 8(%rsp)	# _1, MEM[(struct tuple *)&t].value
# main.cpp:154: 				if (cond) return label(t);
	testq	%rdi, %rdi	# _1
	jne	.L36	#,
.L14:
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:112:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	xorl	%eax, %eax	#
	leaq	.LC0(%rip), %rsi	#, tmp96
	movl	$1, %edi	#,
	call	__printf_chk@PLT	#
# main.cpp:268: 	}
	movq	24(%rsp), %rax	# D.4355, tmp102
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp102
	jne	.L37	#,
	xorl	%eax, %eax	#
	addq	$40, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L36:
	.cfi_restore_state
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-1(%rdi), %rax	#, _15
# main.cpp:120: 				tuple_value<O>(t) = f(tuple_value<Is>(t)...);
	movq	%rax, 8(%rsp)	# _15, MEM[(long long unsigned int &)&t + 8]
# main.cpp:154: 				if (cond) return label(t);
	testq	%rax, %rax	# _15
	je	.L14	#,
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rdi, %rax	# _1, _15
	movq	%rax, %rdx	# _15, _20
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-2(%rdi), %rax	#, _23
# main.cpp:120: 				tuple_value<O>(t) = f(tuple_value<Is>(t)...);
	movq	%rax, 8(%rsp)	# _23, MEM[(long long unsigned int &)&t + 8]
# main.cpp:154: 				if (cond) return label(t);
	testq	%rax, %rax	# _23
	je	.L14	#,
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rax, %rdx	# _23, _20
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-3(%rdi), %rax	#, _31
# main.cpp:120: 				tuple_value<O>(t) = f(tuple_value<Is>(t)...);
	movq	%rax, 8(%rsp)	# _31, MEM[(long long unsigned int &)&t + 8]
# main.cpp:154: 				if (cond) return label(t);
	testq	%rax, %rax	# _31
	je	.L14	#,
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rax, %rdx	# _31, _20
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-4(%rdi), %rax	#, _39
# main.cpp:120: 				tuple_value<O>(t) = f(tuple_value<Is>(t)...);
	movq	%rax, 8(%rsp)	# _39, MEM[(long long unsigned int &)&t + 8]
# main.cpp:154: 				if (cond) return label(t);
	testq	%rax, %rax	# _39
	je	.L14	#,
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rax, %rdx	# _39, _20
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	leaq	-5(%rdi), %rax	#, _47
# main.cpp:120: 				tuple_value<O>(t) = f(tuple_value<Is>(t)...);
	movq	%rax, 8(%rsp)	# _47, MEM[(long long unsigned int &)&t + 8]
# main.cpp:154: 				if (cond) return label(t);
	testq	%rax, %rax	# _47
	je	.L14	#,
# main.cpp:222: 	constexpr u_type multiply  (u_type m, u_type n) { return m*n; }
	imulq	%rax, %rdx	# _47, _20
# main.cpp:223: 	constexpr u_type decrement (u_type n)		{ return n-1; }
	subq	$6, %rdi	#, _55
# main.cpp:120: 				tuple_value<O>(t) = f(tuple_value<Is>(t)...);
	movq	%rdi, 8(%rsp)	# _55, MEM[(long long unsigned int &)&t + 8]
	movq	%rdx, (%rsp)	# _20, MEM[(long long unsigned int &)&t]
# main.cpp:154: 				if (cond) return label(t);
	je	.L14	#,
# main.cpp:155: 				else      return cont(t);
	movq	%rsp, %rdi	#, tmp95
	call	_ZN5_liftILt1EXadL_Z8multiplyyyEEN3nik6moduleILNS0_11TranslationE0ELNS0_6ModuleE1ELNS0_10PermissionE0EXadL_ZNS0_7Version5v_1_0EEELNS0_6VendorE0ELb1EE9auto_packIJLt0ELt1EEEEE6resultIXadL_ZNS_ILt0EXadL_Z9decrementyEENS8_IJLt0EEEEE6resultIXadL_ZN9Factorial5startER5tupleIJyyEEEEyJyEEERSG_IJT0_DpT1_EESN_EEyJyEEESN_SN_	#
# main.cpp:253: 		auto v = Factorial::start(t);
	movq	(%rax), %rdx	# MEM <long long unsigned int> [(const struct tuple &)_56], _20
# main.cpp:155: 				else      return cont(t);
	jmp	.L14	#
.L37:
# main.cpp:268: 	}
	call	__stack_chk_fail@PLT	#
	.cfi_endproc
.LFE74:
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
