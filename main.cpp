#include <iostream>
#include <stack>
#include <vector>
#include <chrono>

const bool DEBUG = false;
const unsigned int LIMIT_M = 4;
const unsigned int LIMIT_N = 10;

unsigned int ackermann_recursive(unsigned int, unsigned int);
unsigned int ackermann_iterative(unsigned int, unsigned int);
extern "C" unsigned int ackermann_iterative_asm(unsigned int, unsigned int);

void teste(void) {
	std::stack<int> pilha;
	std::cout << "Pilha: size=" << pilha.size() << std::endl;
	pilha.push(1);
	std::cout << "Pilha: size=" << pilha.size() << std::endl;
	pilha.push(2);
	std::cout << "Pilha: size=" << pilha.size() << std::endl;
	pilha.push(3);
	std::cout << "Pilha: size=" << pilha.size() << std::endl;
	while (!pilha.empty()) {
		int i = pilha.top();
		pilha.pop();
		std::cout << "i = " << i << " size=" << pilha.size() << std::endl;
	}
}

int main (int ac, char **av) {
	/* Recursive function */
	if (1) {
		std::cout << "Recursive:" << std::endl;
		auto start = std::chrono::system_clock::now();
		for (int m = 0; m < LIMIT_M; m++) {
			for (int n=0; n<LIMIT_N; n++) {
				std::cout << "Ackermann(" << m << "," << n << ") = " << ackermann_recursive(m,n) << '\t' << std::flush;
			}
			std::cout << std::endl;
		}
		auto end = std::chrono::system_clock::now();
    		std::chrono::duration<double> elapsed_seconds = end-start;
    		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	}


	/* Iterative C */
	if (1) {
		std::cout << "Iterative C:" << std::endl;
		auto start = std::chrono::system_clock::now();
		for (int m = 0; m < LIMIT_M; m++) {
			for (int n=0; n<LIMIT_N; n++) {
				std::cout << "Ackermann(" << m << "," << n << ") = " << ackermann_iterative(m,n) << '\t' << std::flush;
			}
			std::cout << std::endl;
		}

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	}


	/* Iterative ASM */
	if (1) {
		std::cout << "Iterative ASM:" << std::endl;
		auto start = std::chrono::system_clock::now();
		for (int m = 0; m < LIMIT_M; m++) {
			for (int n=0; n<LIMIT_N; n++) {
				std::cout << "Ackermann(" << m << "," << n << ") = " << ackermann_iterative_asm(m,n) << '\t' << std::flush;
			}
			std::cout << std::endl;
		}

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	}




	return 0;
}
