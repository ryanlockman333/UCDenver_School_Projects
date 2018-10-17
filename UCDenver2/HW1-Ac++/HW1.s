	.file	"HW1.cpp"
	.intel_syntax noprefix
	.section	.text._ZnwmPv,"axG",@progbits,_ZnwmPv,comdat
	.weak	_ZnwmPv
	.type	_ZnwmPv, @function
_ZnwmPv:
.LFB269:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-16]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE269:
	.size	_ZnwmPv, .-_ZnwmPv
	.section	.text._ZStanSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStanSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStanSt13_Ios_FmtflagsS_
	.type	_ZStanSt13_Ios_FmtflagsS_, @function
_ZStanSt13_Ios_FmtflagsS_:
.LFB589:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	mov	edx, DWORD PTR [rbp-4]
	mov	eax, DWORD PTR [rbp-8]
	and	eax, edx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE589:
	.size	_ZStanSt13_Ios_FmtflagsS_, .-_ZStanSt13_Ios_FmtflagsS_
	.section	.text._ZStorSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStorSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStorSt13_Ios_FmtflagsS_
	.type	_ZStorSt13_Ios_FmtflagsS_, @function
_ZStorSt13_Ios_FmtflagsS_:
.LFB590:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	mov	edx, DWORD PTR [rbp-4]
	mov	eax, DWORD PTR [rbp-8]
	or	eax, edx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE590:
	.size	_ZStorSt13_Ios_FmtflagsS_, .-_ZStorSt13_Ios_FmtflagsS_
	.section	.text._ZStcoSt13_Ios_Fmtflags,"axG",@progbits,_ZStcoSt13_Ios_Fmtflags,comdat
	.weak	_ZStcoSt13_Ios_Fmtflags
	.type	_ZStcoSt13_Ios_Fmtflags, @function
_ZStcoSt13_Ios_Fmtflags:
.LFB592:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	eax, DWORD PTR [rbp-4]
	not	eax
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE592:
	.size	_ZStcoSt13_Ios_Fmtflags, .-_ZStcoSt13_Ios_Fmtflags
	.section	.text._ZStoRRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStoRRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStoRRSt13_Ios_FmtflagsS_
	.type	_ZStoRRSt13_Ios_FmtflagsS_, @function
_ZStoRRSt13_Ios_FmtflagsS_:
.LFB593:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	DWORD PTR [rbp-12], esi
	mov	rax, QWORD PTR [rbp-8]
	mov	eax, DWORD PTR [rax]
	mov	edx, DWORD PTR [rbp-12]
	mov	esi, edx
	mov	edi, eax
	call	_ZStorSt13_Ios_FmtflagsS_
	mov	rdx, QWORD PTR [rbp-8]
	mov	DWORD PTR [rdx], eax
	mov	rax, QWORD PTR [rbp-8]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE593:
	.size	_ZStoRRSt13_Ios_FmtflagsS_, .-_ZStoRRSt13_Ios_FmtflagsS_
	.section	.text._ZStaNRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStaNRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStaNRSt13_Ios_FmtflagsS_
	.type	_ZStaNRSt13_Ios_FmtflagsS_, @function
_ZStaNRSt13_Ios_FmtflagsS_:
.LFB594:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	DWORD PTR [rbp-12], esi
	mov	rax, QWORD PTR [rbp-8]
	mov	eax, DWORD PTR [rax]
	mov	edx, DWORD PTR [rbp-12]
	mov	esi, edx
	mov	edi, eax
	call	_ZStanSt13_Ios_FmtflagsS_
	mov	rdx, QWORD PTR [rbp-8]
	mov	DWORD PTR [rdx], eax
	mov	rax, QWORD PTR [rbp-8]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE594:
	.size	_ZStaNRSt13_Ios_FmtflagsS_, .-_ZStaNRSt13_Ios_FmtflagsS_
	.section	.text._ZStorSt13_Ios_OpenmodeS_,"axG",@progbits,_ZStorSt13_Ios_OpenmodeS_,comdat
	.weak	_ZStorSt13_Ios_OpenmodeS_
	.type	_ZStorSt13_Ios_OpenmodeS_, @function
_ZStorSt13_Ios_OpenmodeS_:
.LFB597:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	mov	edx, DWORD PTR [rbp-4]
	mov	eax, DWORD PTR [rbp-8]
	or	eax, edx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE597:
	.size	_ZStorSt13_Ios_OpenmodeS_, .-_ZStorSt13_Ios_OpenmodeS_
	.section	.text._ZNSt8ios_base4setfESt13_Ios_Fmtflags,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_Fmtflags,comdat
	.align 2
	.weak	_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	.type	_ZNSt8ios_base4setfESt13_Ios_Fmtflags, @function
_ZNSt8ios_base4setfESt13_Ios_Fmtflags:
.LFB620:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-24], rdi
	mov	DWORD PTR [rbp-28], esi
	mov	rax, QWORD PTR [rbp-24]
	mov	eax, DWORD PTR [rax+24]
	mov	DWORD PTR [rbp-4], eax
	mov	rax, QWORD PTR [rbp-24]
	lea	rdx, [rax+24]
	mov	eax, DWORD PTR [rbp-28]
	mov	esi, eax
	mov	rdi, rdx
	call	_ZStoRRSt13_Ios_FmtflagsS_
	mov	eax, DWORD PTR [rbp-4]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE620:
	.size	_ZNSt8ios_base4setfESt13_Ios_Fmtflags, .-_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	.section	.text._ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,comdat
	.align 2
	.weak	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.type	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, @function
_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_:
.LFB621:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-24], rdi
	mov	DWORD PTR [rbp-28], esi
	mov	DWORD PTR [rbp-32], edx
	mov	rax, QWORD PTR [rbp-24]
	mov	eax, DWORD PTR [rax+24]
	mov	DWORD PTR [rbp-4], eax
	mov	eax, DWORD PTR [rbp-32]
	mov	edi, eax
	call	_ZStcoSt13_Ios_Fmtflags
	mov	rdx, QWORD PTR [rbp-24]
	add	rdx, 24
	mov	esi, eax
	mov	rdi, rdx
	call	_ZStaNRSt13_Ios_FmtflagsS_
	mov	edx, DWORD PTR [rbp-32]
	mov	eax, DWORD PTR [rbp-28]
	mov	esi, edx
	mov	edi, eax
	call	_ZStanSt13_Ios_FmtflagsS_
	mov	rdx, QWORD PTR [rbp-24]
	add	rdx, 24
	mov	esi, eax
	mov	rdi, rdx
	call	_ZStoRRSt13_Ios_FmtflagsS_
	mov	eax, DWORD PTR [rbp-4]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE621:
	.size	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, .-_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.section	.text._ZSt9showpointRSt8ios_base,"axG",@progbits,_ZSt9showpointRSt8ios_base,comdat
	.weak	_ZSt9showpointRSt8ios_base
	.type	_ZSt9showpointRSt8ios_base, @function
_ZSt9showpointRSt8ios_base:
.LFB635:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, 1024
	mov	rdi, rax
	call	_ZNSt8ios_base4setfESt13_Ios_Fmtflags
	mov	rax, QWORD PTR [rbp-8]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE635:
	.size	_ZSt9showpointRSt8ios_base, .-_ZSt9showpointRSt8ios_base
	.section	.text._ZSt5fixedRSt8ios_base,"axG",@progbits,_ZSt5fixedRSt8ios_base,comdat
	.weak	_ZSt5fixedRSt8ios_base
	.type	_ZSt5fixedRSt8ios_base, @function
_ZSt5fixedRSt8ios_base:
.LFB651:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	edx, 260
	mov	esi, 4
	mov	rdi, rax
	call	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	mov	rax, QWORD PTR [rbp-8]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE651:
	.size	_ZSt5fixedRSt8ios_base, .-_ZSt5fixedRSt8ios_base
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZSt12setprecisioni,"axG",@progbits,_ZSt12setprecisioni,comdat
	.weak	_ZSt12setprecisioni
	.type	_ZSt12setprecisioni, @function
_ZSt12setprecisioni:
.LFB1246:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	eax, DWORD PTR [rbp-4]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1246:
	.size	_ZSt12setprecisioni, .-_ZSt12setprecisioni
	.section	.rodata
.LC0:
	.string	"YES"
.LC1:
	.string	"Yes"
.LC2:
	.string	"yes"
.LC3:
	.string	"SURE"
.LC4:
	.string	"Sure"
.LC5:
	.string	"sure"
.LC6:
	.string	"OK"
.LC7:
	.string	"Ok"
.LC8:
	.string	"ok"
.LC9:
	.string	"Y"
.LC10:
	.string	"y"
.LC11:
	.string	"NO"
.LC12:
	.string	"No"
.LC13:
	.string	"no"
.LC14:
	.string	"QUIT"
.LC15:
	.string	"Quit"
.LC16:
	.string	"quit"
.LC17:
	.string	"STOP"
.LC18:
	.string	"Stop"
.LC19:
	.string	"stop"
.LC20:
	.string	"TERMINATE"
.LC21:
	.string	"Terminate"
.LC22:
	.string	"terminate"
.LC23:
	.string	"N"
.LC24:
	.string	"n"
	.text
	.globl	_Z8promptYNSs
	.type	_Z8promptYNSs, @function
_Z8promptYNSs:
.LFB1352:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC0
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC1
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC2
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC3
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC4
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC5
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC6
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC7
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC8
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC9
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L26
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC10
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	je	.L27
.L26:
	mov	eax, 1
	jmp	.L28
.L27:
	mov	eax, 0
.L28:
	test	al, al
	je	.L29
	mov	eax, 1
	jmp	.L30
