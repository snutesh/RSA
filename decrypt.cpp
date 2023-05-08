#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

int main(int argc, char const *argv[])
{
	mpz_t n, e, d, M, C;
	mpz_init(n); mpz_init(e); mpz_init(d);
	mpz_init(M); mpz_init(C);
	mpz_set_str(n, argv[1], 10);
	mpz_set_str(d, argv[2], 10);
	mpz_set_str(C, argv[3], 10);
	mpz_powm(M, C, d, n);
	cout << "\n" << mpz_get_str(NULL, 10, M) << "\n\n";
	return 0;
}