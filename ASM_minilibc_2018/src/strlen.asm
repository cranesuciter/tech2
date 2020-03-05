[BITS 64]

global strlen

section .text

strlen:
xor rcx, rcx

count:
cmp BYTE [rdi + rcx], 0
je end
inc rcx
jmp count

end:
mov rax, rcx
ret