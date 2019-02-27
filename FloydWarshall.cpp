#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x[100][100];
    int nodenumber,u,v,cost,src,dist,vertex,edge;
    fstream f1("in.txt");
    f1 >> vertex;
    f1 >> edge;

    for(int i = 1; i <= vertex ; i++){
      for(int j = 1; j <= vertex ; j++){

          if(i == j)
            x[i][j] = 0;
          else
            x[i][j] = 100000;
      }
   }

    for(int i = 1; i<= edge ; i++)
    {
        f1 >> u >> v;
        f1 >> cost;
        x[u][v] = cost;
    }

    for(int k = 1; k <= vertex ; k++){
      for(int i = 1; i <= vertex ; i++){
        for(int j = 1; j <= vertex ; j++){
           x[i][j] = min(x[i][j],x[i][k]+x[k][j]);
        }
      }
    }

    while(scanf("%d%d",&src,&dist)!=EOF)
    {
        printf("%d - > %d : %lld\n",src,dist,x[src][dist]);
    }

    return 0;
}
