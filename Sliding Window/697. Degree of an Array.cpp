//Sliding Window
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        
        int maxfreq = 0;
        
        for(auto x: freq){
            maxfreq = max(maxfreq, x.second);
        }
        
        cout << maxfreq << endl;
        
        int minlen = INT_MAX;
        
        int lo = 0, hi = 0;
        
        freq.clear();
        
        while(hi < nums.size()){
            
            freq[nums[hi]]++;
            
            if(freq[nums[hi]] == maxfreq){
                while(lo <= hi){
                    minlen = min(minlen, hi - lo + 1);
                    if(nums[lo] == nums[hi]){
                        freq[nums[lo]]--;
                        if(freq[nums[lo]] == 0) freq.erase(nums[lo]);
                        lo++;
                        break;
                    }
                    else{
                        freq[nums[lo]]--;
                        if(freq[nums[lo]] == 0) freq.erase(nums[lo]);
                        lo++;
                    }
                }
            }
            hi++;
        }
        return minlen;
    }
};
