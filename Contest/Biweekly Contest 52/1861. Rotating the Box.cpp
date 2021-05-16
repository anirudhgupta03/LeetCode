class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size(), n = box[0].size();
        
        for(int i = 0; i < m; i++){
            
            int j = n - 2;
            
            while(j >= 0){
                
                if(box[i][j] == '#'){
                    
                    int ind = -1;
                    int k = j + 1;
                    
                    while(k < n){

                        if(box[i][k] == '.'){
                            ind = k;
                        }
                        if(box[i][k] == '*'){
                            break;
                        }
                        k++;
                    }
                    if(ind != -1){
                        swap(box[i][j],box[i][ind]);
                    }
                }   
                
                j--;
            }
        }
      
        vector<vector<char>> res(n,vector<char>(m));
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                res[j][m-1-i] = box[i][j];
            }
        }
        
        return res;
    }
};
