[BITS 64]

global memmove

section .text

memmove:
xor	rcx, rcx

count:
cmp	rcx, rdx
je	end
mov	rax, [rsi]
mov	byte [rdi], al
inc rsi
inc	rcx
inc rdi
jmp	count

end:
mov	rax, rdi
ret