// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 
vector <int> shortestDistance(string S, char X) ;

 // } Driver Code Ends
//User function Template for C++

vector <int> shortestDistance(string S, char X) 
{
    int len = S.length();
    int found = 0, num = 10010;
    vector < int > ans(len);
    
    for( int i = 0; i < len; i++ ) {
        ans[i] = INT_MAX;
        if(S[i] == X) num = 0;
        if( num < ans[i] ) ans[i] = num;
        num++;
    }
    
    num = 10010;
    
    for( int i = len - 1; i >= 0; i-- ) {
        if(S[i] == X) num = 0;
        if( num < ans[i] ) ans[i] = num;
        num++;
    }
    
    return ans;
}

// { Driver Code Starts.
int main() 
{ 	int t;
	cin>>t;
	while(t--)
	{
		string S;
		char X;
		cin>>S;
		cin>>X;

		vector <int> result (S.length());
		result = shortestDistance(S, X); 

		for(int i=0; i<result.size();i++)
			cout<<result[i]<<" ";
		cout<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends