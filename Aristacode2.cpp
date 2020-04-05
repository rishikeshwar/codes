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
bool opfile = freopen("op.txt", "w", stdout);
#endif
using namespace std;

void each_case(int t)
{
    
}   

int main()
{
	
    int n, m, k;
    cin >> n >> m >> k;

    string s[n]; int ans = 0;

    for( int i = 0; i < n; i++ ) 
        cin >> s[i];

    int presum[n + 1][m + 1];
    memset(presum, 0, sizeof(presum));

    for( int i = 1; i <= n; i++ ) {
        for(int j = 1; j <= m; j++ ) {
            presum[i][j] = presum[i - 1][j] + presum[i] [j - 1] - presum[i - 1][j - 1];
            if(s[i - 1][j - 1] == '*') presum[i][j]++;

            if( i >= k and j >= k ) {
                ans = max(ans, presum[i][j] - presum[i - k][j] - presum[i][j - k] + presum[i - k][j - k]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}