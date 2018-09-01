global ackermann_iterative_asm2
section .text

;; m <- rdi
;; n <- rsi
;; SP <- rdx

ackermann_iterative_asm2:
push rcx ;; salve rcx para restaurar depois
push rdx ;; salve rdx para restaurar depois
mov rdx, rsp ;; salve o inicio da pilha
;; push rdi ;; push m
;; push rsi ;; push n

_inicio:

;; pop rcx ;; pop n -> r11
;; cmp rsp, rdx ;; compara pilha se esta vazia
;; je _fim ;; se estive vai pro fim
;; pop rax ;; pop m -> r10

test rdi,rdi; ;; testa m==0 ?
jnz _passo2 ;; se m!=0 va para passo2
inc rsi ;; n <- n+1 
cmp rsp, rdx ;; compara pilha se esta vazia
je _fim ;; se estive vai pro fim
;;push rcx ;; coloca n+1 na pilha
pop rdi
jmp _inicio ;; volte pro inicio do loop

_passo2:

test rsi,rsi; ;; testa rcx (n)
jnz _passo3 ;; se n!=0 va para passo3
dec rdi ;; m = m-1;
;; push rax ;; coloque m-1 na pilha
;; push 1 ;; coloque 1 na pilha
mov rsi, 1
jmp _inicio ;; va para inicio

_passo3:

dec rdi ;; m = m - 1
push rdi ;; coloca m-1 na pilha
inc rdi ;; m = m + 1 (desfaz operacao anterior) 
;; push rax ;; coloca m na pilha
dec rsi ;; n = n -1
;;push rcx ;; coloca n-1 na pilha
jmp _inicio ;; va para inicio

_fim:
mov rax, rsi ;; coloque a resposta em rax para retorno
pop rdx ;; restaure registrador rdx
pop rcx ;; restaure registrador rcx

ret
