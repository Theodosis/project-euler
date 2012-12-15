#include <iostream>
#include <stdlib.h>
#include <gmp.h>
using namespace std;

int main(){
    mpz_t sum, temp, limit;
    mpz_init_set_str( sum, "0", 10 );
    mpz_init( temp );
    mpz_init_set_str( limit, "10000000000", 10 );
    
    for( int i = 1; i <= 1000; ++i ){
        mpz_ui_pow_ui( temp, i, i );
//        cout << i << " ^ " << i << " = " << temp;
        mpz_add( sum, sum, temp );
//        cout << " total: " << sum << endl;
    }
    mpz_mod( temp, sum, limit );
    cout << temp << endl;
    
    return 0;
}
