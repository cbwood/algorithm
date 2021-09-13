/*************************************************************************
	> File Name: HDU-6440.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月26日 星期日 18时56分19秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c = getchar(),c == EOF) return 0; //EOF
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c-'0');
    while(c = getchar(),c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x) {
	if(x > 9) out( x / 10);
	putchar( x % 10 + '0');
}

int main(){
	int p,t;
	scan_d(t);
	while(t--){
		scan_d(p);
		for(int i = 0; i < p; ++i){
			for(int j = 0; j < p-1; ++j)
				out((i+j)%p),putchar(' ');
			out((i+p-1)%p);puts("");
		}
		for(int i = 0; i < p; ++i){
			for(int j = 0; j < p-1; ++j)
				out((i*j)%p),putchar(' ');
			out(i*(p-1)%p);puts("");
		}
	}
}
