//
// Created by cb on 2021/9/24.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"
using namespace std;


class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unordered_map<string, int> ma;
        unordered_map<string, string> mb;
        for(auto &x: names) {
            size_t pos = x.find('(');
            ma[x.substr(0, pos)] = std::stoi(x.substr(pos+1,x.size()-pos-2));
        }
        for(auto &x: synonyms){
            size_t pos = x.find(',');
            string n1 = x.substr(1, pos-1);
            string n2 = x.substr(pos+1, x.size()-pos-2);
            if(n1 > n2){
                swap(n1, n2);
            }
            cout<<"1 xx "<<n2<<endl;
            string t1 = n1, t2 = n2;
            while(!mb[n2].empty()){
                n2 = mb[n2];
                cout<<1<<" "<<n2<<endl;
            }
            cout<<"2 xx "<<n1<<endl;
            while(!mb[n1].empty()){
                n1 = mb[n1];
                cout<<2<<" "<<n1<<endl;
            }
            if(t1 > n1)
                mb[t1] = n1;
            else if (t1 < n1)
                mb[n1] = t1;
            if(t2 > n2)
                mb[t2] = n2;
            else if(t2 < n2)
                mb[n2] = t2;
            if(n1 < n2){
                mb[n2] = n1;
                ma[n1] += ma[n2];
                ma.erase(n2);
            }else if(n1 > n2){
                ma[n2] += ma[n1];
                ma.erase(n1);
                mb[n1] = n2;
            }
        }
        vector<string> ans;
        for(auto &x: ma){
            string tmp = x.first+"(" +to_string(x.second)+")";
            ans.push_back(tmp);
        }
        return ans;

    }
};
/*
 * ["Pwsuo(71)","Prf(48)","Rgbu(49)","Zvzm(31)","Xxcl(25)","Bbcpth(42)","Padz(70)","Jmqqsj(19)","Uwy(26)","Jylbla(65)","Xioal(11)","Npbu(62)","Jpftyg(96)","Tal(46)","Hnc(100)","Yldu(85)","Alqw(45)","Wbcxi(34)","Kxjw(36)","Clplqf(8)","Fayxe(66)","Slfwyo(48)","Xbesji(70)","Pmbz(22)","Oip(2)","Fzoe(63)","Qync(79)","Utc(11)","Sqwejn(19)","Ngi(8)","Gsiiyo(60)","Bcs(73)","Icsvku(1)","Yzwm(92)","Vaakt(21)","Uvt(70)","Axaqkm(100)","Gyhh(84)","Gaoo(98)","Ghlj(35)","Umt(13)","Nfimij(52)","Zmeop(77)","Vje(29)","Rqa(47)","Upn(89)","Zhc(44)","Slh(66)","Orpqim(69)","Vxs(85)","Gql(19)","Sfjdjc(62)","Ccqunq(93)","Oyo(32)","Bvnkk(52)","Pxzfjg(45)","Kaaht(28)","Arrugl(57)","Vqnjg(50)","Dbufek(63)","Fshi(62)","Lvaaz(63)","Phlto(41)","Lnow(70)","Mqgga(31)","Adlue(82)","Zqiqe(27)","Mgs(46)","Zboes(56)","Dma(70)","Jnij(57)","Ghk(14)","Mrqlne(39)","Ljkzhs(35)","Rmlbnj(42)","Qszsny(93)","Aasipa(26)","Wzt(41)","Xuzubb(90)","Maeb(56)","Mlo(18)","Rttg(4)","Kmrev(31)","Kqjl(39)","Iggrg(47)","Mork(88)","Lwyfn(50)","Lcp(42)","Zpm(5)","Qlvglt(36)","Liyd(48)","Jxv(67)","Xaq(70)","Tkbn(81)","Rgd(85)","Ttj(28)","Ndc(62)","Bjfkzo(54)","Lqrmqh(50)","Vhdmab(41)"]
["(Uvt,Rqa)","(Qync,Kqjl)","(Fayxe,Upn)","(Maeb,Xaq)","(Pmbz,Vje)","(Hnc,Dma)","(Pwsuo,Gyhh)","(Gyhh,Aasipa)","(Fzoe,Lcp)","(Mgs,Vhdmab)","(Qync,Rgd)","(Gql,Liyd)","(Gyhh,Tkbn)","(Arrugl,Adlue)","(Wbcxi,Slfwyo)","(Yzwm,Vqnjg)","(Lnow,Vhdmab)","(Lvaaz,Rttg)","(Nfimij,Iggrg)","(Vje,Lqrmqh)","(Jylbla,Ljkzhs)","(Jnij,Mlo)","(Adlue,Zqiqe)","(Qync,Rttg)","(Gsiiyo,Vxs)","(Xxcl,Fzoe)","(Dbufek,Xaq)","(Ccqunq,Qszsny)","(Zmeop,Mork)","(Qync,Ngi)","(Zboes,Rmlbnj)","(Yldu,Jxv)","(Padz,Gsiiyo)","(Oip,Utc)","(Tal,Pxzfjg)","(Adlue,Zpm)","(Bbcpth,Mork)","(Qync,Lvaaz)","(Pmbz,Qync)","(Alqw,Ngi)","(Bcs,Maeb)","(Rgbu,Zmeop)"]
 */