.L29:
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC11
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC12
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC13
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC14
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC15
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC16
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC17
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC18
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC19
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC20
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC21
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC22
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC23
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	jne	.L31
	mov	rax, QWORD PTR [rbp-8]
	mov	esi, OFFSET FLAT:.LC24
	mov	rdi, rax
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	test	al, al
	je	.L32
.L31:
	mov	eax, 1
	jmp	.L33
.L32:
	mov	eax, 0
.L33:
	test	al, al
	je	.L34
	mov	eax, 0
	jmp	.L30
.L34:
	mov	eax, 0
.L30:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1352:
	.size	_Z8promptYNSs, .-_Z8promptYNSs
	.section	.rodata
.LC26:
	.string	"-h"
.LC27:
	.string	"\nUsage: "
.LC28:
	.string	" [file path]\n\n"
	.align 8
.LC29:
	.string	"\nError, opening file for reading.\n\n"
.LC30:
	.string	"\nWelcome!"
	.align 8
.LC31:
	.string	"\nThis program calculates an interpolating polynomial to the desired x.\n"
.LC32:
	.string	"\nContinue?: "
	.align 8
.LC33:
	.string	"\nPlease, enter the desired X value:  "
.LC34:
	.string	"\nP("
.LC35:
	.string	") = "
.LC36:
	.string	"\n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1353:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1353
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r12
	push	rbx
	sub	rsp, 112
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	mov	DWORD PTR [rbp-116], edi
	mov	QWORD PTR [rbp-128], rsi
	lea	rax, [rbp-64]
	mov	rdi, rax
.LEHB0:
	call	_ZNSt6vectorIfSaIfEEC1Ev
.LEHE0:
	lea	rax, [rbp-96]
	mov	rdi, rax
.LEHB1:
	call	_ZNSt6vectorIfSaIfEEC1Ev
.LEHE1:
	mov	eax, DWORD PTR .LC25[rip]
	mov	DWORD PTR [rbp-100], eax
	lea	rax, [rbp-112]
	mov	rdi, rax
.LEHB2:
	call	_ZNSsC1Ev
.LEHE2:
	cmp	DWORD PTR [rbp-116], 2
	jne	.L36
	mov	rax, QWORD PTR [rbp-128]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	mov	esi, OFFSET FLAT:.LC26
	mov	rdi, rax
	call	strcmp
	test	eax, eax
	jne	.L37
.L36:
	mov	rax, QWORD PTR [rbp-128]
	mov	rbx, QWORD PTR [rax]
	mov	esi, OFFSET FLAT:.LC27
	mov	edi, OFFSET FLAT:_ZSt4cout
.LEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	rsi, rbx
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, OFFSET FLAT:.LC28
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	ebx, 1
	jmp	.L38
.L37:
	mov	rax, QWORD PTR [rbp-128]
	add	rax, 8
	mov	rax, QWORD PTR [rax]
	lea	rdx, [rbp-96]
	lea	rcx, [rbp-64]
	mov	rsi, rcx
	mov	rdi, rax
	call	_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_
	mov	DWORD PTR [rbp-20], eax
	cmp	DWORD PTR [rbp-20], -1
	jne	.L39
	mov	esi, OFFSET FLAT:.LC29
	mov	edi, OFFSET FLAT:_ZSt4cerr
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	ebx, 1
	jmp	.L38
.L39:
	mov	esi, OFFSET FLAT:.LC30
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, OFFSET FLAT:.LC31
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, OFFSET FLAT:.LC32
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	rax, [rbp-112]
	mov	rsi, rax
	mov	edi, OFFSET FLAT:_ZSt3cin
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	lea	rdx, [rbp-112]
	lea	rax, [rbp-32]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNSsC1ERKSs
.LEHE3:
	lea	rax, [rbp-32]
	mov	rdi, rax
.LEHB4:
	call	_Z8promptYNSs
.LEHE4:
	mov	ebx, eax
	xor	ebx, 1
	lea	rax, [rbp-32]
	mov	rdi, rax
.LEHB5:
	call	_ZNSsD1Ev
	test	bl, bl
	je	.L40
	mov	ebx, 0
	jmp	.L38
.L40:
	mov	esi, OFFSET FLAT:.LC33
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	rax, [rbp-100]
	mov	rsi, rax
	mov	edi, OFFSET FLAT:_ZSt3cin
	call	_ZNSirsERf
	mov	eax, DWORD PTR [rbp-100]
	mov	edx, DWORD PTR [rbp-20]
	lea	rsi, [rbp-96]
	lea	rcx, [rbp-64]
	mov	DWORD PTR [rbp-120], eax
	movss	xmm0, DWORD PTR [rbp-120]
	mov	rdi, rcx
	call	_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_
	movss	DWORD PTR [rbp-120], xmm0
	mov	eax, DWORD PTR [rbp-120]
	mov	DWORD PTR [rbp-24], eax
	mov	ebx, DWORD PTR [rbp-100]
	mov	edi, 1
	call	_ZSt12setprecisioni
	mov	r12d, eax
	mov	esi, OFFSET FLAT:_ZSt5fixedRSt8ios_base
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZNSolsEPFRSt8ios_baseS0_E
	mov	esi, OFFSET FLAT:_ZSt9showpointRSt8ios_base
	mov	rdi, rax
	call	_ZNSolsEPFRSt8ios_baseS0_E
	mov	esi, r12d
	mov	rdi, rax
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision
	mov	esi, OFFSET FLAT:.LC34
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-120], ebx
	movss	xmm0, DWORD PTR [rbp-120]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC35
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	rdx, rax
	mov	eax, DWORD PTR [rbp-24]
	mov	DWORD PTR [rbp-120], eax
	movss	xmm0, DWORD PTR [rbp-120]
	mov	rdi, rdx
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC36
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.LEHE5:
	mov	ebx, 0
.L38:
	lea	rax, [rbp-112]
	mov	rdi, rax
.LEHB6:
	call	_ZNSsD1Ev
.LEHE6:
	lea	rax, [rbp-96]
	mov	rdi, rax
.LEHB7:
	call	_ZNSt6vectorIfSaIfEED1Ev
.LEHE7:
	lea	rax, [rbp-64]
	mov	rdi, rax
.LEHB8:
	call	_ZNSt6vectorIfSaIfEED1Ev
.LEHE8:
	mov	eax, ebx
	jmp	.L52
.L51:
	mov	rbx, rax
	lea	rax, [rbp-32]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L43
.L50:
	mov	rbx, rax
.L43:
	lea	rax, [rbp-112]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L44
.L49:
	mov	rbx, rax
.L44:
	lea	rax, [rbp-96]
	mov	rdi, rax
	call	_ZNSt6vectorIfSaIfEED1Ev
	jmp	.L45
.L48:
	mov	rbx, rax
.L45:
	lea	rax, [rbp-64]
	mov	rdi, rax
	call	_ZNSt6vectorIfSaIfEED1Ev
	mov	rax, rbx
	jmp	.L46
.L47:
.L46:
	mov	rdi, rax
.LEHB9:
	call	_Unwind_Resume
.LEHE9:
.L52:
	add	rsp, 112
	pop	rbx
	pop	r12
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1353:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1353:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1353-.LLSDACSB1353
.LLSDACSB1353:
	.uleb128 .LEHB0-.LFB1353
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L47-.LFB1353
	.uleb128 0
	.uleb128 .LEHB1-.LFB1353
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L48-.LFB1353
	.uleb128 0
	.uleb128 .LEHB2-.LFB1353
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L49-.LFB1353
	.uleb128 0
	.uleb128 .LEHB3-.LFB1353
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L50-.LFB1353
	.uleb128 0
	.uleb128 .LEHB4-.LFB1353
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L51-.LFB1353
	.uleb128 0
	.uleb128 .LEHB5-.LFB1353
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L50-.LFB1353
	.uleb128 0
	.uleb128 .LEHB6-.LFB1353
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L49-.LFB1353
	.uleb128 0
	.uleb128 .LEHB7-.LFB1353
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L48-.LFB1353
	.uleb128 0
	.uleb128 .LEHB8-.LFB1353
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L47-.LFB1353
	.uleb128 0
	.uleb128 .LEHB9-.LFB1353
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
.LLSDACSE1353:
	.text
	.size	main, .-main
	.section	.text._ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_,"axG",@progbits,_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_,comdat
	.weak	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	.type	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_, @function
_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_:
.LFB1355:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSs7compareEPKc
	test	eax, eax
	sete	al
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1355:
	.size	_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_, .-_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	.section	.text._ZNSt6vectorIfSaIfEEC2Ev,"axG",@progbits,_ZNSt6vectorIfSaIfEEC5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIfSaIfEEC2Ev
	.type	_ZNSt6vectorIfSaIfEEC2Ev, @function
_ZNSt6vectorIfSaIfEEC2Ev:
.LFB1357:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEEC2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1357:
	.size	_ZNSt6vectorIfSaIfEEC2Ev, .-_ZNSt6vectorIfSaIfEEC2Ev
	.weak	_ZNSt6vectorIfSaIfEEC1Ev
	.set	_ZNSt6vectorIfSaIfEEC1Ev,_ZNSt6vectorIfSaIfEEC2Ev
	.section	.text._ZNSt6vectorIfSaIfEED2Ev,"axG",@progbits,_ZNSt6vectorIfSaIfEED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIfSaIfEED2Ev
	.type	_ZNSt6vectorIfSaIfEED2Ev, @function
_ZNSt6vectorIfSaIfEED2Ev:
.LFB1360:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1360
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 24
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-24], rdi
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rax+8]
	mov	rax, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rax]
	mov	rsi, rcx
	mov	rdi, rax
