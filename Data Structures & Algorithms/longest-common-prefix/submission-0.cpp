class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(); 

        string res = strs[0]; 

        for(int i = 0; i < n; i++){
            int j = 0; 
            while(j < min(res.length(), strs[i].length())){
                if(res[j] != strs[i][j]){
                    break; 
                }
                j++; 
            }
            res = res.substr(0, j); 
        }

        return res; 
    }
};