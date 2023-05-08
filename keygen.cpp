#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

int main(int argc, char const *argv[])
{
    mpz_t n, e, d, p, q, phi, tmp1, tmp2;
    mpz_init(n); mpz_init(e); mpz_init(d);
    mpz_init(p); mpz_init(q); mpz_init(phi);
    mpz_init(tmp1); mpz_init(tmp2);

    mpz_set_str(p, argv[1], 10);
    mpz_set_str(q, argv[2], 10);

    mpz_mul(n, p, q);
    mpz_sub_ui(tmp1, p, 1);
    mpz_sub_ui(tmp2, q, 1);
    mpz_mul(phi, tmp1, tmp2);

    mpz_set_ui(e, 3);
    mpz_gcd(tmp1, e, phi);
    while (!(mpz_cmp_ui(tmp1, 1) == 0))
    {
        mpz_nextprime(e, e);
        mpz_gcd(tmp1, e, phi);
    }
    if (mpz_invert(d, e, phi) == 0)
    {
        mpz_gcd(tmp1, e, phi);
        printf("gcd(e, phi) = %s\n", mpz_get_str(NULL, 10, tmp1));
        printf("Invert failed\n");
    }
    cout << "\nPublic Key: (" << mpz_get_str(NULL, 10, n) << "," << mpz_get_str(NULL, 10, e) << ")\n";
    cout << "Private Key: (" << mpz_get_str(NULL, 10, n) << "," << mpz_get_str(NULL, 10, d) << ")\n\n";
    return 0;
}