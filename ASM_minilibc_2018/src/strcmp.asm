[BITS 64]

global strcmp

section .text

strcmp:
xor rcx, rcx

count:
mov al, [rdi + rcx]
mov bl, [rsi + rcx]
inc rcx
cmp  al, 0
cmp bl, 0
je end
cmp al, bl
jne end
jmp count

end:
sub al, bl
movsx rax, al
ret