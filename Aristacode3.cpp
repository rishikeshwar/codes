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
	
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << s << endl;
        int len = s.length(), count = 0, flag = 0, ans = 0;

        for(int i = 0; i < len; i++) {
            count++;
            if( s[i] == '0' and flag == 1 ) {
                ans = max(count, ans);
                flag = 0; count = 0;
            }

            if( s[i] == '0' ) {
                flag = 1;
            } 
        }
        ans = max(count, ans);

        cout << ans << endl;
    }

    return 0;
}