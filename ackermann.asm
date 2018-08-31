global ackermann_iterative_asm
section .text

;; m <- rax
;; n <- rcx
;; SP <- rdx

ackermann_iterative_asm:
push rcx ;; salve rcx para restaurar depois
push rdx ;; salve rdx para restaurar depois
mov rdx, rsp ;; salve o inicio da pilha
push rdi ;; push m
push rsi ;; push n

_inicio:

pop rcx ;; pop n -> r11
cmp rsp, rdx ;; compara pilha se esta vazia
je _fim ;; se estive vai pro fim
pop rax ;; pop m -> r10

test rax,rax; ;; testa rax (m)
jnz _passo2 ;; se m!=0 va para passo2
inc rcx ;; n <- n+1 
push rcx ;; coloca n+1 na pilha
jmp _inicio ;; volte pro inicio do loop

_passo2:

test rcx,rcx; ;; testa rcx (n)
jnz _passo3 ;; se n!=0 va para passo3
dec rax ;; m = m-1;
push rax ;; coloque m-1 na pilha
push 1 ;; coloque 1 na pilha
jmp _inicio ;; va para inicio

_passo3:

dec rax ;; m = m - 1
push rax ;; coloca m-1 na pilha
inc rax ;; m = m + 1 (desfaz operacao anterior) 
push rax ;; coloca m na pilha
dec rcx ;; n = n -1
push rcx ;; coloca n-1 na pilha
jmp _inicio ;; va para inicio

_fim:
mov rax, rcx ;; coloque a resposta em rax para retorno
pop rdx ;; restaure registrador rdx
pop rcx ;; restaure registrador rcx

ret
