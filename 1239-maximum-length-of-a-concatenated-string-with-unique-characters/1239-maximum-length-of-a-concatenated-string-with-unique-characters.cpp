class Solution {
public:
    int chars[26] = {0}; 
    int helper(vector<string> &arr, int i){
        if(i >= arr.size()) return 0; 

        int op_1 =INT_MIN, op_2 = INT_MIN; 

//don' take current string into final answer --> 
        op_1 = helper(arr, i+1); 

//inlude current string into answer --> 
        //include all the chars of current string into the arr
        for(int j=0; j<arr[i].size(); j++) chars[arr[i][j] - 'a'] += 1; 

        //check if any char is repeating
        bool flag = true; 
        for(int j=0; j<26; j++) if(chars[j] > 1) flag = false; 

        //if not repeating, then take current string into answer
        if(flag) op_2 = helper(arr, i+1) + arr[i].size(); 

        //backtrack to original state 
        for(int j=0; j<arr[i].size(); j++) chars[arr[i][j] - 'a'] -= 1; 
    
        return max(op_1, op_2); 
    }
    int maxLength(vector<string>& arr) {
        return helper(arr, 0); 
    }
};