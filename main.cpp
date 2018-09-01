#include <iostream>
#include <stack>
#include <vector>
#include <chrono>
#include <string>

const bool DEBUG = false;
const unsigned int LIMIT_M = 2;
const unsigned int LIMIT_N = 10;
typedef unsigned int (*f_ptr)(unsigned int, unsigned int);

struct _f {
	f_ptr funcao;
	std::string nome;
};

struct _r {
	std::chrono::duration<double> seconds;
	unsigned int value;
};

unsigned int ackermann_recursive(unsigned int, unsigned int);
unsigned int ackermann_iterative(unsigned int, unsigned int);
unsigned int ackermann_iterative2(unsigned int, unsigned int);
extern "C" unsigned int ackermann_iterative_asm(unsigned int, unsigned int);
extern "C" unsigned int ackermann_iterative_asm2(unsigned int, unsigned int);

_r bench( const _f &f, unsigned int m, unsigned int n) {
	auto start = std::chrono::system_clock::now();
	auto resposta = f.funcao(m,n);
	auto end = std::chrono::system_clock::now();
//	std::cout << f.nome << "(" << m << "," << n << ") = " << resposta << '\t' << std::flush;
	std::chrono::duration<double> elapsed_seconds = end-start;
//	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	_r r;
	r.seconds = elapsed_seconds;
	r.value = resposta;
	return r;
}

int main (int ac, char **av) {
//	std::cout << ackermann_iterative_asm2(1,1);
	std::vector<_f> funcoes = {
		{ ackermann_recursive, "recursiva" },
		{ ackermann_iterative, "iterativa" },
		{ ackermann_iterative2, "iterativa2" },
		{ ackermann_iterative_asm, "asm1" },
		{ ackermann_iterative_asm2, "asm2" }
	};
	std::cout << std::endl << "(m,n)\t";
	for (auto &i : funcoes) std::cout << i.nome << "\t";
	std::cout << "\tValue" << std::endl;
	for (int m = 0; m < LIMIT_M; m++) {
		for (int n = 0; n < LIMIT_N; n++) {
			std::cout << "(" << m << "," << n << ")" << std::flush;
			bool first = true;
			unsigned int value=0;
			for (auto &i : funcoes) {
				_r tmp = bench(i, m, n);
				std::cout << "\t" << tmp.seconds.count() << std::flush;
				if (first) {
					value = tmp.value;
					first = false;
				} else {
					if (value != tmp.value) {
						std::cout << "X" << std::flush;
					}
				}
			}
			std::cout << "\t" << value << std::endl;
		}
	}

	return 0;
}
