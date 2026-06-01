/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    static bool comparator(const Interval &a, const Interval &b){
        return a.start < b.start; 
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0; 
        int n = intervals.size(); 
        int rooms = 1; 

        sort(intervals.begin(), intervals.end(), comparator);

        int minE = intervals[0].end; 

        priority_queue<int, vector<int>, greater<int>> pq; 

        pq.push(intervals[0].end);

        for(int i = 1; i < n; i++){
            if(intervals[i].start >= pq.top()){
                pq.pop(); 
            }
            pq.push(intervals[i].end);
        }
        return pq.size(); 
    }
};
