	.file	"parser.c"
	.text
	.p2align 4,,15
	.globl	SubcommandList_Contains
	.def	SubcommandList_Contains;	.scl	2;	.type	32;	.endef
	.seh_proc	SubcommandList_Contains
SubcommandList_Contains:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	.refptr.NUM_COMMANDS(%rip), %rax
	movq	%rcx, %rsi
	movl	(%rax), %eax
	testl	%eax, %eax
	jle	.L4
	movq	.refptr.COMMANDS(%rip), %rbx
	subl	$1, %eax
	leaq	8(%rbx,%rax,8), %rdi
	jmp	.L3
	.p2align 4,,10
.L8:
	addq	$8, %rbx
	cmpq	%rdi, %rbx
	je	.L4
.L3:
	movq	(%rbx), %rdx
	movq	%rsi, %rcx
	call	strcmp
	testl	%eax, %eax
	jne	.L8
	movl	$1, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
.L4:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	Parser_Next
	.def	Parser_Next;	.scl	2;	.type	32;	.endef
	.seh_proc	Parser_Next
Parser_Next:
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	state.2282(%rip), %eax
	movl	%ecx, %r12d
	movq	%rdx, %r13
	testl	%eax, %eax
	je	.L11
	cmpl	$1, %eax
	jne	.L27
	movl	i.2281(%rip), %edi
.L17:
	addl	$1, %edi
	movl	%edi, i.2281(%rip)
.L13:
	cmpl	%edi, %r12d
	jle	.L28
	movslq	%edi, %rax
	movq	0(%r13,%rax,8), %rsi
	cmpb	$45, (%rsi)
	je	.L14
	movl	state.2282(%rip), %eax
	testl	%eax, %eax
	je	.L15
.L14:
	movq	.refptr.NUM_COMMANDS(%rip), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jle	.L17
	movq	.refptr.COMMANDS(%rip), %rbx
	subl	$1, %eax
	leaq	8(%rbx,%rax,8), %rbp
	jmp	.L18
	.p2align 4,,10
.L29:
	addq	$8, %rbx
	cmpq	%rbx, %rbp
	je	.L17
.L18:
	movq	(%rbx), %rdx
	movq	%rsi, %rcx
	call	strcmp
	testl	%eax, %eax
	jne	.L29
	movq	%rsi, %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.p2align 4,,10
.L27:
	xorl	%esi, %esi
.L9:
	movq	%rsi, %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.p2align 4,,10
.L11:
	movl	$1, i.2281(%rip)
	movl	$1, %edi
	jmp	.L13
	.p2align 4,,10
.L15:
	movl	$1, state.2282(%rip)
	jmp	.L9
	.p2align 4,,10
.L28:
	movl	$-1, state.2282(%rip)
	xorl	%esi, %esi
	jmp	.L9
	.seh_endproc
	.p2align 4,,15
	.globl	Parser_NextArgs
	.def	Parser_NextArgs;	.scl	2;	.type	32;	.endef
	.seh_proc	Parser_NextArgs
Parser_NextArgs:
	.seh_endprologue
	ret
	.seh_endproc
.lcomm i.2281,4,4
.lcomm state.2282,4,4
	.ident	"GCC: (GNU) 7.3.0"
	.def	strcmp;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.COMMANDS, "dr"
	.globl	.refptr.COMMANDS
	.linkonce	discard
.refptr.COMMANDS:
	.quad	COMMANDS
	.section	.rdata$.refptr.NUM_COMMANDS, "dr"
	.globl	.refptr.NUM_COMMANDS
	.linkonce	discard
.refptr.NUM_COMMANDS:
	.quad	NUM_COMMANDS
