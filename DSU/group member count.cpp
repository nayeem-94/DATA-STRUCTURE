// find member of each group BY DSU  [ codeforces- 1167C ]

#include <bits/stdc++.h>
using namespace std;

const int MAX = 500005;
int n,m,pr[MAX],sum[MAX];

int find_captain(int u)
{
    if (pr[u] == u) return u;
    return pr[u] = find_captain(pr[u]);

}

void join ( int u , int v)
{
    int cu = find_captain(u);
    int cv = find_captain(v);
    pr[cv] = cu;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <=n ; ++i)
    {
        pr[i]=i;
    }
    while(m--)
    {
        int k,x,y; cin >> k ;
        if(!k)
            continue;
        cin >> x;

        for (int i = 2; i <=  k ; ++i)
        {
            cin >> y;
            join( x , y );
        }

    }
   
    for (int i = 1; i <= n; ++i)
      {
        //cout<<i <<" find captain ----> "<<find_captain(i)<<'\n';
        sum[find_captain(i)]++;
      } 

    for (int i = 1; i <= n; ++i)
        cout << sum[pr[i]] << " ";

    cout<<"\n";
   

    
}