.LEHB10:
	call	_ZSt8_DestroyIPffEvT_S1_RSaIT0_E
.LEHE10:
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
.LEHB11:
	call	_ZNSt12_Vector_baseIfSaIfEED2Ev
.LEHE11:
	jmp	.L60
.L59:
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEED2Ev
	mov	rax, rbx
	mov	rdi, rax
.LEHB12:
	call	_Unwind_Resume
.LEHE12:
.L60:
	add	rsp, 24
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1360:
	.section	.gcc_except_table
.LLSDA1360:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1360-.LLSDACSB1360
.LLSDACSB1360:
	.uleb128 .LEHB10-.LFB1360
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L59-.LFB1360
	.uleb128 0
	.uleb128 .LEHB11-.LFB1360
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB12-.LFB1360
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE1360:
	.section	.text._ZNSt6vectorIfSaIfEED2Ev,"axG",@progbits,_ZNSt6vectorIfSaIfEED5Ev,comdat
	.size	_ZNSt6vectorIfSaIfEED2Ev, .-_ZNSt6vectorIfSaIfEED2Ev
	.weak	_ZNSt6vectorIfSaIfEED1Ev
	.set	_ZNSt6vectorIfSaIfEED1Ev,_ZNSt6vectorIfSaIfEED2Ev
	.section	.text._Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_,"axG",@progbits,_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_,comdat
	.weak	_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_
	.type	_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_, @function
_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_:
.LFB1372:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1372
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 600
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-584], rdi
	mov	QWORD PTR [rbp-592], rsi
	mov	QWORD PTR [rbp-600], rdx
	mov	rcx, QWORD PTR [rbp-584]
	lea	rax, [rbp-576]
	mov	edx, 8
	mov	rsi, rcx
	mov	rdi, rax
.LEHB13:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
.LEHE13:
	lea	rax, [rbp-576]
	add	rax, 256
	mov	rdi, rax
.LEHB14:
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEntEv
	test	al, al
	je	.L62
	mov	ebx, -1
	jmp	.L63
.L62:
	lea	rax, [rbp-48]
	mov	rdi, rax
	call	_ZNSsC1Ev
.LEHE14:
	mov	DWORD PTR [rbp-20], 0
	jmp	.L64
.L67:
	lea	rcx, [rbp-48]
	lea	rax, [rbp-576]
	mov	edx, 32
	mov	rsi, rcx
	mov	rdi, rax
.LEHB15:
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_ES4_
	lea	rax, [rbp-48]
	mov	rdi, rax
	call	_ZNKSs5c_strEv
.LEHE15:
	mov	rdi, rax
	call	atof
	unpcklpd	xmm0, xmm0
	cvtpd2ps	xmm0, xmm0
	movss	DWORD PTR [rbp-28], xmm0
	lea	rdx, [rbp-28]
	mov	rax, QWORD PTR [rbp-592]
	mov	rsi, rdx
	mov	rdi, rax
.LEHB16:
	call	_ZNSt6vectorIfSaIfEE9push_backERKf
.LEHE16:
	lea	rcx, [rbp-48]
	lea	rax, [rbp-576]
	mov	edx, 10
	mov	rsi, rcx
	mov	rdi, rax
.LEHB17:
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_ES4_
	lea	rax, [rbp-48]
	mov	rdi, rax
	call	_ZNKSs5c_strEv
.LEHE17:
	mov	rdi, rax
	call	atof
	unpcklpd	xmm0, xmm0
	cvtpd2ps	xmm0, xmm0
	movss	DWORD PTR [rbp-24], xmm0
	lea	rdx, [rbp-24]
	mov	rax, QWORD PTR [rbp-600]
	mov	rsi, rdx
	mov	rdi, rax
.LEHB18:
	call	_ZNSt6vectorIfSaIfEE9push_backERKf
.LEHE18:
	add	DWORD PTR [rbp-20], 1
.L64:
	lea	rax, [rbp-576]
	add	rax, 256
	mov	rdi, rax
.LEHB19:
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEE4goodEv
	test	al, al
	je	.L65
	lea	rax, [rbp-576]
	mov	rdi, rax
	call	_ZNSi4peekEv
.LEHE19:
	cmp	eax, -1
	je	.L65
	mov	eax, 1
	jmp	.L66
.L65:
	mov	eax, 0
.L66:
	test	al, al
	jne	.L67
	mov	ebx, DWORD PTR [rbp-20]
	lea	rax, [rbp-48]
	mov	rdi, rax
.LEHB20:
	call	_ZNSsD1Ev
.LEHE20:
.L63:
	lea	rax, [rbp-576]
	mov	rdi, rax
.LEHB21:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
.LEHE21:
	mov	eax, ebx
	jmp	.L79
.L77:
	mov	rbx, rax
	jmp	.L70
.L78:
	mov	rbx, rax
	jmp	.L70
.L76:
	mov	rbx, rax
.L70:
	lea	rax, [rbp-48]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L72
.L75:
	mov	rbx, rax
.L72:
	lea	rax, [rbp-576]
	mov	rdi, rax
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	mov	rax, rbx
	jmp	.L73
.L74:
.L73:
	mov	rdi, rax
.LEHB22:
	call	_Unwind_Resume
.LEHE22:
.L79:
	add	rsp, 600
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1372:
	.section	.gcc_except_table
.LLSDA1372:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1372-.LLSDACSB1372
.LLSDACSB1372:
	.uleb128 .LEHB13-.LFB1372
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L74-.LFB1372
	.uleb128 0
	.uleb128 .LEHB14-.LFB1372
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L75-.LFB1372
	.uleb128 0
	.uleb128 .LEHB15-.LFB1372
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L76-.LFB1372
	.uleb128 0
	.uleb128 .LEHB16-.LFB1372
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L77-.LFB1372
	.uleb128 0
	.uleb128 .LEHB17-.LFB1372
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L76-.LFB1372
	.uleb128 0
	.uleb128 .LEHB18-.LFB1372
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L78-.LFB1372
	.uleb128 0
	.uleb128 .LEHB19-.LFB1372
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L76-.LFB1372
	.uleb128 0
	.uleb128 .LEHB20-.LFB1372
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L75-.LFB1372
	.uleb128 0
	.uleb128 .LEHB21-.LFB1372
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L74-.LFB1372
	.uleb128 0
	.uleb128 .LEHB22-.LFB1372
	.uleb128 .LEHE22-.LEHB22
	.uleb128 0
	.uleb128 0
.LLSDACSE1372:
	.section	.text._Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_,"axG",@progbits,_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_,comdat
	.size	_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_, .-_Z9fillArrayISt6vectorIfSaIfEEEiPKcRT_S6_
	.section	.rodata
.LC38:
	.string	"P"
.LC39:
	.string	"(x)="
.LC40:
	.string	"(x+"
.LC41:
	.string	")/("
.LC42:
	.string	"+"
.LC43:
	.string	")"
.LC44:
	.string	"(x-"
.LC45:
	.string	"-"
.LC46:
	.string	" "
.LC47:
	.string	"\n"
	.section	.text._Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_,"axG",@progbits,_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_,comdat
	.weak	_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_
	.type	_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_, @function
_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_:
.LFB1374:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1374
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r13
	push	r12
	push	rbx
	sub	rsp, 520
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	mov	QWORD PTR [rbp-504], rdi
	mov	QWORD PTR [rbp-512], rsi
	mov	DWORD PTR [rbp-516], edx
	movss	DWORD PTR [rbp-520], xmm0
	mov	eax, DWORD PTR .LC25[rip]
	mov	DWORD PTR [rbp-36], eax
	mov	eax, DWORD PTR .LC37[rip]
	mov	DWORD PTR [rbp-40], eax
	mov	esi, 8
	mov	edi, 16
	call	_ZStorSt13_Ios_OpenmodeS_
	mov	edx, eax
	lea	rax, [rbp-496]
	mov	esi, edx
	mov	rdi, rax
.LEHB23:
	call	_ZNSt18basic_stringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode
.LEHE23:
	lea	rax, [rbp-80]
	mov	rdi, rax
.LEHB24:
	call	_ZNSsC1Ev
.LEHE24:
	lea	rax, [rbp-96]
	mov	rdi, rax
.LEHB25:
	call	_ZNSsC1Ev
.LEHE25:
	lea	rax, [rbp-112]
	mov	rdi, rax
.LEHB26:
	call	_ZNSsC1Ev
.LEHE26:
	lea	rax, [rbp-128]
	mov	rdi, rax
.LEHB27:
	call	_ZNSsC1Ev
.LEHE27:
	lea	rax, [rbp-496]
	add	rax, 16
	mov	esi, OFFSET FLAT:.LC38
	mov	rdi, rax
.LEHB28:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	edx, DWORD PTR [rbp-516]
	mov	esi, edx
	mov	rdi, rax
	call	_ZNSolsEj
	mov	esi, OFFSET FLAT:.LC39
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	rdx, [rbp-128]
	lea	rax, [rbp-496]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	lea	rax, [rbp-496]
	add	rax, 104
	mov	esi, 0
	mov	rdi, rax
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate
	mov	DWORD PTR [rbp-44], 0
	jmp	.L81
.L92:
	mov	DWORD PTR [rbp-48], 0
	jmp	.L82
