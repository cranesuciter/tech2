[BITS 64]

global rindex

section .text

rindex:
xor rcx, rcx

go_to_end:
cmp BYTE [rdi], 0
je found_it
inc rdi
jmp go_to_end

found_it:
cmp BYTE [rdi], sil
je end
cmp rcx, 0
je end_null
dec rdi
jmp found_it

end:
mov rax, rdi
ret

end_null:
mov rax, 0
ret