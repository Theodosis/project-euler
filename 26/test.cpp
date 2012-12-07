#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>

using namespace std;

int main(){
    typedef string::const_iterator iterator;
    string s("3333333333333333333");
    set<string> found;

    for (iterator i = s.begin() + 1, j = s.end(); i != j; ++i) {
        for (iterator x = s.begin(); x != i; ++x) {
            iterator tmp = mismatch(i, j, x).second;;
            if (tmp - x > 1){
                found.insert(string(x, tmp));
            }
        }
    }

    copy(found.begin(), found.end(),ostream_iterator<string>(cout, "\n"));
}
