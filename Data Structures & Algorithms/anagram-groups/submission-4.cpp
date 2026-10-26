class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> sorted; 

        for(auto& s:strs){
            string temp = s; 
            sort(temp.begin(), temp.end()); 

            sorted[temp].push_back(s); 
        }

        vector<vector<string>> ans; 


        //pushback the second one because its a vector containing all the anagrams of the key 
        for(auto& s:sorted){
            ans.push_back(s.second); 
        }
        return ans; 
    }
};
