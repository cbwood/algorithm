#include "bits/stdc++.h"

using namespace std;

class b {
public:
    b();

    virtual ~b();

private:
    short a;
    char dd;
    int c;
    char *p;
};

int main() {
    cout << sizeof(b) << endl;
    return 0;
}