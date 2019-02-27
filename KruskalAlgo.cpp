//Md.Atiqur Rahaman
//Roll:1610876133

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class GG{

public:
    int V, E;
    int cnt;

    struct Edge{
        int u, v, w;
    };



    vector<Edge> edges;



    GG(int v, int e){
        this->V = v;
        this->E = e;

    }




    struct disjointset{
        int parent;
        int deg;
    };


    void addEdge(int x, int y, int z){
        Edge _e;
        _e.u = x;
        _e.v = y;
        _e.w = z;
        edges.push_back(_e);
    }





    void marge(vector<disjointset> &subsets, int x1, int y1){
        int _x = find(subsets, x1);
        int _y = find(subsets, y1);

        if(subsets[_x].deg < subsets[_y].deg){
            subsets[_x].parent = _y;
        }
        else if(subsets[_x].deg > subsets[_y].deg){
            subsets[_y].parent = _x;
        }
        else{
            subsets[_y].parent = _x;
            subsets[_x].deg++;
        }
    }



    void bubbleSort(vector<Edge> &v){
        for(int i=0; i<v.size()-1; i++){
            for(int j=i+1; j<v.size(); j++){
                if(v[j].w<v[i].w){
                    swap(v[i], v[j]);
                }
            }
        }
    }



    void kruskal(){
        vector<Edge> res(V);
        int buff = 0;
        int i=0;
        bubbleSort(edges);

        vector<disjointset> subsets(V);
        for(int j=0; j<V; j++){
            subsets[j].parent = j;
            subsets[j].deg = 0;
        }
        while(buff<V-1){
            struct Edge curr = edges[i++];
            int x = find(subsets, curr.u);
            int y = find(subsets, curr.v);
            if (x!=y){
                res[buff++] = curr;
                marge(subsets, x, y);
            }
        }
        cout << "Minimum spanning tree:" << endl;
        for(int i=0; i<buff; i++){
            cout << res[i].u << " -- " << res[i].v << ": " << res[i].w << endl;
        }

    }



    int find(vector<disjointset> &subsets, int i){
        if(subsets[i].parent!=i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }


};


int main(){

    freopen("in.txt", "r", stdin);

    int v, e;
    cin >> v >> e;
    GG ob(v, e);

    int a, b, w;
    for(int i=0; i<e; i++){
        cin >> a >> b >> w;
        ob.addEdge(a, b, w);
    }
    ob.kruskal();

    return 0;
}
