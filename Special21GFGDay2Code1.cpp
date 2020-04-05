// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// arr: input array
// num: size of array

long long kadane( int ar[], int num ) {
    long long ans = INT_MIN, count = 0; 
    
    for( int i = 0; i < num; i++ ) {
        count += ar[i];
        
        ans = max(ans, count);
        
        if( count < 0 ) count = 0;
    }
    
    return ans;
} 

int  maxMoney(int arr[], int num)
{
    long long maxo = kadane( arr, num ), sumo = 0;
    
    for(int i = 0; i < num; i++) {
        sumo += arr[i];
        arr[i] *= -1;
    }
    
    long long mino = kadane( arr, num );
    
    return max( maxo, sumo + mino);
    // your code here
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << maxMoney(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends