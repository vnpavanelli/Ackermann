Comparison of different Ackermann implementations for Algorithms Course in DCM/FFCLRP/USP

The implementations are as followed:
* Recursive implementation (recursive)
* Iterative implementation using std::stack on every step (iterative)
* Iterative Optimized using std::stack only when needed (iterative2)
* Assembly implementation using stack (push/pop) on every step (asm1)
* Assembly Optimized using stack only when needed (asm2)

All implementation shows the same complexity. 
Though some are faster than others (Assembly and Recursive) their computation time grows the same with the parameters.

![Ackermann comparison graph](https://github.com/vnpavanelli/Ackermann/blob/master/files/Ackermann1.png)

Curve fitting for recursive and asm2 implementations, both are best guessed as O(n<sup>2</sup>):
![Ackermann curve fitting](https://github.com/vnpavanelli/Ackermann/blob/master/files/Fitting.png)
