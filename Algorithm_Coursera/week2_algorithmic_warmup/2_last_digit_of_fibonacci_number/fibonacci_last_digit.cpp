#include <iostream>

typedef long long int ll;


int get_fibonacci_last_digit_naive(int n) {
	if (n <= 1)
		return n;

	int previous = 0;
	int current  = 1;

	for (int i = 0; i < n - 1; ++i) {
		int tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % 10;
}

ll fib(ll f[], ll n){
	f[0] = 0;
	f[1] = 1;

	for(ll i = 2; i<=n ;i++){
		f[i] = (f[i-1] + f[i-2]) %10;

	}

	return f[n];

}


int get_fibonacci_last_digit_new(int n){
	ll f[60] = {0};

	fib(f,60);

	return f[n%60];
}



int main() {
	int n;
	std::cin >> n;
	int c = get_fibonacci_last_digit_new(n);
	std::cout << c << '\n';
}
