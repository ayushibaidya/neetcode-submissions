class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 
        int currTank = 0; 
        int totalTank = 0; 
        int start = 0; 

        for(int j = 0; j < n; j++){ 
                int diff = gas[j]-cost[j];
                currTank += diff; 
                totalTank += diff; 
                if(currTank < 0){
                    start = j+1; 
                    currTank = 0; 
                }
            }
        return (totalTank >= 0) ? start : -1; 
    }
};
