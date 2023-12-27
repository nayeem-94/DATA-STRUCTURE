prolem no : 1144 F

#include <bits/stdc++.h>
#define newline         cout<<'\n';
#define space           cout<<' ';
#define print(s)        cout<<s;
#define printarry(a)    for(auto it : a) cout<<it<<' ';
#define crack(a)        cout<<"this is"<<" ----> "<<a;
#define dbg(x)          cout<<"line " << __LINE__ << " says: " << #x << " = " << x << "\n";
#define fast            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int MAX = 200005+5 ;

vector < int > adj_list [ MAX ];
vector<bool> vist(MAX);
vector<int> col(MAX,-1);



bool dfs(int u)
{
    vist[u]=1;

    for(auto it : adj_list[u])
    {
        if(col[u]==col[it])
            return false;
        else if( !vist[it] )
        {
            col[it]=!col[u];

            if(!dfs(it))
                return false;

        }

    }
    return true;
}

void solve()
{
    fast;
    int n,m;
    cin >> n >> m;

    vector<vector<int> > ev;


    for (int i = 0; i < m; ++i)
    {
        int u , v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        ev.push_back({u,v});
    }

    col[1]=0;

    if(!dfs(1))
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        string ans;

        for (int i = 0; i < m; ++i)
        {
            int direct = ev[i][0];

            if(col[direct]==0)
                ans+="0";
            else
                ans+="1";
        }
        cout<<ans<<'\n';

    }

    return;

}

int main() 
{
    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
