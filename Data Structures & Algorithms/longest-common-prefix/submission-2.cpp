class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(); 

        string ans = strs[0]; 

        for(int i = 0; i < ans.size(); i++){
            for(int j = 1; j < n; j++){
                if(i >= strs[j].size() || ans[i] != strs[j][i]){
                    return ans.substr(0, i); 
                }
            }
        }
        return ans; 
    }
};