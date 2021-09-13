#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
    bool solve(string s, string p, int sx, int sp){
        int slen =s.length(), plen = p.length();
        if(sx == slen){
            if(sp == plen)
                return true;
            if(sp == plen -1) return false;
            for(int i = sp+1; i < plen; ++i)
                if(p[i] != '*')
                    return false;
            return true;
        }
        if(sp == plen){
            if(sx == slen)
                return true;
            return false;
        }
        char ch;
        while(sx < slen && sp < plen){
            if(p[sp] == '.'){
                sx++,sp++;
                ch = s[sx-1];
                if(sp < plen && p[sp] =='*'){
                    if(sp == plen-1) return true;
                    for(int i = 0; sx + i < slen; ++i)
                        if(solve(s, p, sx+i, sp+1))
                            return true;
                }
            }else if(p[sp] != '*'){
                if(sp == plen -1){
                    if(s[sx] != p[sp] || sx != slen -1)
                        return false;
                    return true;
                }if(p[sp+1] != '*'){
                    if(s[sx] != p[sp])
                        return false;
                    return solve(s, p, sx+1, sp+1);
                }
                ch = p[sp];
                for(int i = 0; i < slen-sx; i++){
                    if(s[sx+i] == ch){
                        if(solve(s, p, sx+i+1, sp+2))
                            return true;
                    }else return solve(s, p, sx, sp+2);
                }
            }else {
                for(int i = 0; i < slen-sx; i++){
                    if(s[sx+i] == ch){
                        if(solve(s, p, sx+i+1, sp+1))
                            return true;
                    }else return solve(s, p, sx, sp+1);
                }
            }
        }return solve(s, p, sx, sp);
    }
};

int main(){
    Solution s;
    string ss,pp;
    ss = "a";
    pp = "ab*";
    cout << s.isMatch(ss, pp) << endl;
}
