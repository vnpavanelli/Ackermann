global ackermann_iterative_asm
section .text

;; m <- rax
;; n <- rcx
;; SP <- rdx

ackermann_iterative_asm:
push rcx
push rdx
mov rdx, rsp ;; salve o inicio da pilha
push rdi ;; push m
push rsi ;; push n

_inicio:

pop rcx ;; pop n -> r11
cmp rsp, rdx ;; compara pilha se esta vazia
je _fim ;; se estive vai pro fim
pop rax ;; pop m -> r10

cmp rax,0 ;; m==0?
jne _passo2 ;; caso nao va pra passo2
inc rcx ;; n <- n+1 
push rcx ;; coloca n+1 na pilha
jmp _inicio

_passo2:

cmp rcx,0
jne _passo3
dec rax
push rax
push 1
jmp _inicio

_passo3:

dec rax
push rax
inc rax
push rax
dec rcx
push rcx
jmp _inicio

_fim:
mov rax, rcx
pop rdx
pop rcx

ret
