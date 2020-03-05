[BITS 64]

global strncmp

section .text

strncmp:
xor rcx, rcx

count:
mov al, [rdi + rcx]
mov bl, [rsi + rcx]
inc rcx
cmp al, bl
jne end
cmp rcx, rdx
jne end
jmp count

end:
sub al, bl
movsx rax, al
ret