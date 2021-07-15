class Solution {
public:
    #define ll long long
    string fractionToDecimal(int numerator, int denominator) {
        
        ll num = numerator, den = denominator;
        
        bool flag = false;
        
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0){
            flag = true;
        }
        
        num = abs(num);
        den = abs(den);
        
        ll a = num/den;
        
        string res;
        
        res += to_string(a);
        
        num %= den;
        
        if(num == 0){
            if(flag){
                res.insert(res.begin(),'-');
            }
            return res;
        }
        
        res.push_back('.');
        unordered_map<int,int> umap;
        
        int pos = res.size();
        
        while(num){
            num *= 10;
            
            if(umap.find(num) != umap.end()){       //Quotient can be same for many numerators so we will see the numerator
                break;
            }
            else{
                umap[num] = pos;
            }
            
            a = num/den;
            res.push_back(a + '0');
            num %= den;
            pos++;
        }
        
        if(num != 0){
            pos = umap[num];
            res.insert(res.begin()+pos,'(');
            res.push_back(')');
        }
        if(flag){
            res.insert(res.begin(),'-');
        }
        return res;
    }
};