.L86:
	mov	eax, DWORD PTR [rbp-48]
	cmp	eax, DWORD PTR [rbp-44]
	je	.L83
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	movss	xmm1, DWORD PTR [rax]
	movss	xmm0, DWORD PTR [rbp-520]
	movaps	xmm2, xmm0
	subss	xmm2, xmm1
	movss	DWORD PTR [rbp-524], xmm2
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	movss	xmm0, DWORD PTR [rax]
	movss	DWORD PTR [rbp-528], xmm0
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	movss	xmm0, DWORD PTR [rax]
	movss	xmm1, DWORD PTR [rbp-528]
	subss	xmm1, xmm0
	movaps	xmm0, xmm1
	movss	xmm2, DWORD PTR [rbp-524]
	divss	xmm2, xmm0
	movaps	xmm0, xmm2
	movss	xmm1, DWORD PTR [rbp-40]
	mulss	xmm0, xmm1
	movss	DWORD PTR [rbp-40], xmm0
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	movss	xmm1, DWORD PTR [rax]
	xorps	xmm0, xmm0
	ucomiss	xmm0, xmm1
	seta	al
	test	al, al
	je	.L84
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	ebx, DWORD PTR [rax]
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	r12d, DWORD PTR [rax]
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	r13d, DWORD PTR [rax]
	lea	rax, [rbp-496]
	add	rax, 16
	mov	esi, OFFSET FLAT:.LC40
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], r13d
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC41
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], r12d
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC42
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], ebx
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC43
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	jmp	.L85
.L84:
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	ebx, DWORD PTR [rax]
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	r12d, DWORD PTR [rax]
	mov	edx, DWORD PTR [rbp-48]
	mov	rax, QWORD PTR [rbp-504]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	r13d, DWORD PTR [rax]
	lea	rax, [rbp-496]
	add	rax, 16
	mov	esi, OFFSET FLAT:.LC44
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], r13d
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC41
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], r12d
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC45
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], ebx
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	mov	esi, OFFSET FLAT:.LC43
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.L85:
	lea	rdx, [rbp-80]
	lea	rax, [rbp-496]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	lea	rax, [rbp-64]
	lea	rcx, [rbp-80]
	mov	edx, OFFSET FLAT:.LC46
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
.LEHE28:
	lea	rdx, [rbp-64]
	lea	rax, [rbp-112]
	mov	rsi, rdx
	mov	rdi, rax
.LEHB29:
	call	_ZNSspLERKSs
.LEHE29:
	lea	rax, [rbp-64]
	mov	rdi, rax
.LEHB30:
	call	_ZNSsD1Ev
	lea	rax, [rbp-496]
	add	rax, 104
	mov	esi, 0
	mov	rdi, rax
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate
.L83:
	add	DWORD PTR [rbp-48], 1
.L82:
	mov	eax, DWORD PTR [rbp-48]
	cmp	eax, DWORD PTR [rbp-516]
	setb	al
	test	al, al
	jne	.L86
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-512]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-512]
	mov	esi, 0
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	cmp	rbx, rax
	je	.L87
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-512]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	movss	xmm0, DWORD PTR [rax]
	xorps	xmm1, xmm1
	ucomiss	xmm0, xmm1
	jbe	.L87
.L108:
	mov	eax, 1
	jmp	.L89
.L87:
	mov	eax, 0
.L89:
	test	al, al
	je	.L90
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-512]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	ebx, DWORD PTR [rax]
	lea	rax, [rbp-496]
	add	rax, 16
	mov	esi, OFFSET FLAT:.LC42
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	DWORD PTR [rbp-532], ebx
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rax
	call	_ZNSolsEf
	lea	rdx, [rbp-80]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	jmp	.L91
.L90:
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-512]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	mov	eax, DWORD PTR [rax]
	lea	rdx, [rbp-496]
	add	rdx, 16
	mov	DWORD PTR [rbp-532], eax
	movss	xmm0, DWORD PTR [rbp-532]
	mov	rdi, rdx
	call	_ZNSolsEf
	lea	rdx, [rbp-80]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
.L91:
	lea	rdx, [rbp-96]
	lea	rax, [rbp-496]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	lea	rdx, [rbp-96]
	lea	rax, [rbp-128]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNSspLERKSs
	lea	rax, [rbp-496]
	add	rax, 104
	mov	esi, 0
	mov	rdi, rax
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate
	mov	edx, DWORD PTR [rbp-44]
	mov	rax, QWORD PTR [rbp-512]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE2atEm
	movss	xmm0, DWORD PTR [rax]
	mulss	xmm0, DWORD PTR [rbp-40]
	movss	xmm1, DWORD PTR [rbp-36]
	addss	xmm0, xmm1
	movss	DWORD PTR [rbp-36], xmm0
	add	DWORD PTR [rbp-44], 1
	mov	eax, DWORD PTR .LC37[rip]
	mov	DWORD PTR [rbp-40], eax
.L81:
	mov	eax, DWORD PTR [rbp-44]
	cmp	eax, DWORD PTR [rbp-516]
	setb	al
	test	al, al
	jne	.L92
	mov	esi, OFFSET FLAT:.LC47
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	lea	rdx, [rbp-128]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	mov	esi, OFFSET FLAT:.LC47
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
.LEHE30:
	mov	ebx, DWORD PTR [rbp-36]
	lea	rax, [rbp-128]
	mov	rdi, rax
.LEHB31:
	call	_ZNSsD1Ev
.LEHE31:
	lea	rax, [rbp-112]
	mov	rdi, rax
.LEHB32:
	call	_ZNSsD1Ev
.LEHE32:
	lea	rax, [rbp-96]
	mov	rdi, rax
.LEHB33:
	call	_ZNSsD1Ev
.LEHE33:
	lea	rax, [rbp-80]
	mov	rdi, rax
.LEHB34:
	call	_ZNSsD1Ev
.LEHE34:
	lea	rax, [rbp-496]
	mov	rdi, rax
.LEHB35:
	call	_ZNSt18basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev
.LEHE35:
	mov	eax, ebx
	jmp	.L109
.L107:
	mov	rbx, rax
	lea	rax, [rbp-64]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L95
.L106:
	mov	rbx, rax
.L95:
	lea	rax, [rbp-128]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L96
.L105:
	mov	rbx, rax
.L96:
	lea	rax, [rbp-112]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L97
.L104:
	mov	rbx, rax
.L97:
	lea	rax, [rbp-96]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L98
.L103:
	mov	rbx, rax
.L98:
	lea	rax, [rbp-80]
	mov	rdi, rax
	call	_ZNSsD1Ev
	jmp	.L99
.L102:
	mov	rbx, rax
.L99:
	lea	rax, [rbp-496]
	mov	rdi, rax
	call	_ZNSt18basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev
	mov	rax, rbx
	jmp	.L100
.L101:
.L100:
	mov	rdi, rax
.LEHB36:
	call	_Unwind_Resume
.LEHE36:
.L109:
	mov	DWORD PTR [rbp-532], eax
	movss	xmm0, DWORD PTR [rbp-532]
	add	rsp, 520
	pop	rbx
	pop	r12
	pop	r13
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1374:
	.section	.gcc_except_table
.LLSDA1374:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1374-.LLSDACSB1374
.LLSDACSB1374:
	.uleb128 .LEHB23-.LFB1374
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L101-.LFB1374
	.uleb128 0
	.uleb128 .LEHB24-.LFB1374
	.uleb128 .LEHE24-.LEHB24
	.uleb128 .L102-.LFB1374
	.uleb128 0
	.uleb128 .LEHB25-.LFB1374
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L103-.LFB1374
	.uleb128 0
	.uleb128 .LEHB26-.LFB1374
	.uleb128 .LEHE26-.LEHB26
	.uleb128 .L104-.LFB1374
	.uleb128 0
	.uleb128 .LEHB27-.LFB1374
	.uleb128 .LEHE27-.LEHB27
	.uleb128 .L105-.LFB1374
	.uleb128 0
	.uleb128 .LEHB28-.LFB1374
	.uleb128 .LEHE28-.LEHB28
	.uleb128 .L106-.LFB1374
	.uleb128 0
	.uleb128 .LEHB29-.LFB1374
	.uleb128 .LEHE29-.LEHB29
	.uleb128 .L107-.LFB1374
	.uleb128 0
	.uleb128 .LEHB30-.LFB1374
	.uleb128 .LEHE30-.LEHB30
	.uleb128 .L106-.LFB1374
	.uleb128 0
	.uleb128 .LEHB31-.LFB1374
	.uleb128 .LEHE31-.LEHB31
	.uleb128 .L105-.LFB1374
	.uleb128 0
	.uleb128 .LEHB32-.LFB1374
	.uleb128 .LEHE32-.LEHB32
	.uleb128 .L104-.LFB1374
	.uleb128 0
	.uleb128 .LEHB33-.LFB1374
	.uleb128 .LEHE33-.LEHB33
	.uleb128 .L103-.LFB1374
	.uleb128 0
	.uleb128 .LEHB34-.LFB1374
	.uleb128 .LEHE34-.LEHB34
	.uleb128 .L102-.LFB1374
	.uleb128 0
	.uleb128 .LEHB35-.LFB1374
	.uleb128 .LEHE35-.LEHB35
	.uleb128 .L101-.LFB1374
	.uleb128 0
	.uleb128 .LEHB36-.LFB1374
	.uleb128 .LEHE36-.LEHB36
	.uleb128 0
	.uleb128 0
.LLSDACSE1374:
	.section	.text._Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_,"axG",@progbits,_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_,comdat
	.size	_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_, .-_Z15interpolatePolyIfSt6vectorIfSaIfEEET_RKT0_S6_jS3_
	.section	.text._ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev
	.type	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev, @function
