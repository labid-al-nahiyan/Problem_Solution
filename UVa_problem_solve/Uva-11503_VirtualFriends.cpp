#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map<string,string>mp;
map<string , int> ranks;

string find_parent(string str){
    if(str==mp[str])return str;

    return mp[str]=find_parent(mp[str]);
    
}

int solve(string s1,string s2){
    s1=find_parent(s1);
    s2=find_parent(s2);
    if(s1==s2)return ranks[s1];
    if(ranks[s1]>ranks[s2])swap(s1,s2);
    mp[s1]=s2;
    if(ranks[s1]<=ranks[s2])ranks[s2]+=ranks[s1];
    
    return max(ranks[s1],ranks[s2]);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        ranks.clear();
        long long d;
        cin>>d;
        while(d--){
            string s1,s2;
            cin>>s1>>s2;
            if(mp.count(s1)==0){
                mp[s1]=s1;
                ranks[s1]=1;
            }
            if(mp.count(s2)==0){
                mp[s2]=s2;
                ranks[s2]=1;
            }
            cout<<solve(s1,s2)<<'\n';
        }
    }
}