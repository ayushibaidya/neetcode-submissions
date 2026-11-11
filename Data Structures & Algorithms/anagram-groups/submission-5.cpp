class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(); 

        unordered_map<string, vector<string>> mp; 

        for(auto& s:strs){
            string temp = s; 
            sort(temp.begin(), temp.end()); 

            mp[temp].push_back(s); 
        }

        vector<vector<string>> ans; 

        for(auto& s:mp){
            ans.push_back(s.second); 
        }
        return ans; 
    }
};
