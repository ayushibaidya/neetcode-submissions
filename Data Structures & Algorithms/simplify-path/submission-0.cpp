class Solution {
public:
    string simplifyPath(string path) {
        vector<string> clean; 

        int n = path.size(); 

        string ans;

        for(int i = 0; i <= n; i++){
            if(i == n || path[i] == '/'){
                if(ans == "" || ans == "."){}
                else if(ans == ".."){
                    if(!clean.empty()){
                        clean.pop_back(); 
                    }
                }else{
                    clean.push_back(ans); 
                }
                ans = ""; 
            }else{
                ans += path[i]; 
            }
        }
        string fans; 
        for(string i:clean){
            fans += "/"+i; 
        }
        return fans.empty() ? "/" : fans; 
    }
};