class Solution {
public:

    void dfs(int sum, int n, vector<int>& ans){
        if(sum >= n) return;
        for(int i = 0; i <= 9; i++){
            if(sum*10 + i <= n){
                ans.push_back(sum*10 + i);
                dfs(sum*10 + i, n, ans);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        int sum = 0;
        vector<int> ans;
        for(int i = 1; i <= 9; i++){
            if(sum*10 + i <= n){
                ans.push_back(sum*10 + i);
                dfs(sum*10 + i, n, ans);
            }
        }
        return ans;
    }
};