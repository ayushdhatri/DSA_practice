class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // two kind of sequence is getting build up
        // G S G S G S ..... comparing k with k + 1 subarray of lenght L = 4
        // S G S G S G...... comparing k with k + 1 subarray of lenght L = 5
        // take the maximum of both of them and return the answer
        // take two for loop for each of sequence kind find anse
        // we can do precompuete and compare every number with the next number and store 0 or 1
        // find longest subarray with 0,1,0,1 as adjacent numer
        // dupliactes can also exist so if adjacent are duplicates then in that case asnwer will be 0
        // [G,G,S,G,S,E,G,S] // let compare adjacent and put the value
        // do a single traversal and check find longest one
        int n = arr.size();
        if(n == 1) return 1;
        if(n == 2){
            if(arr[0] != arr[1])return n;
            return 1;
        }
        int prevComp = 0;
        int currLen = 1;
        int maxLen = 1;
        for(int i = 0;i<n-1;i++){
            int currComp = 0;
            if(arr[i] < arr[i+1]){
                currComp = -1;
            }
            else if(arr[i] > arr[i+1]){
                currComp = 1;
            }
            if(currComp == 0){
                // elements are equal
                currLen = 1;
            }
            else if(currComp == -prevComp){
                currLen+=1;
            }
            else{
                currLen = 2;
            }
            maxLen = max(maxLen, currLen);
            prevComp = currComp;

        }
        return maxLen;
    }
};