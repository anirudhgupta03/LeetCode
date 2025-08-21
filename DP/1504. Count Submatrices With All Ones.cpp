//Ref: https://www.youtube.com/watch?v=hrd-MEcZkOI
//TC: O(m*m*n)
//SC: O(1)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = n - 2; j >= 0; j--){
                if(mat[i][j] == 1){
                    mat[i][j] += mat[i][j + 1];
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    int temp = mat[i][j];
                    count += temp;
                    for(int k = i + 1; k < m; k++){
                        temp = min(temp, mat[k][j]);
                        count += temp;
                    }
                }
            }
        }
        return count;
    }
};

//Ref: https://www.youtube.com/watch?v=JnJGIE7porM
//TC: O(m*n)
//SC: O(m*n)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> histogram(n, 0);
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    histogram[j] += 1;
                }
                else{
                    histogram[j] = 0;
                }
            }
            stack<vector<int>> st;
            st.push({-1, -1, 0});

            for(int j = 0; j < n; j++){
                while(histogram[j] < st.top()[0]){
                    st.pop();
                }
                int gap = j - st.top()[1];
                count += gap*histogram[j] + st.top()[2];
                st.push({histogram[j], j, gap*histogram[j] + st.top()[2]});
            }
        }
        return count;
    }
};
