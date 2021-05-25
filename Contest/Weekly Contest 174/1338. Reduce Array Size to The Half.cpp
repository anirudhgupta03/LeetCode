class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> umap;
        
        int n = arr.size();
        
        for(auto x: arr){
            umap[x]++;
        }
        
        vector<int> freq;
        
        unordered_map<int,int> :: iterator it;
        
        for(it = umap.begin(); it != umap.end(); it++){
            freq.push_back(it->second);
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int count = 0;
        
        for(int i = 0; i < freq.size(); i++){
            
            n -= freq[i];
            count++;
            
            if(n <= arr.size()/2){
                break;
            }
        }
        return count;
    }
};