_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev:
.LFB1382:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSaIfED2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1382:
	.size	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev, .-_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev
	.weak	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD1Ev
	.set	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD1Ev,_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD2Ev
	.section	.text._ZNSt12_Vector_baseIfSaIfEEC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEEC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEEC2Ev
	.type	_ZNSt12_Vector_baseIfSaIfEEC2Ev, @function
_ZNSt12_Vector_baseIfSaIfEEC2Ev:
.LFB1384:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1384:
	.size	_ZNSt12_Vector_baseIfSaIfEEC2Ev, .-_ZNSt12_Vector_baseIfSaIfEEC2Ev
	.weak	_ZNSt12_Vector_baseIfSaIfEEC1Ev
	.set	_ZNSt12_Vector_baseIfSaIfEEC1Ev,_ZNSt12_Vector_baseIfSaIfEEC2Ev
	.section	.text._ZNSt12_Vector_baseIfSaIfEED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEED5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEED2Ev
	.type	_ZNSt12_Vector_baseIfSaIfEED2Ev, @function
_ZNSt12_Vector_baseIfSaIfEED2Ev:
.LFB1387:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1387
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 24
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-24], rdi
	mov	rax, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rax+16]
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rdx
	sub	rcx, rax
	mov	rax, rcx
	sar	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rax]
	mov	rax, QWORD PTR [rbp-24]
	mov	rsi, rcx
	mov	rdi, rax
.LEHB37:
	call	_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm
.LEHE37:
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD1Ev
	jmp	.L117
.L116:
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implD1Ev
	mov	rax, rbx
	mov	rdi, rax
.LEHB38:
	call	_Unwind_Resume
.LEHE38:
.L117:
	add	rsp, 24
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1387:
	.section	.gcc_except_table
.LLSDA1387:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1387-.LLSDACSB1387
.LLSDACSB1387:
	.uleb128 .LEHB37-.LFB1387
	.uleb128 .LEHE37-.LEHB37
	.uleb128 .L116-.LFB1387
	.uleb128 0
	.uleb128 .LEHB38-.LFB1387
	.uleb128 .LEHE38-.LEHB38
	.uleb128 0
	.uleb128 0
.LLSDACSE1387:
	.section	.text._ZNSt12_Vector_baseIfSaIfEED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEED5Ev,comdat
	.size	_ZNSt12_Vector_baseIfSaIfEED2Ev, .-_ZNSt12_Vector_baseIfSaIfEED2Ev
	.weak	_ZNSt12_Vector_baseIfSaIfEED1Ev
	.set	_ZNSt12_Vector_baseIfSaIfEED1Ev,_ZNSt12_Vector_baseIfSaIfEED2Ev
	.section	.text._ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv:
.LFB1389:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1389:
	.size	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	.section	.text._ZSt8_DestroyIPffEvT_S1_RSaIT0_E,"axG",@progbits,_ZSt8_DestroyIPffEvT_S1_RSaIT0_E,comdat
	.weak	_ZSt8_DestroyIPffEvT_S1_RSaIT0_E
	.type	_ZSt8_DestroyIPffEvT_S1_RSaIT0_E, @function
_ZSt8_DestroyIPffEvT_S1_RSaIT0_E:
.LFB1390:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZSt8_DestroyIPfEvT_S1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1390:
	.size	_ZSt8_DestroyIPffEvT_S1_RSaIT0_E, .-_ZSt8_DestroyIPffEvT_S1_RSaIT0_E
	.section	.text._ZNSt6vectorIfSaIfEE9push_backERKf,"axG",@progbits,_ZNSt6vectorIfSaIfEE9push_backERKf,comdat
	.align 2
	.weak	_ZNSt6vectorIfSaIfEE9push_backERKf
	.type	_ZNSt6vectorIfSaIfEE9push_backERKf, @function
_ZNSt6vectorIfSaIfEE9push_backERKf:
.LFB1416:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdx, QWORD PTR [rax+8]
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax+16]
	cmp	rdx, rax
	je	.L122
	mov	rax, QWORD PTR [rbp-8]
	mov	rcx, QWORD PTR [rax+8]
	mov	rax, QWORD PTR [rbp-8]
	mov	rdx, QWORD PTR [rbp-16]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax+8]
	lea	rdx, [rax+4]
	mov	rax, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax+8], rdx
	jmp	.L121
.L122:
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSt6vectorIfSaIfEE3endEv
	mov	rcx, rax
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf
.L121:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1416:
	.size	_ZNSt6vectorIfSaIfEE9push_backERKf, .-_ZNSt6vectorIfSaIfEE9push_backERKf
	.section	.text._ZNKSt6vectorIfSaIfEE2atEm,"axG",@progbits,_ZNKSt6vectorIfSaIfEE2atEm,comdat
	.align 2
	.weak	_ZNKSt6vectorIfSaIfEE2atEm
	.type	_ZNKSt6vectorIfSaIfEE2atEm, @function
_ZNKSt6vectorIfSaIfEE2atEm:
.LFB1429:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE14_M_range_checkEm
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEEixEm
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1429:
	.size	_ZNKSt6vectorIfSaIfEE2atEm, .-_ZNKSt6vectorIfSaIfEE2atEm
	.section	.text._ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,comdat
	.weak	_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
	.type	_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_, @function
_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_:
.LFB1430:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1430
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 40
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rdx, QWORD PTR [rbp-32]
	mov	rax, QWORD PTR [rbp-24]
	mov	rsi, rdx
	mov	rdi, rax
.LEHB39:
	call	_ZNSsC1ERKSs
.LEHE39:
	mov	rdx, QWORD PTR [rbp-40]
	mov	rax, QWORD PTR [rbp-24]
	mov	rsi, rdx
	mov	rdi, rax
.LEHB40:
	call	_ZNSs6appendEPKc
.LEHE40:
	jmp	.L130
.L129:
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZNSsD1Ev
	mov	rax, rbx
	mov	rdi, rax
.LEHB41:
	call	_Unwind_Resume
.LEHE41:
.L130:
	mov	rax, QWORD PTR [rbp-24]
	add	rsp, 40
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1430:
	.section	.gcc_except_table
.LLSDA1430:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1430-.LLSDACSB1430
.LLSDACSB1430:
	.uleb128 .LEHB39-.LFB1430
	.uleb128 .LEHE39-.LEHB39
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB40-.LFB1430
	.uleb128 .LEHE40-.LEHB40
	.uleb128 .L129-.LFB1430
	.uleb128 0
	.uleb128 .LEHB41-.LFB1430
	.uleb128 .LEHE41-.LEHB41
	.uleb128 0
	.uleb128 0
.LLSDACSE1430:
	.section	.text._ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,comdat
	.size	_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_, .-_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
	.section	.text._ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev
	.type	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev, @function
_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev:
.LFB1435:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSaIfEC2Ev
	mov	rax, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax], 0
	mov	rax, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax+8], 0
	mov	rax, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax+16], 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1435:
	.size	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev, .-_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev
	.weak	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1Ev
	.set	_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC1Ev,_ZNSt12_Vector_baseIfSaIfEE12_Vector_implC2Ev
	.section	.text._ZNSaIfED2Ev,"axG",@progbits,_ZNSaIfED5Ev,comdat
	.align 2
	.weak	_ZNSaIfED2Ev
	.type	_ZNSaIfED2Ev, @function
_ZNSaIfED2Ev:
.LFB1438:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZN9__gnu_cxx13new_allocatorIfED2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1438:
	.size	_ZNSaIfED2Ev, .-_ZNSaIfED2Ev
	.weak	_ZNSaIfED1Ev
	.set	_ZNSaIfED1Ev,_ZNSaIfED2Ev
	.section	.text._ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm
	.type	_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm, @function
_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm:
.LFB1440:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	cmp	QWORD PTR [rbp-16], 0
	je	.L134
	mov	rax, QWORD PTR [rbp-8]
	mov	rdx, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rbp-16]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm
.L134:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1440:
	.size	_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm, .-_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm
	.section	.text._ZSt8_DestroyIPfEvT_S1_,"axG",@progbits,_ZSt8_DestroyIPfEvT_S1_,comdat
	.weak	_ZSt8_DestroyIPfEvT_S1_
	.type	_ZSt8_DestroyIPfEvT_S1_, @function
_ZSt8_DestroyIPfEvT_S1_:
.LFB1441:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1441:
	.size	_ZSt8_DestroyIPfEvT_S1_, .-_ZSt8_DestroyIPfEvT_S1_
	.section	.text._ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_,"axG",@progbits,_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_,comdat
	.weak	_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_
	.type	_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_, @function
_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_:
.LFB1474:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rdx, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1474:
	.size	_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_, .-_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_
	.section	.rodata
.LC48:
	.string	"vector::_M_insert_aux"
	.section	.text._ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf,"axG",@progbits,_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf,comdat
	.align 2
	.weak	_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf
	.type	_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf, @function
_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf:
.LFB1475:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1475
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r12
	push	rbx
	sub	rsp, 80
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	mov	QWORD PTR [rbp-72], rdi
	mov	QWORD PTR [rbp-80], rsi
	mov	QWORD PTR [rbp-88], rdx
	mov	rax, QWORD PTR [rbp-72]
	mov	rdx, QWORD PTR [rax+8]
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax+16]
	cmp	rdx, rax
	je	.L139
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax+8]
	lea	rdx, [rax-4]
	mov	rax, QWORD PTR [rbp-72]
	mov	rcx, QWORD PTR [rax+8]
	mov	rax, QWORD PTR [rbp-72]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax+8]
	lea	rdx, [rax+4]
	mov	rax, QWORD PTR [rbp-72]
	mov	QWORD PTR [rax+8], rdx
	mov	rax, QWORD PTR [rbp-88]
	mov	eax, DWORD PTR [rax]
	mov	DWORD PTR [rbp-28], eax
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax+8]
	lea	r12, [rax-4]
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax+8]
	lea	rbx, [rax-8]
	lea	rax, [rbp-80]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	mov	rax, QWORD PTR [rax]
	mov	rdx, r12
	mov	rsi, rbx
	mov	rdi, rax
