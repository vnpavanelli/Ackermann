#include <stack>


unsigned int ackermann_iterative(unsigned int m, unsigned int n) {
	std::stack<unsigned int> pilha;
	pilha.push(m);
	pilha.push(n);
	while (1) {
		n = pilha.top();
		pilha.pop();
		if (pilha.empty()) {
			return n;
		}
		m = pilha.top();
		pilha.pop();
		if (m==0) {
			pilha.push(n+1);
			continue;
		} else if (n==0) {
			pilha.push(m-1);
			pilha.push(1);
			continue;
		} else {
			pilha.push(m-1);
			pilha.push(m);
			pilha.push(n-1);
			continue;
		}
	}
	return 0;
}


