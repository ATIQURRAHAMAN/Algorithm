#include<bits/stdc++.h>
#define pii pair<int,int>
#define vipii vector<int,pii>
using namespace std;
int parent[100];
vector< pair<int, pii> > tree;

int findparent(int r)
{
    if(parent[r] == r)
     return r;
    else
      parent[r] = findparent(parent[r]);

    return
       parent[r];
}

void Union(int u,int v)
{

    if(u!=v)
    {
        parent[u] = v;
    }
}


void kruskalMST(vector< pair<int, pii> > vec)
{
   vector< pair<int, pii> > :: iterator it;

   for(it = vec.begin() ; it!=vec.end() ; it++)
   {
      int u = (*it).first;
      int v = (*it).second.first;
      int cost = (*it).second.second;

      int a = findparent(u);
      int b = findparent(v);

      if(a != b)
      {
          Union(a,b);
          tree.push_back(make_pair(u,pii(v,cost)));
      }
   }
}


int main()
{
    int u,v,cost;
    int vertices,edges;
    vector< pair<int, pii> > EdgeList;
    fstream f1("in.txt");
    scanf("%d%d",&vertices,&edges);

    for(int i = 1; i<=edges; i++)
    {
        f1>>u>>v>>cost;
        EdgeList.push_back(make_pair(cost,pii(u,v)));
    }
    sort(EdgeList.begin(),EdgeList.end());
    kruskalMST(EdgeList);

    for(int i = 0; i < tree.size(); i++)
    {
        printf("%d -> %d %d\n",tree[i].first,tree[i].second.first,tree[i].second.second);
    }

    return 0;
}
