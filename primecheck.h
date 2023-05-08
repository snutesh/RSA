#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

mpz_class exp_one(mpz_class a, mpz_class b, mpz_class c) {
    mpz_class r;
    mpz_powm(r.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t(), c.get_mpz_t());
    return r;
}

mpz_class exp_two(mpz_class a, mpz_class b) {
    mpz_class r, c;
    c = 2;
    mpz_powm(r.get_mpz_t(), a.get_mpz_t(), c.get_mpz_t(), b.get_mpz_t());
    return r;
}

mpz_class mr_check_one(mpz_class n) {
    if (n % 2 != 0) {
        return 0;
    }
    n = n - 1;
    while (n % 2 == 0) {
        n = n / 2;
    }
    return n;
}

mpz_class mr_check_two(mpz_class m, mpz_class n) {
    mpz_class b, u, j, d;
    u = n - 1;
    j = 0;
    d = 2;
    b = exp_one(d, m, n);
    if (b == u or b == 1) {
        return 0;
    }
    while (b != u and j < 7) {
        b = exp_two(b, n);
        j++;
    }
    if (b == u) {
        return 0;
    } else {
        return 1;
    }
}

bool miller_rabin(mpz_class n) {
    mpz_class r;
    r = mr_check_one(n);
    r = mr_check_two(r, n);
    if (r == 0) {
        return true;
    }
    return false;
}