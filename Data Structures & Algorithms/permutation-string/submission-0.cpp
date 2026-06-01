class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false; 

        vector<int> freq1(26,0); 
        vector<int> freqWindow(26,0); 

        for(char c:s1){
            freq1[c-'a']++; 
        }

        for(int i = 0; i < s2.size(); i++){
            freqWindow[s2[i] - 'a']++; 
            if(i >= s1.size()){
                freqWindow[s2[i-s1.size()] - 'a']--; 
            }

            if(freq1 == freqWindow) return true; 
        }

        return false; 
    }
};
