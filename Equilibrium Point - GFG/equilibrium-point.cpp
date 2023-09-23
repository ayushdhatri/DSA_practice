//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n==1)return 1;
        bool flag = false;
        int ans = 0;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum+=a[i];
        }
        long long prefix_sum = a[0];
        
        for(int i = 1;i<n-1;i++){
            long long temp = sum-(prefix_sum+a[i]);
            if(prefix_sum==temp){
                flag = true;
                ans = i;
                break;
            }
            prefix_sum+=a[i];
        }
        if(flag==false)return -1;
        return ans+1;
    
        // Your code here
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends