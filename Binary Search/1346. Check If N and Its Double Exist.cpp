class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map<int,int> umap;
        
        for(int i = 0; i < arr.size(); i++){
            if(umap.find(2*arr[i]) != umap.end()){
                return true;
            }
            if(arr[i] % 2 == 0){
                if(umap.find(arr[i]/2) != umap.end()){
                    return true;
                }
            }
            umap[arr[i]] = 1;
        }
        return false;
    }
};
