

unsigned int ackermann_recursive(unsigned int m, unsigned int n) {
	if (m==0) return (n+1);
	if (n==0) return ackermann_recursive(m-1,1);
	return ackermann_recursive(m-1, ackermann_recursive(m,n-1));
}


