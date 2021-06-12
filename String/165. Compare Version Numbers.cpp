class Solution {
public:
    int compareVersion(string A, string B) {
        
      vector<int> v1,v2;
    
        for(int i = 0; i < A.size(); i++){
            if(A[i] == '.'){
                A[i] = ' ';
            }
        }
        for(int i = 0; i < B.size(); i++){
            if(B[i] == '.'){
                B[i] = ' ';
            }
        }
        stringstream X1(A);
        string temp;
        while(X1 >> temp){
            v1.push_back(stoi(temp));
        }

        stringstream X2(B);
        while(X2 >> temp){
            v2.push_back(stoi(temp));
        }

        if(v1.size() > v2.size()){
            while(v2.size() != v1.size()){
                v2.push_back(0);
            }
        }
        else{
            while(v1.size() != v2.size()){
                v1.push_back(0);
            }
        }

        for(int i = 0; i < v1.size(); i++){
            if(v1[i] > v2[i]){
                return 1;
            }
            else if(v2[i] > v1[i]){
                return -1;
            }
        }
        return 0;
    }
};