int main(){
    vector<string> names={"Pwsuo(71)","Prf(48)","Rgbu(49)","Zvzm(31)","Xxcl(25)","Bbcpth(42)","Padz(70)","Jmqqsj(19)","Uwy(26)","Jylbla(65)","Xioal(11)","Npbu(62)","Jpftyg(96)","Tal(46)","Hnc(100)","Yldu(85)","Alqw(45)","Wbcxi(34)","Kxjw(36)","Clplqf(8)","Fayxe(66)","Slfwyo(48)","Xbesji(70)","Pmbz(22)","Oip(2)","Fzoe(63)","Qync(79)","Utc(11)","Sqwejn(19)","Ngi(8)","Gsiiyo(60)","Bcs(73)","Icsvku(1)","Yzwm(92)","Vaakt(21)","Uvt(70)","Axaqkm(100)","Gyhh(84)","Gaoo(98)","Ghlj(35)","Umt(13)","Nfimij(52)","Zmeop(77)","Vje(29)","Rqa(47)","Upn(89)","Zhc(44)","Slh(66)","Orpqim(69)","Vxs(85)","Gql(19)","Sfjdjc(62)","Ccqunq(93)","Oyo(32)","Bvnkk(52)","Pxzfjg(45)","Kaaht(28)","Arrugl(57)","Vqnjg(50)","Dbufek(63)","Fshi(62)","Lvaaz(63)","Phlto(41)","Lnow(70)","Mqgga(31)","Adlue(82)","Zqiqe(27)","Mgs(46)","Zboes(56)","Dma(70)","Jnij(57)","Ghk(14)","Mrqlne(39)","Ljkzhs(35)","Rmlbnj(42)","Qszsny(93)","Aasipa(26)","Wzt(41)","Xuzubb(90)","Maeb(56)","Mlo(18)","Rttg(4)","Kmrev(31)","Kqjl(39)","Iggrg(47)","Mork(88)","Lwyfn(50)","Lcp(42)","Zpm(5)","Qlvglt(36)","Liyd(48)","Jxv(67)","Xaq(70)","Tkbn(81)","Rgd(85)","Ttj(28)","Ndc(62)","Bjfkzo(54)","Lqrmqh(50)","Vhdmab(41)"};
    vector<string> synonyms={"(Uvt,Rqa)","(Qync,Kqjl)","(Fayxe,Upn)","(Maeb,Xaq)","(Pmbz,Vje)","(Hnc,Dma)","(Pwsuo,Gyhh)","(Gyhh,Aasipa)","(Fzoe,Lcp)","(Mgs,Vhdmab)","(Qync,Rgd)","(Gql,Liyd)","(Gyhh,Tkbn)","(Arrugl,Adlue)","(Wbcxi,Slfwyo)","(Yzwm,Vqnjg)","(Lnow,Vhdmab)","(Lvaaz,Rttg)","(Nfimij,Iggrg)","(Vje,Lqrmqh)","(Jylbla,Ljkzhs)","(Jnij,Mlo)","(Adlue,Zqiqe)","(Qync,Rttg)","(Gsiiyo,Vxs)","(Xxcl,Fzoe)","(Dbufek,Xaq)","(Ccqunq,Qszsny)","(Zmeop,Mork)","(Qync,Ngi)","(Zboes,Rmlbnj)","(Yldu,Jxv)","(Padz,Gsiiyo)","(Oip,Utc)","(Tal,Pxzfjg)","(Adlue,Zpm)","(Bbcpth,Mork)","(Qync,Lvaaz)","(Pmbz,Qync)","(Alqw,Ngi)","(Bcs,Maeb)","(Rgbu,Zmeop)"};
    Solution so;
    vector<string> ans = so.trulyMostPopular(names, synonyms);
    for(auto &x: ans)
        cout<<x<<endl;
}