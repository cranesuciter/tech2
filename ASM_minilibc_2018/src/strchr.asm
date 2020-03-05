[BITS 64]

global strchr

section .text

strchr:
xor rcx, rcx
cmp rdi, 0
je null

count:
cmp BYTE [rdi + rcx], 0
je null
cmp BYTE [rdi + rcx], sil
je found
inc rcx
jmp count

found:
add rdi, rcx
mov rax, rdi
ret

null:
mov rax, 0
ret