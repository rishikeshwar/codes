// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int find_min(int* a, int n, int k);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        cout << find_min(a, n, k) << endl;
    }
    return 1;
}
// } Driver Code Ends
// User function Template for C++

// number of socks available of ith colour is given by a[i]
// return the min number of picks needed to get k pairs
// do not print anything

int find_min(int* a, int n, int k) {
    
    long long ans = n, done = 0, getting = 0, sumo = 0;
    for( int i = 0; i < n; i++ ) {
        sumo += a[i]/2;
        a[i]--;
        if( a[i] != 0 and !(a[i]%2)) {
            getting = a[i]/2;
            if(done + getting >= k) {
                int want = k - done;
                return ans + (2*want) - 1;
            }
            done += getting;
            ans += a[i];
        }
    }
    
    for( int i = 0; i < n; i++ ) {
        if( a[i] > 1 and a[i]%2 ) {
            getting = a[i]/2;
            if( done + getting >= k ) {
                int want = k - done;
                return ans + (2*want) - 1;
            }
            done += getting;
            ans += a[i] - 1;
            
        }    
    }
    
    for( int i = 0; i < n; i++ ) {
        if(a[i] > 0) {
            done += 1;
            if( done >= k ) {
                return ans + 1;
            }
            ans++;
        }
    }
    if(k > sumo) return -1;
    if(done < k) return -1;
    
    return ans;
    
}
