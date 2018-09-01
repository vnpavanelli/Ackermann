#include <iostream>
#include <stack>
#include <vector>
#include <chrono>
#include <string>

const bool DEBUG = false;
const unsigned int LIMIT_M = 4;
const unsigned int LIMIT_N = 14;
typedef unsigned int (*f_ptr)(unsigned int, unsigned int);

struct _f {
	f_ptr funcao;
	std::string nome;
};

typedef std::chrono::duration<double> tempo;

unsigned int ackermann_recursive(unsigned int, unsigned int);
unsigned int ackermann_iterative(unsigned int, unsigned int);
extern "C" unsigned int ackermann_iterative_asm(unsigned int, unsigned int);
extern "C" unsigned int ackermann_iterative_asm2(unsigned int, unsigned int);

tempo bench( const _f &f, unsigned int m, unsigned int n) {
	auto start = std::chrono::system_clock::now();
	auto resposta = f.funcao(m,n);
	auto end = std::chrono::system_clock::now();
//	std::cout << f.nome << "(" << m << "," << n << ") = " << resposta << '\t' << std::flush;
	std::chrono::duration<double> elapsed_seconds = end-start;
//	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return elapsed_seconds;
}

int main (int ac, char **av) {
//	std::cout << ackermann_iterative_asm2(1,1);
	std::vector<_f> funcoes = {
		{ ackermann_recursive, "recursiva" },
		{ ackermann_iterative, "iterativa" },
		{ ackermann_iterative_asm, "asm1" },
		{ ackermann_iterative_asm2, "asm2" }
	};
	std::cout << std::endl << "(m,n)\t";
	for (auto &i : funcoes) std::cout << i.nome << "\t";
	std::cout << std::endl;
	for (int m = 0; m < LIMIT_M; m++) {
		for (int n = 0; n < LIMIT_N; n++) {
			std::cout << "(" << m << "," << n << ")" << std::flush;
			for (auto &i : funcoes) {
				std::cout << "\t" << bench(i, m, n).count() << std::flush;
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
