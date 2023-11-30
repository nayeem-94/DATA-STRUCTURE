//problem no -  [ SPOJ-PT07Y ] 
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005 ;

vector < int > adj_list [ MAX ];
vector < bool > visited;

void dfs( int vertex)           
{
    visited[vertex] = 1;
    for( auto it : adj_list[vertex])
    {
        if( ! visited[it])
        {
            dfs(it);
        }
    }
}
 


int main()
{
    int n , e;
    cin >> n >> e;

    visited.resize( n + 1 , 0 ); 

    for (int i = 0; i < e; ++i)
    {
        int u , v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);

    if ( n - 1 == e)
    {
        int check = 1;
        for (int i = 1; i <= n ; ++i)
        {
            if( ! visited[i])
            {
                check = 0;
            }
        }

        if ( check )
            cout<< "YES\n";
        else 
            cout<<"NO\n";
    }

    else
    {
        cout<<"NO\n";
    }

    

    return 0;

}
