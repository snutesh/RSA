#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <time.h>
#include "primecheck.h"

using namespace std;

int main(int argc, char const *argv[])
{
    bool r = false;
    const auto n_bits = atoi(argv[1]);
    mpz_t mpz_int;
    do
    {
        gmp_randstate_t state;
        mpz_init(mpz_int);
        gmp_randinit_default(state);
        gmp_randseed_ui(state, (unsigned int)time(NULL));
        mpz_rrandomb(mpz_int, state, n_bits);
        r = miller_rabin(mpz_class(mpz_get_str(nullptr, 10, mpz_int)));
    } while (!r);
    cout << "\n" << mpz_get_str(nullptr, 10, mpz_int) << "\n" << endl;
    return 0;
}