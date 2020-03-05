[BITS 64]

global strcasecmp

section .text

strcasecmp:
xor rcx, rcx
jmp check1

lowcase1:
add al, 32
jmp check2

lowcase2:
add bl, 32
jmp count

check1:
mov al, [rdi + rcx]
cmp al, 65
jl check2
cmp al, 90
jle lowcase1

check2:
mov bl, [rsi + rcx]
cmp bl, 65
jl count
cmp bl, 90
jle lowcase2

count:
cmp al, bl
jne end
cmp al, 0
cmp bl, 0
je end
inc rcx
jmp check1

end:
sub al, bl
movsx rax, al
ret