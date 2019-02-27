#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
vector<pi> vi[100];
int dist[100];

void disktra(int src)
{
    memset(dist,10000,sizeof(dist));
    dist[src] = 0;

   priority_queue<pi,vector<pi> ,greater<pi> > pq;
   pq.push(make_pair(0,src));

   while(!pq.empty())
   {
       pi p = pq.top();
       pq.pop();
       vector<pi>::iterator it;

       int u = p.second;

       for(it = vi[u].begin();it!=vi[u].end();it++)
       {
       	 int dis = (*it).second;
       	 int cost = (*it).first;
       	 if(dist[u] + cost < dist[dis])
       	 {
       	   dist[dis] = dist[u] + cost;
       	   pq.push(make_pair(dist[dis],dis));
       	 }
       }
   }
}


int main()
{


  int u,v,c;
  int  src,dis;
  int vertex,edge;
  fstream f1("in.txt");
  f1 >> vertex;
  f1 >> edge;

  for(int i = 1; i<=edge; i++)
  {
  	 f1 >> u >> v >> c;

  	 vi[u].push_back(make_pair(c,v));
  }



   disktra(2);

  while( cin >> dis)
  {
          printf("%d - > %d : %d\n",2,dis,dist[dis]);
  }


  return 0;

}
