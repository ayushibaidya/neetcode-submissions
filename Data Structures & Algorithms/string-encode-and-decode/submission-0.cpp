class Solution {
public:

    string encode(vector<string>& strs) {
        string newString = ""; 

        for(string s:strs){
            newString += to_string(s.size()) + "#" + s;
        }
        return newString; 
    }

    vector<string> decode(string s) {
         vector<string> result;
    int i = 0;

    while (i < s.size()) {
        int j = i;
        while (s[j] != '#') j++;
        int len = stoi(s.substr(i, j - i)); // length before '#'
        result.push_back(s.substr(j + 1, len));
        i = j + 1 + len;
    }

    return result;
    }
};
