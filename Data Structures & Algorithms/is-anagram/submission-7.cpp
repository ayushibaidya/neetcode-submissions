class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1 = s.size(); 
        int s2 = t.size(); 

        if(s1 != s2) return false; 

        vector<int> freq(26, 0); 
        for(auto& c:s){
            freq[c-'a']++; 
        }

        for(auto& c:t){
            freq[c-'a']--; 
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false; 
            }
        }
        return true; 
    }
};
