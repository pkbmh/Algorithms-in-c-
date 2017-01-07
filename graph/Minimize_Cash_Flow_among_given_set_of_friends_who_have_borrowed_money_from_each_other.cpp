#include <bits/stdc++.h>
using namespace std;

#define tr(c , it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define PII pair < int , int >

typedef struct GRAPH {
    int v;
    int **vertex;
    GRAPH(int a) {
        v = a;
        vertex = new int *[a];
        for(int i = 0; i < a; i++) {
            vertex[i] = new int[a];
            for(int j = 0; j < a; j++) {
                vertex[i][j] = 0;
            }
        }
    }
    void insert_edge(int s , int d , int w) { vertex[s][d] = w; }
}GRAPH;

PII max_debt_cre(int *net , int v) {
    int debt = 0;
    int cre = 0;

    for(int i = 1; i < v; i++) {
        if(net[debt] > net[i])
            debt = i;
        if(net[cre] < net[i])
            cre = i;
    }
    return make_pair(debt , cre);
}
int minimum_cash_flow(GRAPH graph) {
    int v = graph.v;
    int net[v];
    memset(net , 0 , sizeof(net));

    for(int i = 0; i < v; i++) {
       for(int j = 0; j < v; j++){
            net[i] -= graph.vertex[i][j];
            net[j] += graph.vertex[i][j];
        }
    }

    int min_flow = 0;
    PII debt_cre;

    while(true) {
        debt_cre = max_debt_cre(net , v);
        int debt = debt_cre.first;
        int cre = debt_cre.second;

        if(debt == 0 && cre == 0)
            break;
        int f = min(-net[debt] , net[cre]);
        min_flow += f;
        cout << "from " << debt << " to " << cre << " cash :: " << f << endl;

        net[debt] += f;
        net[cre] -= f;
    }

    return min_flow;
}
int main()
{
    int n = 3;
    GRAPH graph(n);
    graph.insert_edge(0 , 1 , 1000);
    graph.insert_edge(0 , 2, 2000);
    graph.insert_edge(1 , 2 , 5000);

    int min_cash_flow = minimum_cash_flow(graph);
    cout << " Minimum cash flow is = " << min_cash_flow << endl;

return 0;
}
