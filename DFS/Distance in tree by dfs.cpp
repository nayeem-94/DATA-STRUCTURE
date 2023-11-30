#include <bits/stdc++.h>
const int  MAX = 100005;

using namespace std;

vector<int > adj[MAX];
vector<bool> vist;
vector<int> dist;

void DFS( int u )
{
    vist [u] = 1;

    for(auto it : adj[u])
    {
        if( ! vist[it] )
        {
            dist[it] = dist[u] + 1;
            DFS(it);
        }
    }
}

int main() 
{
   int n , e;
   cin >> n >> e;
   vist.clear();
   dist.clear();
   vist.resize(n+1 , 0);
   dist.resize(n+1 , 0);


   
   for (int i = 0; i < e ; ++i)
   {
        int u , v;
       cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }

   DFS(1);

   for (int i = 1; i <= n; ++i)
   {
       cout << i << " : "<< dist[i] <<'\n';
   }

   
  
  return 0;
}

/*input :

5 4 
1 2
1 3 
2 4 
2 5

*/
