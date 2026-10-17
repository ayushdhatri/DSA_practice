class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
       // for each recipie we know ingredients
       // ingredient can be either recipie or stand alone ingredients
        // to make sandwichi you need bread + meat 
        // bread-> sandwich
        // meat -> sandwich
        // yeast-> bread
        // flour -> bread 
        // indegree = {sandwich -> 1,meat->0, yeast->0, flour->0,bread->0 }
        // meat indegree is zero so we can print this but wait since its a part of supplies we can avoid it
        // yeat indegree is zero so we can avoid as its not a recipie
        // flour indegree is zero so we can avoid as it is not a recipie
        // bread indegree is zero so we can add it our list as it is a recipie
        // indegree of sandwich is zero so we can add it our list 
        // here since we dont have connected  nodes if supplies is there but its not part of any recipie ingredients
        // then in that case we can safely push this supplies into our queue
        unordered_map<string, vector<string>>adj;
        unordered_map<string, int> indegree;
        int totalRecipies = recipes.size();
        for(int i =0;i<totalRecipies;i++){
            vector<string> ingredientsList = ingredients[i];
            for(auto x: ingredientsList){
                adj[x].push_back(recipes[i]);
                indegree[recipes[i]]+=1;
            }
        }
        // here I am confused how to get indegree of the ingrdeints having value zero
        // you can notice that supplies will have indegree zero 
        queue<string>q;
        for(auto x: supplies){
            q.push(x);
        }
        vector<string>ans;
        while(q.size()!=0){
            string currSupply = q.front();
            q.pop();
            for(auto x : adj[currSupply]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        return ans;
        

    }
};