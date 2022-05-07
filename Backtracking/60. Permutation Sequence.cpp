//Method - 1
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

//Method - 2
class Solution {
public:
    string getPermutation(int A, int B) {
        if(A == 1){
            return "1";
        }

        int fact = 1;

        for(int i = 1; i <= A - 1; i++){
            fact *= i;
        }

        vector<int> v(A);
        for(int i = 0; i < A; i++){
            v[i] = i + 1;
        }

        string res;
        int i = A - 1;

        while(B){
            int temp = B/fact;
            if(B % fact == 0){
                temp--;
            }
            res += to_string(v[temp]);

            v.erase(v.begin() + temp);
            B %= fact;
            fact /= i;
            i--;
        }
        for(int i = v.size() - 1; i >= 0; i--){
            res += to_string(v[i]);
        }
        return res;
    }
};
