[BITS 64]

global memset

section .text

memset:
mov rax, rdi

count:
cmp rdx, 0
je end
mov [rax], sil
inc rax
dec rdx
jmp count

end:
mov rax, rdi
ret