#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fib(long long n, long long m){
	long long f[n+1];

	f[0] = 0;
	f[1] = 1;

	for(long long i = 2; i<=n ;i++){
		f[i] = (f[i-1] + f[i-2])%m;

	}

	return f[n];

}
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fib(n, m) << '\n';
}
