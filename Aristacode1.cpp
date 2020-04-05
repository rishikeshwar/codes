#include <bits/stdc++.h>
#define fr(i, a, n) for (i = a; i <= n; i++)
#define rf(i, n, a) for (i = n; i >= a; i--)
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define pb push_back
#define pp(a, b) pb(mp(a, b))
#define fi first
#define se second
#define ll long long
#define ld long double
#define mem(a, b) memset(a, b, sizeof(a))
#define cl(a) mem(a, 0)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define wi(x) cerr << #x << " is " << x << endl;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#ifndef ONLINE_JUDGE
bool ipfile = freopen("ip.txt", "r", stdin);
bool opfile = freopen("op.txt", "w", stdout) ;
#endif
using namespace std;

vector< vector <int>> adj;
int counto = 0; 

long long dfs( int node, int par, string s ) {
    int hasho = 0;
    for(auto u: adj[node]) {
        if(u == par) continue;
        hasho |= dfs(u, node, s); 
    }

    if( (1 << (s[node - 1] - 'a')) & hasho) return hasho;

    hasho |= (1 << (s[node - 1] - 'a'));
    counto++;
}

int main()
{
	
    int t;

    while(t--) {

        counto = 0;
        int n; string s;

        cin >> n;
        cin >> s;

        for(int i = 0; i < s.length(); i++) {
            adj[i].clear();
        }

        int m, len = n - 1, u, v;
        cin >> m;

        while(len--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, s); cout << counto << endl; 

    }

    return 0;
}