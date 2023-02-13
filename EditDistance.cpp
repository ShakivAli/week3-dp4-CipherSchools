class Solution {
public:

    int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i == s1.length()) return s2.length()-j;
        if(j == s2.length()) return s1.length()-i;
        if(dp[i][j] != - 1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = solve(s1,s2,i+1,j+1,dp);
        else{
            int ans1 =  solve(s1,s2,i+1,j+1,dp);
            int ans2 =  solve(s1,s2,i+1,j,dp);
            int ans3 =  solve(s1,s2,i,j+1,dp);
            return dp[i][j] = min({ans1,ans2,ans3})+1;
        }
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,vector<int> (word2.length()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};
