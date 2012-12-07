#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char arr[ 1000 ];
    int sum = 0;
    mpz_t num;
    mpz_init_set_str( num, "2", 10 );
    mpz_pow_ui( num, num, 1000 );
    mpz_get_str( arr, 10, num );

    
    for( int i = 0; i < strlen( arr ); ++i ){
        sum += arr[ i ] - 48;
    }
    printf( "%d\n", sum );
}
