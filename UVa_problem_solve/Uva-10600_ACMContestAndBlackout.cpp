#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<long long,pair<int,int> > &a, pair<long long,pair<int,int> > &b){
	return a.first<b.first;
}
//Set parent
int getFather(int a,int* setFather){
	if(a==setFather[a])return a;
	else{
		return setFather[a]=getFather(setFather[a],setFather);
	}
}
// Check for avoid cycle
int isSameFather(int a,int b,int* setFather){
	return getFather(a,setFather)==getFather(b,setFather);
}
//For avoid cycle
void makeSameFather(int a,int b,int* setFather){
	setFather[getFather(a,setFather)]=getFather(b,setFather);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n,m;
		  cin>>n>>m;
		  vector<pair<long long,pair<int,int> > > diss;
		
		  for(int i=0;i<m;i++){
			    int a,b,c;
			    cin>>a>>b>>c;
				  diss.push_back({c,{a,b}});	
		  }
		  sort(diss.begin(),diss.end(),cmp);
		
		  int setFather[1009];
		  for(int i=1;i<=n;i++){
			  setFather[i]=i;
		  }
		  long long road=0,sum=0,sum1=1000007;
		
		  vector<long long> used;
		  for(int i=0;i<diss.size()&& road<n-1;i++){
			  if(!isSameFather(diss[i].second.first,diss[i].second.second,setFather)){
				  road++;
				  used.push_back(i);
				  sum+=diss[i].first;
				  makeSameFather(diss[i].second.first,diss[i].second.second,setFather);
			  }
		  }
		  cout<<sum<<' ';
		  road=0;
		  if(m==n-1)cout<<sum<<'\n';
		  else{    
		    for(int k=0;k<used.size();k++){
		      long long temp=0;
		      road=0;
		      for(int i=1;i<=n;i++){
			      setFather[i]=i;
		      }
		      for(int i=0;i<diss.size()&&road<n-1;i++){
			      if(!isSameFather(diss[i].second.first,diss[i].second.second,setFather)&& i!=used[k]){
				      road++;
				      temp+=diss[i].first;
				      makeSameFather(diss[i].second.first,diss[i].second.second,setFather);
			      }
		      }   
          if(road!=n-1)continue;
		      sum1=min(sum1,temp);
		    }
		    cout<<sum1<<'\n';
	    }
		}
}