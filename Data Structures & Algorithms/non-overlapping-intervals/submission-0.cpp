class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 

        int n = intervals.size(); 

        int remove = 0; 
        int prevEnd = intervals[0][1]; 

        for(int i = 1; i < n; i++){
            int start = intervals[i][0]; 
            int end = intervals[i][1]; 

            //no overlap 
            if(start >= prevEnd){
                //update prevEnd 
                prevEnd = end; 
            }else{
                remove++; 
                prevEnd = min(prevEnd, end); 
            }
        }
        return remove; 
    }
};
