class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; 

        for(auto& s:strs){
            string temp = s;
            sort(temp.begin(), temp.end()); 
            mp[temp].push_back(s);  
        }

        vector<vector<string>> results; 

        for(auto &s:mp){
            results.push_back(s.second); 
        }
        return results; 
    }
};
