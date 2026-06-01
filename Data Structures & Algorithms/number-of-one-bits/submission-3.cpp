class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask = 1; 
        int count = 0; 

        for(int i = 0; i < 32; i++){
            if((n & mask) != 0){
                count++; 
            }
            mask = mask << 1; 
        }
        return count; 
    }
};