.LEHB42:
	call	_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_
	lea	rax, [rbp-80]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv
	mov	rdx, rax
	mov	eax, DWORD PTR [rbp-28]
	mov	DWORD PTR [rdx], eax
	jmp	.L138
.L139:
	mov	rax, QWORD PTR [rbp-72]
	mov	edx, OFFSET FLAT:.LC48
	mov	esi, 1
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc
	mov	QWORD PTR [rbp-40], rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rdi, rax
	call	_ZNSt6vectorIfSaIfEE5beginEv
	mov	QWORD PTR [rbp-64], rax
	lea	rdx, [rbp-64]
	lea	rax, [rbp-80]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	mov	QWORD PTR [rbp-48], rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rdx, QWORD PTR [rbp-40]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm
.LEHE42:
	mov	QWORD PTR [rbp-56], rax
	mov	rax, QWORD PTR [rbp-56]
	mov	QWORD PTR [rbp-24], rax
	mov	rax, QWORD PTR [rbp-48]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-56]
	lea	rcx, [rdx+rax]
	mov	rax, QWORD PTR [rbp-72]
	mov	rdx, QWORD PTR [rbp-88]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZN9__gnu_cxx14__alloc_traitsISaIfEE9constructIfEEvRS1_PfRKT_
	mov	QWORD PTR [rbp-24], 0
	mov	rax, QWORD PTR [rbp-72]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	mov	rbx, rax
	lea	rax, [rbp-80]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	mov	rsi, QWORD PTR [rax]
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax]
	mov	rdx, QWORD PTR [rbp-56]
	mov	rcx, rbx
	mov	rdi, rax
.LEHB43:
	call	_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_
	mov	QWORD PTR [rbp-24], rax
	add	QWORD PTR [rbp-24], 4
	mov	rax, QWORD PTR [rbp-72]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	mov	r12, rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rbx, QWORD PTR [rax+8]
	lea	rax, [rbp-80]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	mov	rax, QWORD PTR [rax]
	mov	rdx, QWORD PTR [rbp-24]
	mov	rcx, r12
	mov	rsi, rbx
	mov	rdi, rax
	call	_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_
.LEHE43:
	mov	QWORD PTR [rbp-24], rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rcx, QWORD PTR [rax+8]
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax]
	mov	rsi, rcx
	mov	rdi, rax
.LEHB44:
	call	_ZSt8_DestroyIPffEvT_S1_RSaIT0_E
.LEHE44:
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax+16]
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rdx
	sub	rcx, rax
	mov	rax, rcx
	sar	rax, 2
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rcx, QWORD PTR [rax]
	mov	rax, QWORD PTR [rbp-72]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm
	mov	rax, QWORD PTR [rbp-72]
	mov	rdx, QWORD PTR [rbp-56]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR [rbp-72]
	mov	rdx, QWORD PTR [rbp-24]
	mov	QWORD PTR [rax+8], rdx
	mov	rax, QWORD PTR [rbp-40]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-56]
	add	rdx, rax
	mov	rax, QWORD PTR [rbp-72]
	mov	QWORD PTR [rax+16], rdx
	jmp	.L138
.L146:
	mov	rbx, rax
	call	__cxa_end_catch
	mov	rax, rbx
	mov	rdi, rax
.LEHB45:
	call	_Unwind_Resume
.LEHE45:
.L145:
	mov	rdi, rax
	call	__cxa_begin_catch
	cmp	QWORD PTR [rbp-24], 0
	jne	.L143
	mov	rax, QWORD PTR [rbp-48]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-56]
	add	rdx, rax
	mov	rax, QWORD PTR [rbp-72]
	mov	rsi, rdx
	mov	rdi, rax
.LEHB46:
	call	_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf
	jmp	.L144
.L143:
	mov	rax, QWORD PTR [rbp-72]
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	mov	rdx, rax
	mov	rcx, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rbp-56]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZSt8_DestroyIPffEvT_S1_RSaIT0_E
.L144:
	mov	rax, QWORD PTR [rbp-72]
	mov	rdx, QWORD PTR [rbp-40]
	mov	rcx, QWORD PTR [rbp-56]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZNSt12_Vector_baseIfSaIfEE13_M_deallocateEPfm
	call	__cxa_rethrow
.LEHE46:
.L138:
	add	rsp, 80
	pop	rbx
	pop	r12
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1475:
	.section	.gcc_except_table
	.align 4
.LLSDA1475:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT1475-.LLSDATTD1475
.LLSDATTD1475:
	.byte	0x1
	.uleb128 .LLSDACSE1475-.LLSDACSB1475
.LLSDACSB1475:
	.uleb128 .LEHB42-.LFB1475
	.uleb128 .LEHE42-.LEHB42
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB43-.LFB1475
	.uleb128 .LEHE43-.LEHB43
	.uleb128 .L145-.LFB1475
	.uleb128 0x1
	.uleb128 .LEHB44-.LFB1475
	.uleb128 .LEHE44-.LEHB44
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB45-.LFB1475
	.uleb128 .LEHE45-.LEHB45
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB46-.LFB1475
	.uleb128 .LEHE46-.LEHB46
	.uleb128 .L146-.LFB1475
	.uleb128 0
.LLSDACSE1475:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1475:
	.section	.text._ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf,"axG",@progbits,_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf,comdat
	.size	_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf, .-_ZNSt6vectorIfSaIfEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPfS1_EERKf
	.section	.text._ZNSt6vectorIfSaIfEE3endEv,"axG",@progbits,_ZNSt6vectorIfSaIfEE3endEv,comdat
	.align 2
	.weak	_ZNSt6vectorIfSaIfEE3endEv
	.type	_ZNSt6vectorIfSaIfEE3endEv, @function
_ZNSt6vectorIfSaIfEE3endEv:
.LFB1476:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-24], rdi
	mov	rax, QWORD PTR [rbp-24]
	lea	rdx, [rax+8]
	lea	rax, [rbp-16]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC1ERKS1_
	mov	rax, QWORD PTR [rbp-16]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1476:
	.size	_ZNSt6vectorIfSaIfEE3endEv, .-_ZNSt6vectorIfSaIfEE3endEv
	.section	.rodata
.LC49:
	.string	"vector::_M_range_check"
	.section	.text._ZNKSt6vectorIfSaIfEE14_M_range_checkEm,"axG",@progbits,_ZNKSt6vectorIfSaIfEE14_M_range_checkEm,comdat
	.align 2
	.weak	_ZNKSt6vectorIfSaIfEE14_M_range_checkEm
	.type	_ZNKSt6vectorIfSaIfEE14_M_range_checkEm, @function
_ZNKSt6vectorIfSaIfEE14_M_range_checkEm:
.LFB1491:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE4sizeEv
	cmp	rax, QWORD PTR [rbp-16]
	setbe	al
	test	al, al
	je	.L149
	mov	edi, OFFSET FLAT:.LC49
	call	_ZSt20__throw_out_of_rangePKc
.L149:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1491:
	.size	_ZNKSt6vectorIfSaIfEE14_M_range_checkEm, .-_ZNKSt6vectorIfSaIfEE14_M_range_checkEm
	.section	.text._ZNKSt6vectorIfSaIfEEixEm,"axG",@progbits,_ZNKSt6vectorIfSaIfEEixEm,comdat
	.align 2
	.weak	_ZNKSt6vectorIfSaIfEEixEm
	.type	_ZNKSt6vectorIfSaIfEEixEm, @function
_ZNKSt6vectorIfSaIfEEixEm:
.LFB1492:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax]
	mov	rdx, QWORD PTR [rbp-16]
	sal	rdx, 2
	add	rax, rdx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1492:
	.size	_ZNKSt6vectorIfSaIfEEixEm, .-_ZNKSt6vectorIfSaIfEEixEm
	.section	.text._ZNSaIfEC2Ev,"axG",@progbits,_ZNSaIfEC5Ev,comdat
	.align 2
	.weak	_ZNSaIfEC2Ev
	.type	_ZNSaIfEC2Ev, @function
_ZNSaIfEC2Ev:
.LFB1497:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZN9__gnu_cxx13new_allocatorIfEC2Ev
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1497:
	.size	_ZNSaIfEC2Ev, .-_ZNSaIfEC2Ev
	.weak	_ZNSaIfEC1Ev
	.set	_ZNSaIfEC1Ev,_ZNSaIfEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIfED2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIfED5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIfED2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIfED2Ev, @function
_ZN9__gnu_cxx13new_allocatorIfED2Ev:
.LFB1500:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1500:
	.size	_ZN9__gnu_cxx13new_allocatorIfED2Ev, .-_ZN9__gnu_cxx13new_allocatorIfED2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIfED1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIfED1Ev,_ZN9__gnu_cxx13new_allocatorIfED2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm
	.type	_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm, @function
_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm:
.LFB1502:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rax, QWORD PTR [rbp-16]
	mov	rdi, rax
	call	_ZdlPv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1502:
	.size	_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm, .-_ZN9__gnu_cxx13new_allocatorIfE10deallocateEPfm
	.section	.text._ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_,"axG",@progbits,_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_,comdat
	.weak	_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_
	.type	_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_, @function
