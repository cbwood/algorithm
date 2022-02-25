#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <string>

using namespace std;
typedef long long LL;
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;


#define exp(s) printf("test s is:%s\n",s)
#define exp1(s) printf("test s is:%s\n",#s)
#define exp2(s) #s

int main() {
    exp("hello");
    exp1(hello);

    string str = exp2(bac);
    cout << str << " " << str.size() << endl;
    /**
     * 忽略传入参数名前面和后面的空格。
     */
    string str1 = exp2(asda bac);
    /**
     * 当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
     * 用每个子字符串之间以一个空格连接，忽略剩余空格。
     */
    cout << str1 << " " << str1.size() << endl;
    return 0;
}

