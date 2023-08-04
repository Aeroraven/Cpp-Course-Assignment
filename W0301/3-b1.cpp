#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool func(vector<int> a) {
    int sz = a.size();
    if (sz == 0)return false;
    for (int i = 0; i < sz; i++) {
        int lfind = 0, lval = 0;
        int rfind = 0, rval = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (lfind == 0) {
                    lfind = 1;
                    lval = a[j];
                }
                else {
                    if (a[j] < lval) {
                        lval = a[j];
                    }
                }
            }
        }
        if (lfind == 0)continue;
        for (int j = i + 1; j < sz; j++) {
            if (a[j] > lval && a[j] < a[i]) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cout << func({ 1,4,0,1 });
}