_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_:
.LFB1503:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1503:
	.size	_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_, .-_ZNSt12_Destroy_auxILb1EE9__destroyIPfEEvT_S3_
	.section	.text._ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf
	.type	_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf, @function
_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf:
.LFB1507:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rax, QWORD PTR [rbp-16]
	mov	rsi, rax
	mov	edi, 4
	call	_ZnwmPv
	test	rax, rax
	je	.L158
	mov	rdx, QWORD PTR [rbp-24]
	mov	edx, DWORD PTR [rdx]
	mov	DWORD PTR [rax], edx
.L158:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1507:
	.size	_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf, .-_ZN9__gnu_cxx13new_allocatorIfE9constructEPfRKf
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv:
.LFB1508:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1508:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	.section	.text._ZSt13copy_backwardIPfS0_ET0_T_S2_S1_,"axG",@progbits,_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_,comdat
	.weak	_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_
	.type	_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_, @function
_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_:
.LFB1509:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 40
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rax, QWORD PTR [rbp-32]
	mov	rdi, rax
	call	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_
	mov	rdx, QWORD PTR [rbp-40]
	mov	rsi, rbx
	mov	rdi, rax
	call	_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_
	add	rsp, 40
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1509:
	.size	_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_, .-_ZSt13copy_backwardIPfS0_ET0_T_S2_S1_
	.section	.text._ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv,"axG",@progbits,_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv
	.type	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv, @function
_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv:
.LFB1510:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1510:
	.size	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv, .-_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEdeEv
	.section	.text._ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc,"axG",@progbits,_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc,comdat
	.align 2
	.weak	_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc
	.type	_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc, @function
_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc:
.LFB1511:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 56
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-40], rdi
	mov	QWORD PTR [rbp-48], rsi
	mov	QWORD PTR [rbp-56], rdx
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE8max_sizeEv
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE4sizeEv
	mov	rdx, rbx
	sub	rdx, rax
	mov	rax, QWORD PTR [rbp-48]
	cmp	rdx, rax
	setb	al
	test	al, al
	je	.L168
	mov	rax, QWORD PTR [rbp-56]
	mov	rdi, rax
	call	_ZSt20__throw_length_errorPKc
.L168:
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE4sizeEv
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE4sizeEv
	mov	QWORD PTR [rbp-32], rax
	lea	rdx, [rbp-48]
	lea	rax, [rbp-32]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZSt3maxImERKT_S2_S2_
	mov	rax, QWORD PTR [rax]
	add	rax, rbx
	mov	QWORD PTR [rbp-24], rax
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE4sizeEv
	cmp	rax, QWORD PTR [rbp-24]
	ja	.L169
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE8max_sizeEv
	cmp	rax, QWORD PTR [rbp-24]
	jae	.L170
.L169:
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZNKSt6vectorIfSaIfEE8max_sizeEv
	jmp	.L171
.L170:
	mov	rax, QWORD PTR [rbp-24]
.L171:
	add	rsp, 56
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1511:
	.size	_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc, .-_ZNKSt6vectorIfSaIfEE12_M_check_lenEmPKc
	.section	.text._ZNSt6vectorIfSaIfEE5beginEv,"axG",@progbits,_ZNSt6vectorIfSaIfEE5beginEv,comdat
	.align 2
	.weak	_ZNSt6vectorIfSaIfEE5beginEv
	.type	_ZNSt6vectorIfSaIfEE5beginEv, @function
_ZNSt6vectorIfSaIfEE5beginEv:
.LFB1512:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-24], rdi
	mov	rdx, QWORD PTR [rbp-24]
	lea	rax, [rbp-16]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC1ERKS1_
	mov	rax, QWORD PTR [rbp-16]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1512:
	.size	_ZNSt6vectorIfSaIfEE5beginEv, .-_ZNSt6vectorIfSaIfEE5beginEv
	.section	.text._ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_,"axG",@progbits,_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_,comdat
	.weak	_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	.type	_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_, @function
_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_:
.LFB1513:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 24
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	mov	rax, QWORD PTR [rax]
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-32]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEE4baseEv
	mov	rax, QWORD PTR [rax]
	mov	rdx, rbx
	sub	rdx, rax
	mov	rax, rdx
	sar	rax, 2
	add	rsp, 24
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1513:
	.size	_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_, .-_ZN9__gnu_cxxmiIPfSt6vectorIfSaIfEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	.section	.text._ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm,"axG",@progbits,_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm
	.type	_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm, @function
_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm:
.LFB1514:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	cmp	QWORD PTR [rbp-16], 0
	je	.L178
	mov	rax, QWORD PTR [rbp-8]
	mov	rcx, QWORD PTR [rbp-16]
	mov	edx, 0
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv
	jmp	.L179
.L178:
	mov	eax, 0
.L179:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1514:
	.size	_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm, .-_ZNSt12_Vector_baseIfSaIfEE11_M_allocateEm
	.section	.text._ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_,"axG",@progbits,_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_,comdat
	.weak	_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_
	.type	_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_, @function
_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_:
.LFB1515:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	QWORD PTR [rbp-32], rcx
	mov	rcx, QWORD PTR [rbp-32]
	mov	rdx, QWORD PTR [rbp-24]
	mov	rsi, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1515:
	.size	_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_, .-_ZSt34__uninitialized_move_if_noexcept_aIPfS0_SaIfEET0_T_S3_S2_RT1_
	.section	.text._ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf,"axG",@progbits,_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf,comdat
	.weak	_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf
	.type	_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf, @function
_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf:
.LFB1516:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rdx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rdx
	mov	rdi, rax
	call	_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1516:
	.size	_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf, .-_ZN9__gnu_cxx14__alloc_traitsISaIfEE7destroyERS1_Pf
	.section	.text._ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_,"axG",@progbits,_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC5ERKS1_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_
	.type	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_, @function
_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_:
.LFB1518:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-16]
	mov	rdx, QWORD PTR [rax]
	mov	rax, QWORD PTR [rbp-8]
	mov	QWORD PTR [rax], rdx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1518:
	.size	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_, .-_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_
	.weak	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC1ERKS1_
	.set	_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC1ERKS1_,_ZN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEC2ERKS1_
	.section	.text._ZNKSt6vectorIfSaIfEE4sizeEv,"axG",@progbits,_ZNKSt6vectorIfSaIfEE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIfSaIfEE4sizeEv
	.type	_ZNKSt6vectorIfSaIfEE4sizeEv, @function
_ZNKSt6vectorIfSaIfEE4sizeEv:
.LFB1530:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax+8]
	mov	rdx, rax
	mov	rax, QWORD PTR [rbp-8]
	mov	rax, QWORD PTR [rax]
	mov	rcx, rdx
	sub	rcx, rax
	mov	rax, rcx
	sar	rax, 2
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1530:
	.size	_ZNKSt6vectorIfSaIfEE4sizeEv, .-_ZNKSt6vectorIfSaIfEE4sizeEv
	.section	.text._ZN9__gnu_cxx13new_allocatorIfEC2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIfEC5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIfEC2Ev
	.type	_ZN9__gnu_cxx13new_allocatorIfEC2Ev, @function
_ZN9__gnu_cxx13new_allocatorIfEC2Ev:
.LFB1532:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1532:
	.size	_ZN9__gnu_cxx13new_allocatorIfEC2Ev, .-_ZN9__gnu_cxx13new_allocatorIfEC2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorIfEC1Ev
	.set	_ZN9__gnu_cxx13new_allocatorIfEC1Ev,_ZN9__gnu_cxx13new_allocatorIfEC2Ev
	.section	.text._ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_,"axG",@progbits,_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_,comdat
	.weak	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_
	.type	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_, @function
_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_:
.LFB1534:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1534:
	.size	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_, .-_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_
	.section	.text._ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_,"axG",@progbits,_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_,comdat
	.weak	_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_
	.type	_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_, @function
_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_:
.LFB1535:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r12
	push	rbx
	sub	rsp, 32
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	mov	r12, rax
	mov	rax, QWORD PTR [rbp-32]
	mov	rdi, rax
	call	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	mov	rdx, r12
	mov	rsi, rbx
	mov	rdi, rax
	call	_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_
	add	rsp, 32
	pop	rbx
	pop	r12
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1535:
	.size	_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_, .-_ZSt23__copy_move_backward_a2ILb0EPfS0_ET1_T0_S2_S1_
	.section	.text._ZNKSt6vectorIfSaIfEE8max_sizeEv,"axG",@progbits,_ZNKSt6vectorIfSaIfEE8max_sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIfSaIfEE8max_sizeEv
	.type	_ZNKSt6vectorIfSaIfEE8max_sizeEv, @function
_ZNKSt6vectorIfSaIfEE8max_sizeEv:
.LFB1536:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	mov	rdi, rax
	call	_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1536:
	.size	_ZNKSt6vectorIfSaIfEE8max_sizeEv, .-_ZNKSt6vectorIfSaIfEE8max_sizeEv
	.section	.text._ZSt3maxImERKT_S2_S2_,"axG",@progbits,_ZSt3maxImERKT_S2_S2_,comdat
	.weak	_ZSt3maxImERKT_S2_S2_
	.type	_ZSt3maxImERKT_S2_S2_, @function
_ZSt3maxImERKT_S2_S2_:
.LFB1537:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdx, QWORD PTR [rax]
	mov	rax, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rax]
	cmp	rdx, rax
	jae	.L195
	mov	rax, QWORD PTR [rbp-16]
	jmp	.L196
.L195:
	mov	rax, QWORD PTR [rbp-8]
.L196:
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1537:
	.size	_ZSt3maxImERKT_S2_S2_, .-_ZSt3maxImERKT_S2_S2_
	.section	.text._ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv
	.type	_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv, @function
