//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        int curr = 0;
        int low = -1;
        int high = n;
        while(curr<high)
        {
            if(arr[curr]==0)
            {
                low++;
                swap(arr[low],arr[curr]);
                curr++;
                
            }
            else if(arr[curr]==1)
            {
                curr++;
            }
            else// it can be equal to 2
            {
                high--;
                swap(arr[curr],arr[high]);
            }
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends