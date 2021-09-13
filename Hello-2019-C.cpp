/*************************************************************************
	> File Name: Hello-2019-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月05日 星期六 11时47分37秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
int a[maxn], b[maxn];
stack<char> st;

int main(){
	int n;
	cin >> n;
	string s;
	int ans = 0;
	while(n--){
		cin >> s;
		for(char &x : s){
			if(st.empty()) st.push(x);
			else if(x == ')' && st.top() == '('){
				st.pop();
			}else st.push(x);
		}int x=0, y=0;
		while(!st.empty()){
			if(st.top() == '(') x++;
			else y++;
			st.pop();
		}if(x+y==0) ans++;
		else if(!x||!y) a[x]++,b[y]++;
	}ans /= 2;
	for(int i = 1; i < maxn; ++i)
		ans += min(a[i], b[i]);
	cout << ans << endl;
}
