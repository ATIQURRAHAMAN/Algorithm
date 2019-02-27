#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<pair<pii,int> > v[100];
int dis[100];

bool bellman_ford(int src,int V,int E){
    memset(dis,10000,sizeof(dis));
    dis[src] =  0;
    for(int i = 0; i<=V-1; i++){
        for(int j = 0; j<E; j++){
            vector<pair<pii,int> > ::iterator it;
            it = v[j].begin();
            int src = (*it).first.first;
            int dist = (*it).first.second;
            int w = (*it).second;
            if(dis[src]!=10000 && dis[src] + w < dis[dist]){
                dis[dist] = dis[src] + w;
            }
        }
    }

    for(int i = 0; i < E ;i++){
            vector<pair<pii,int> > ::iterator it;
            it = v[i].begin();
            int src = (*it).first.first;
            int dist = (*it).first.second;
            int w = (*it).second;
            if(dis[src]!=10000 && dis[src] + w < dis[dist]){
                return true;
            }
    }
    return false;
}

int main(){
  int a,b,c,V,dist,E;
  int edge = 0;
  fstream f1("in.txt");
  f1 >> V;
  f1 >> E;
  for(int i = 0; i < E; i++){

         f1 >> a >> b >> c;
      v[edge++].push_back(make_pair(pii(a,b),c));
  }

  if(bellman_ford(1,V,edge)){
      cout<<"Negative cycle detected"<<endl;
  }
  else{
      while(scanf("%d",&dist)!=EOF){
          printf("%d - > %d: %d\n",1,dist,dis[dist]);
      }
  }
  return 0;
}
