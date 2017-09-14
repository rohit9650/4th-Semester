#include<iostream>

using namespace std;

int v = 9;

/**********************************        Union-find data structure        ***********************************/

struct vertex{
    public :
        int leader,size;
}component[9];

                void link(int x, int y){
                    if(component[x].size > component[y].size){
                        component[y].leader = x;
                        component[x].size++;
                     }
                    else{
                        component[x].leader = y;
                            component[y].size += 1;
                    }
                }

                int find_leader(int u){
                    if(component[u].leader != u)
                        component[u].leader = find_leader(component[u].leader);
                    return component[u].leader;
                }

                void make_union(int u, int v){
                    link(find_leader(u),find_leader(v));
                }


/*******************************  Representation of graph as an array of edges  ********************************/

class Edge{
    public :
                int src,dest,weight;
                Edge(){}

                void add_edge(int s, int d, int w){
                    src = s; dest = d; weight = w;
                }
};

class Graph{
    public :
                int e;
                Edge *edge;
                Graph(){
                    int s,d,w;
                    cout<<"\nEnter the number of vertices : ";
                    cin>>v;
                    cout<<"\nEnter the number of edges    : ";
                    cin>>e;
                    edge = new Edge[e];
                    for(int i=0; i<v; i++){
                        component[i].leader = i;
                        component[i].size = 0;
                    }
                    cout<<"\n\n------------------  Enter the Edges  ------------------\n";
                    /*for(int i=0; i<e; ++i){
                        cout<<"\n  source destination weight : ";
                        cin>>s;
                        cin>>d;
                        cin>>w;
                        edge[i].add_edge(s,d,w);
                    }

                    edge[0].add_edge(7,6,1);
                    edge[1].add_edge(8,2,2);
                    edge[2].add_edge(6,5,2);
                    edge[3].add_edge(0,1,4);
                    edge[4].add_edge(2,5,4);
                    edge[5].add_edge(8,6,6);
                    edge[6].add_edge(2,3,7);
                    edge[7].add_edge(7,8,7);
                    edge[8].add_edge(0,7,8);
                    edge[9].add_edge(1,2,8);
                    edge[10].add_edge(3,4,9);
                    edge[11].add_edge(5,4,10);
                    edge[12].add_edge(1,7,11);
                    edge[13].add_edge(3,5,14);*/
                    edge[0].add_edge(0,1,4);
                    edge[1].add_edge(1,2,8);
                    edge[2].add_edge(2,3,7);
                    edge[3].add_edge(3,4,9);
                    edge[4].add_edge(4,5,10);
                    edge[5].add_edge(5,6,2);
                    edge[6].add_edge(6,7,1);
                    edge[7].add_edge(7,8,7);
                    edge[8].add_edge(1,7,11);
                    edge[9].add_edge(8,2,2);
                    edge[10].add_edge(8,6,6);
                    edge[11].add_edge(2,5,4);
                    edge[12].add_edge(3,5,14);
                    edge[13].add_edge(3,5,14);
                }
};

/******************************* Using quick-sort for the kruskal's algorithm   ********************************/

int partition(int l,int r, Edge *a){

    int pivot = a[r].weight;
    int i=l-1;
    for(int j=l; j<=r-1; j++){
        if(a[j].weight<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quicksort(int l,int r, Edge *a){
    if(l<r){
        int pivot = partition(l,r,a);
        quicksort(l,pivot-1,a);
        quicksort(pivot+1,r,a);
    }
}

/******************************       Implementation of kruskal's algorithm     ********************************/

void kruskal(Graph g){

    Edge *MST = new Edge[v-1];

    Edge *edge_array = g.edge;
    quicksort(1,g.e-1,edge_array);

    for(int i=0,j=0; i<g.e; ++i){

        int x = edge_array[i].src, y = edge_array[i].dest;

        if(find_leader(x) != find_leader(y)){
            MST[j] = edge_array[i];
            j++;
            make_union(x,y);
        }
    }

    for(int i=0; i<v-1; i++){
        cout<<"\n\n\nsrc : "<<MST[i].src<<" "<<"  dest : "<<MST[i].dest<<" weight : "<<MST[i].weight;
    }
}

int main(){
    Graph g;
    kruskal(g);
    return 0;
}
