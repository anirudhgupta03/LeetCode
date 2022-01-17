//Ref: https://www.youtube.com/watch?v=WY6qloZPZ00
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        unordered_map<int,int> umap;
        
        for(int i = 0; i < row.size(); i++){
            umap[row[i]] = i;
        }
        
        int swaps = 0;
        for(int i = 0; i < row.size(); i+=2){
            int first = row[i];
            int second = first + (row[i] % 2 == 0 ? 1 : -1);
            
            if(second != row[i + 1]){
                swaps++;
                int ind = umap[second];
                umap[second] = i;
                umap[row[i + 1]] = ind;
                swap(row[ind], row[i + 1]);
            }
        }
        return swaps;
    }
};