_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv:
.LFB1538:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv
	cmp	rax, QWORD PTR [rbp-16]
	setb	al
	test	al, al
	je	.L198
	call	_ZSt17__throw_bad_allocv
.L198:
	mov	rax, QWORD PTR [rbp-16]
	sal	rax, 2
	mov	rdi, rax
	call	_Znwm
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1538:
	.size	_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv, .-_ZN9__gnu_cxx13new_allocatorIfE8allocateEmPKv
	.section	.text._ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E,"axG",@progbits,_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E,comdat
	.weak	_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E
	.type	_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E, @function
_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E:
.LFB1539:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	QWORD PTR [rbp-32], rcx
	mov	rdx, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1539:
	.size	_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E, .-_ZSt22__uninitialized_copy_aIPfS0_fET0_T_S2_S1_RSaIT1_E
	.section	.text._ZN9__gnu_cxx13new_allocatorIfE7destroyEPf,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf
	.type	_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf, @function
_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf:
.LFB1540:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1540:
	.size	_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf, .-_ZN9__gnu_cxx13new_allocatorIfE7destroyEPf
	.section	.text._ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_,"axG",@progbits,_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_,comdat
	.weak	_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_
	.type	_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_, @function
_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_:
.LFB1541:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1541:
	.size	_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_, .-_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_
	.section	.text._ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_,"axG",@progbits,_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_,comdat
	.weak	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	.type	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_, @function
_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_:
.LFB1542:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNSt10_Iter_baseIPfLb0EE7_S_baseES0_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1542:
	.size	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_, .-_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	.section	.text._ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_,"axG",@progbits,_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_,comdat
	.weak	_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_
	.type	_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_, @function
_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_:
.LFB1543:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	BYTE PTR [rbp-1], 1
	mov	rdx, QWORD PTR [rbp-40]
	mov	rcx, QWORD PTR [rbp-32]
	mov	rax, QWORD PTR [rbp-24]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1543:
	.size	_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_, .-_ZSt22__copy_move_backward_aILb0EPfS0_ET1_T0_S2_S1_
	.section	.text._ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_,"axG",@progbits,_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_,comdat
	.weak	_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_
	.type	_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_, @function
_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_:
.LFB1544:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	mov	rdi, rax
	call	_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1544:
	.size	_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_, .-_ZN9__gnu_cxx14__alloc_traitsISaIfEE8max_sizeERKS1_
	.section	.text._ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	.type	_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv, @function
_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv:
.LFB1545:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	mov	rax, QWORD PTR [rbp-8]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1545:
	.size	_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv, .-_ZNKSt12_Vector_baseIfSaIfEE19_M_get_Tp_allocatorEv
	.section	.text._ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv,"axG",@progbits,_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv
	.type	_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv, @function
_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv:
.LFB1546:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-8], rdi
	movabs	rax, 4611686018427387903
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1546:
	.size	_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv, .-_ZNK9__gnu_cxx13new_allocatorIfE8max_sizeEv
	.section	.text._ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_,"axG",@progbits,_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_,comdat
	.weak	_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_
	.type	_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_, @function
_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_:
.LFB1547:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rdx, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1547:
	.size	_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_, .-_ZSt18uninitialized_copyIPfS0_ET0_T_S2_S1_
	.section	.text._ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_
	.type	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_, @function
_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_:
.LFB1548:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rdx, QWORD PTR [rbp-32]
	mov	rax, QWORD PTR [rbp-24]
	mov	rcx, rdx
	sub	rcx, rax
	mov	rax, rcx
	sar	rax, 2
	mov	QWORD PTR [rbp-8], rax
	cmp	QWORD PTR [rbp-8], 0
	je	.L218
	mov	rax, QWORD PTR [rbp-8]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-8]
	sal	rax, 2
	mov	rcx, rax
	neg	rcx
	mov	rax, QWORD PTR [rbp-40]
	add	rcx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rsi, rax
	mov	rdi, rcx
	call	memmove
.L218:
	mov	rax, QWORD PTR [rbp-8]
	sal	rax, 2
	mov	rdx, rax
	neg	rdx
	mov	rax, QWORD PTR [rbp-40]
	add	rax, rdx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1548:
	.size	_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_, .-_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIfEEPT_PKS3_S6_S4_
	.section	.text._ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_,"axG",@progbits,_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_,comdat
	.weak	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_
	.type	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_, @function
_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_:
.LFB1549:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR [rbp-8], rdi
	mov	QWORD PTR [rbp-16], rsi
	mov	QWORD PTR [rbp-24], rdx
	mov	rdx, QWORD PTR [rbp-24]
	mov	rcx, QWORD PTR [rbp-16]
	mov	rax, QWORD PTR [rbp-8]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZSt4copyIPfS0_ET0_T_S2_S1_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1549:
	.size	_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_, .-_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIPfS2_EET0_T_S4_S3_
	.section	.text._ZSt4copyIPfS0_ET0_T_S2_S1_,"axG",@progbits,_ZSt4copyIPfS0_ET0_T_S2_S1_,comdat
	.weak	_ZSt4copyIPfS0_ET0_T_S2_S1_
	.type	_ZSt4copyIPfS0_ET0_T_S2_S1_, @function
_ZSt4copyIPfS0_ET0_T_S2_S1_:
.LFB1550:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 40
	.cfi_offset 3, -24
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rax, QWORD PTR [rbp-32]
	mov	rdi, rax
	call	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZSt12__miter_baseIPfENSt11_Miter_baseIT_E13iterator_typeES2_
	mov	rdx, QWORD PTR [rbp-40]
	mov	rsi, rbx
	mov	rdi, rax
	call	_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_
	add	rsp, 40
	pop	rbx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1550:
	.size	_ZSt4copyIPfS0_ET0_T_S2_S1_, .-_ZSt4copyIPfS0_ET0_T_S2_S1_
	.section	.text._ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_,"axG",@progbits,_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_,comdat
	.weak	_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_
	.type	_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_, @function
_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_:
.LFB1551:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	r12
	push	rbx
	sub	rsp, 32
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	mov	r12, rax
	mov	rax, QWORD PTR [rbp-32]
	mov	rdi, rax
	call	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	mov	rbx, rax
	mov	rax, QWORD PTR [rbp-24]
	mov	rdi, rax
	call	_ZSt12__niter_baseIPfENSt11_Niter_baseIT_E13iterator_typeES2_
	mov	rdx, r12
	mov	rsi, rbx
	mov	rdi, rax
	call	_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_
	add	rsp, 32
	pop	rbx
	pop	r12
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1551:
	.size	_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_, .-_ZSt14__copy_move_a2ILb0EPfS0_ET1_T0_S2_S1_
	.section	.text._ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_,"axG",@progbits,_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_,comdat
	.weak	_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_
	.type	_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_, @function
_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_:
.LFB1552:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	BYTE PTR [rbp-1], 1
	mov	rdx, QWORD PTR [rbp-40]
	mov	rcx, QWORD PTR [rbp-32]
	mov	rax, QWORD PTR [rbp-24]
	mov	rsi, rcx
	mov	rdi, rax
	call	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1552:
	.size	_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_, .-_ZSt13__copy_move_aILb0EPfS0_ET1_T0_S2_S1_
	.section	.text._ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_,"axG",@progbits,_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_,comdat
	.weak	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_
	.type	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_, @function
_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_:
.LFB1553:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR [rbp-24], rdi
	mov	QWORD PTR [rbp-32], rsi
	mov	QWORD PTR [rbp-40], rdx
	mov	rdx, QWORD PTR [rbp-32]
	mov	rax, QWORD PTR [rbp-24]
	mov	rcx, rdx
	sub	rcx, rax
	mov	rax, rcx
	sar	rax, 2
	mov	QWORD PTR [rbp-8], rax
	cmp	QWORD PTR [rbp-8], 0
	je	.L229
	mov	rax, QWORD PTR [rbp-8]
	lea	rdx, [0+rax*4]
	mov	rcx, QWORD PTR [rbp-24]
	mov	rax, QWORD PTR [rbp-40]
	mov	rsi, rcx
	mov	rdi, rax
	call	memmove
.L229:
	mov	rax, QWORD PTR [rbp-8]
	lea	rdx, [0+rax*4]
	mov	rax, QWORD PTR [rbp-40]
	add	rax, rdx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1553:
	.size	_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_, .-_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIfEEPT_PKS3_S6_S4_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1554:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	cmp	DWORD PTR [rbp-4], 1
	jne	.L231
	cmp	DWORD PTR [rbp-8], 65535
	jne	.L231
	mov	edi, OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edx, OFFSET FLAT:__dso_handle
	mov	esi, OFFSET FLAT:_ZStL8__ioinit
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
.L231:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1554:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z8promptYNSs, @function
_GLOBAL__sub_I__Z8promptYNSs:
.LFB1555:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	esi, 65535
	mov	edi, 1
	call	_Z41__static_initialization_and_destruction_0ii
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1555:
	.size	_GLOBAL__sub_I__Z8promptYNSs, .-_GLOBAL__sub_I__Z8promptYNSs
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z8promptYNSs
	.section	.rodata
	.align 8
	.type	_ZZL18__gthread_active_pvE20__gthread_active_ptr, @object
	.size	_ZZL18__gthread_active_pvE20__gthread_active_ptr, 8
_ZZL18__gthread_active_pvE20__gthread_active_ptr:
	.quad	_ZL22__gthrw_pthread_cancelm
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.align 4
.LC25:
	.long	0
	.align 4
.LC37:
	.long	1065353216
	.hidden	__dso_handle
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
