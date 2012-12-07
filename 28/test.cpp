#include <stdio.h>

int main(){
    int i, j, sum = 1, pad = 2, c = 1;
    for( i = 0; i < 500; ++i ){
        for( j = 0; j < 4; ++j ){
            c += pad;
            sum += c;
            //printf( "%d + ", c );
        }
        pad += 2;
    }

    printf( "%d\n", sum );
}
