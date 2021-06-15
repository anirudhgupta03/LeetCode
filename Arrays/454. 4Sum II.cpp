//Time Complexity - O(N^2)
//Space Complexity - O(N)
//Similar Question - https://www.spoj.com/problems/SUMFOUR/
//Ref: https://leetcode.com/problems/4sum-ii/discuss/93925/Concise-C%2B%2B-11-code-beat-99.5
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> umap;
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                umap[nums1[i]+nums2[j]]++;
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                
                if(umap.find(-nums3[i]-nums4[j]) != umap.end()){
                    count += umap[-nums3[i]-nums4[j]];
                }
            }
        }
        
        return count;
    }
};
