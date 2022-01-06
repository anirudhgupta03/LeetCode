class Solution {
public:
    string countOfAtoms(string formula) {
        
        int n = formula.size();
        
        map<string,int> atoms;
        
        int temp = 1;
        
        vector<int> multiples;
        multiples.push_back(1);
        
        for(int i = n - 1; i >= 0; i--){
            
            if(isdigit(formula[i])){
                string res;
                while(i >= 0 && isdigit(formula[i])){
                    res.push_back(formula[i]);   
                    i--;
                }
                i++;
                reverse(res.begin(),res.end());
                
                multiples.push_back(multiples.back()*(stoi(res)));
                temp = temp*(stoi(res));
            }
            else if(formula[i] == '('){
                if(multiples.size() != 1)
                multiples.pop_back();   
            }
            else if(formula[i] == ')'){
                temp = 1;
            }
            else{
                string res;
                    if(formula[i] >= 'a' && formula[i] <= 'z'){
                        res.push_back(formula[i]);
                        res.push_back(formula[i-1]);
                        i--;
                    }
                    else{
                        res.push_back(formula[i]);
                    }
                    reverse(res.begin(),res.end());
                    atoms[res] += multiples.back();
                    
                    if(temp != 1){
                        temp /= (multiples[multiples.size()- 1]/(multiples[multiples.size()-2]));
                        multiples.pop_back();   
                    }
            }
        }
        
        string ans;
        for(auto x: atoms){
            ans += x.first;
            if(x.second != 1)
            ans += to_string(x.second);
        }
        return ans;
    }
};
