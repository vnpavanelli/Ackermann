#include <iostream>

unsigned int ackermann_recursive(unsigned int m, unsigned int n) {
	if (m==0) return (n+1);
	if (n==0) return ackermann_recursive(m-1,1);
	return ackermann_recursive(m-1, ackermann_recursive(m,n-1));
}

int main (int ac, char **av) {
	int m,n;
	for (int m = 0; m < 10; m++) {
		for (int n=0; n<4; n++) {
			std::cout << "Ackermann(" << m << "," << n << ") = " << ackermann_recursive(m,n) << '\t' << std::flush;
		}
		std::cout << std::endl;
	}
	return 0;
}
