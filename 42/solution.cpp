#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int NumberIsTriangle( int num ){
    int n = 1, term = 1;
    while( term < num ){
        ++n;
        term = n * ( n + 1 ) / 2;
    }
    return term == num;
}
int WordIsTriangle( string word ){
    const char *temp = word.c_str();
    int total = 0;
   
    for( int i = 0; i < strlen( temp ); ++i ){
        total += temp[ i ] - 64;
    }
    //cout << total;
    return NumberIsTriangle( total );
}

int main(){
    vector<string> words;
    string str;
    ifstream file( "words.txt" );
    int total = 0;

    getline( file, str );

    split( words, str, is_any_of( "," ) );
    
    for( int i = 0; i < words.size(); ++i ){
        //cout << endl << words[ i ].substr( 1, words[ i ].length() - 2 ) << " -> ";
        if( WordIsTriangle( words[ i ].substr( 1, words[ i ].length() - 2 ) ) ){
            ++total;
        //    cout << " is triangle";
        }
    }
    cout << total << endl;
}
