#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


double dis(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int cmp(pair<double, pair<int,int> > &a, pair<double, pair<int,int> > &b){
    return a.first < b.first;
}
int getParent(int a,int *set){
    if(a==set[a])return a;
    return set[a]=getParent(set[a],set);
}
int sameParent(int a,int b,int *set){
    return getParent(a,set)==getParent(b,set);
}
void makeSParent(int a,int b, int *set){
    set[getParent(a,set)]=getParent(b,set);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll s,p;
        cin>>s>>p;
        
        vector<pair<int,int> > cord;
        vector<pair<double ,pair<int,int> > >tree;
        
        for(int i=0;i<p;i++){
            int x,y;
            cin>>x>>y;
            cord.push_back({x,y});
            
        }
        
            for(int i=0;i<cord.size();i++){
                for(int j=i+1;j<cord.size();j++){
                    tree.push_back({dis(cord[i].first, cord[i].second, cord[j].first, cord[j].second), {i+1,j+1}});
                }
            }
            
            int parent[501];
            for(int i=1;i<=p;i++){
                parent[i]=i;
            }
            sort(tree.begin(),tree.end(),cmp);
            int count=p;
            double d=0;
            for(int i=0;i<tree.size()&& count!=s;i++){
                if(!sameParent(tree[i].second.first,tree[i].second.second,parent)){
                    count--;
                    d=tree[i].first;
                    makeSParent(tree[i].second.first,tree[i].second.second, parent);
                }
            }
            
            printf("%.2lf\n",d);
            
        
    }
}