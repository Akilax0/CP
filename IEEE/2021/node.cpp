#include<bits/stdc++.h>
using namespace std;
int biggest_dist(int n, int v, const vector< vector<int> >& graph)
{ //This function finds the diameter of thegraph
int INF = 2 * graph.size(); // Bigger than any other length
vector<int> dist(n, INF);

dist[v] = 0;
queue<int> next;
next.push(v);

int bdist = 0; //biggest distance
while (!next.empty()) {
    int pos = next.front();
    next.pop();
    bdist = dist[pos];

    for (int i = 0; i < graph[pos].size(); ++i) {
        int nghbr = graph[pos][i];
        if (dist[nghbr] > dist[pos] + 1) {
            dist[nghbr] = dist[pos] + 1;
            next.push(nghbr);
        }
    }
}

return bdist;
}

int main()  
{
int N; scanf("%i", &N);
int minst;
vector< vector<int> > graph(N+1);
vector<int> noder;
for (int i = 0; i <N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);

    graph[a].push_back(b);
    graph[b].push_back(a);
}


int answer = 0;
int dis = biggest_dist(N+1, 0,graph);
int maxdist;
for (int j = 0; j < N-1; ++j)
{
    maxdist = biggest_dist(N+1,j, graph);
    if (maxdist < dis)
    {
        dis = maxdist;
        answer = j;
    }
}
printf("%d", maxdist);

return 0;
}