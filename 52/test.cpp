#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class ForwardIt1, class ForwardIt2>
bool is_permutation(ForwardIt1 first, ForwardIt1 last,
                    ForwardIt2 d_first)
{
   // skip common prefix
//   std::tie(first, d_first) = std::mismatch(first, last, d_first);
   // iterate over the rest, counting how many times each element
   // from [first, last) appears in [d_first, d_last)
   if (first != last) {
       ForwardIt2 d_last = d_first;
       std::advance(d_last, std::distance(first, last));
       for (ForwardIt1 i = first; i != last; ++i) {
            if (i != std::find(first, i, *i)) continue; // already counted this *i
 
            int m = std::count(d_first, d_last, *i);
            if (m==0 || std::count(i, last, *i) != m) {
                return false;
            }
        }
    }
    return true;
}

string IntToStr( int n ){
    ostringstream r;
    r << n;
    return r.str();
}
int StrToInt( const string& s ){
    int r;
    istringstream ss( s );
    ss >> r;
    return r;
}

int main(){
    int i = 1;
    string x, x2, x3, x4, x5, x6;
    do{
        ++i;
        x = IntToStr( i );
        x2 = IntToStr( i * 2 );
        x3 = IntToStr( i * 3 );
        x4 = IntToStr( i * 4 );
        x5 = IntToStr( i * 5 );
        x6 = IntToStr( i * 6 );
        if( x6.size() == x.size() &&
            is_permutation( x.begin(), x.end(), x2.begin() ) &&
            is_permutation( x.begin(), x.end(), x3.begin() ) &&
            is_permutation( x.begin(), x.end(), x4.begin() ) &&
            is_permutation( x.begin(), x.end(), x5.begin() ) &&
            is_permutation( x.begin(), x.end(), x6.begin() ) ){

            cout << i << endl;
            return 0;
        }
    } while( true );
}
