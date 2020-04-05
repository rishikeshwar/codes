// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string LCP(string ar[], int n);
int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        cout<<LCP(arr,n)<<endl;
	    }
	return 0;
}// } Driver Code Ends
//User function Template for C++

string LCP(string ar[], int n)
{
    if(n == 0) return "";
    if(n == 1) return ar[0];
    
    sort( ar, ar + n );
    
    int len = min( ar[0].length(), ar[n - 1].length() );
    
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    
    while( i < len and first[i] == last[i] ) i++;
    
    if(i == 0) return "-1";
    
    return first.substr(0, i);
    
}