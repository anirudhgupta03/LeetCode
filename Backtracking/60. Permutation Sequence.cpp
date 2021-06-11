class Solution {
public:
    int fact(int n){
    
        if(n == 0){
            return 1;
        }
        return n*fact(n-1);
    }
    string getPermutation(int A, int B) {

        int factA = fact(A - 1);

        vector<string> s;

        for(int i = 1; i <= A; i++){
            s.push_back(to_string(i));
        }

        string ans;
        int ind;

        A--;

        while(s.size() != 1){

            if(B % factA == 0){
                ind = B/factA - 1;
            }
            else{
                ind = B/factA;
            }

            ans += s[ind];
            s.erase(s.begin()+ind);


            B -= (ind)*(factA);

            factA /= A;

            A--;
        }
        ans += s[0];
        return ans;
    }
};
