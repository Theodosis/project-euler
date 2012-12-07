THIS IS CRAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int isPandigital( int a, int b, int c ){
    int is = 1;
    char a1[ 10 ];
    char b1[ 10 ];
    char c1[ 10 ];
    sprintf( a1, "%d", a );
    sprintf( b1, "%d", b );
    sprintf( c1, "%d", c );
    char req[] = "0123456789";
    for( int i = 0; i < 10; ++i ){
        if( !strstr( a1, req[ i ] ) &&
            !strstr( b1, req[ i ] ) &&
            !strstr( c1, req[ i ] ) ){
            is = 0;
            break;
        }
    }

    return is;
}

int main(){
    
    printf( "%d", isPandigital( 1234567,8,9 ) );
    return 0;


    for( int i = 1; i < 10000; ++i ){
        for( int j = 1; j < 10000; ++j ){
            
        }
    }
}
