class Solution {
public:
    int trap(vector<int>& A) {
    
            int n = A.size();
            
            if(n == 0){
                return 0;
            }
            vector<int> ngl(n,-1);

            stack<int> s;

            ngl[0] = -1;

            s.push(A[0]);

            for(int i = 1; i < n; i++){

                if(A[i] < s.top()){
                    ngl[i] = s.top();    
                }
                else{

                    while(!s.empty() && A[i] >= s.top()){
                        s.pop();
                    }

                    if(!s.empty()){
                        ngl[i] = s.top();
                    }
                    s.push(A[i]);
                }
            }

            while(s.size()){
                s.pop();
            }

            vector<int> ngr(n,-1);

            ngr[n-1] = -1;

            s.push(A[n-1]);

            for(int i = n - 2; i >= 0; i--){

                if(A[i] < s.top()){
                    ngr[i] = s.top();
                }
                else{

                    while(!s.empty() && A[i] >= s.top()){
                        s.pop();
                    }

                    if(!s.empty()){
                        ngr[i] = s.top();
                    }
                    s.push(A[i]);
                }
            }

            int water_trapped = 0;

            for(int i = 1; i <= n - 2; i++){

                if(ngl[i] != -1 && ngr[i] != -1){
                    water_trapped += min(ngl[i],ngr[i]) - A[i];
                }
            }

            return water_trapped;
        }
};
