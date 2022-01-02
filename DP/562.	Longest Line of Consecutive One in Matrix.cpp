//https://www.lintcode.com/problem/875/
class Solution {
public:
    /**
     * @param M: the 01 matrix
     * @return: the longest line of consecutive one in the matrix
     */
    int longestLine(vector<vector<int>> &M) {
        
        int m = M.size();
        if(m == 0){return 0;}

        int n = M[0].size();

        vector<vector<int>> vis1(m, vector<int>(n,0));  //horizontal
        vector<vector<int>> vis2(m, vector<int>(n,0));  //vertical
        vector<vector<int>> vis3(m, vector<int>(n,0));  //diagonal
        vector<vector<int>> vis4(m, vector<int>(n,0));  //anti-diagonal

        int maxcount = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(M[i][j] == 1){

                    if(vis1[i][j] == 0){
                        int count = 0;
                        int k = j;
                        while(k < n && M[i][k] == 1){
                            vis1[i][k] = 1;
                            count++;
                            k++;
                        }
                        maxcount = max(maxcount, count);
                    }
                    if(vis2[i][j] == 0){
                        int k = i;
                        int count = 0;
                        while(k < m && M[k][j] == 1){
                            vis2[k][j] = 1;
                            count++;
                            k++;
                        }
                        maxcount = max(maxcount, count);
                    }
                    if(vis3[i][j] == 0){
                        int k = i, l = j;
                        int count = 0;
                        while(k < m && l < n && M[k][l] == 1){
                            vis3[k][l] = 1;
                            count++;
                            k++;
                            l++;
                        }
                        maxcount = max(maxcount, count);
                    }
                    if(vis4[i][j] == 0){
                        int k = i, l = j;
                        int count = 0;
                        while(k < m && l >= 0 && M[k][l] == 1){
                            vis4[k][l] = 1;
                            count++;
                            k++;
                            l--;
                        }
                        maxcount = max(maxcount, count);
                    }
                }
            }
        }
        return maxcount;
    }
};
