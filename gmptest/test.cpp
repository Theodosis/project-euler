#include <iostream>
#include <stdlib.h>
#include <gmp.h>
using namespace std;

 void foo(){
    mpz_t n;
    int i;
    mpz_init (n);
    mpz_set_str( n, "2", 10 );
    mpz_mul ( n, n, n );
    cout << n;
    mpz_clear (n);
}

int main(){
    foo();
    return 0;
}
