//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    
 
    void insertHeap(int &x)
    {
        if(left.size()==0&&right.size()==0)
        {
            left.push(x);
        }
        else
        {
            if(right.size()!=0&&x>right.top())
                right.push(x);
            else
                left.push(x);
            
            if(left.size()-right.size()>1)
            {
                if(left.size()<right.size())
                {
                    left.push(right.top());
                    right.pop();
                }
                else
                {
                    right.push(left.top());
                    left.pop();
                }
            }
        }
        
        
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()+right.size()==1)
        return left.top();
        if(left.size()==right.size())// number of data in the stream is equal
        {
            return 1.0*(left.top()+right.top())/2;
        }
        if(left.size()>right.size())
        return left.top();
        return right.top();
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends