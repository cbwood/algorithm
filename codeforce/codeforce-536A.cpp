/*************************************************************************
	> File Name: codeforce-536A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月31日 星期四 20时36分47秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;
char s[maxn][maxn];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf(" %s", s[i]+1);
	int ans = 0;
	for(int i = 2; i < n; ++i)
		for(int j = 2; j < n; ++j)
			if(s[i][j] == s[i-1][j-1] && s[i][j] == s[i-1][j+1] && s[i][j] == s[i+1][j+1]
					&& s[i][j] == s[i+1][j-1] && s[i][j] == 'X')
				ans++;
	printf("%d\n", ans);
	return 0;
}
