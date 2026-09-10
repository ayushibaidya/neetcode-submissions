class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> match; 

        for(auto &s:strs){
            string temp = s; 
            sort(temp.begin(), temp.end());  
            match[temp].push_back(s); 
        }

        vector<vector<string>> ans; 

        for(auto& s:match){
            ans.push_back(s.second); 
        }
        return ans; 

    }
};
