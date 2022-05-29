class Solution {
public:
    string discountPrices(string s, int discount) {
        
        stringstream X(s);
        string temp;
        
        string res;
        while(X >> temp){
            if(temp[0] == '$'){
                bool flag = false;
                for(int i = 1; i < temp.size(); i++){
                    if(!isdigit(temp[i])){
                        flag = true;
                        break;
                    }
                }
                // cout << flag << endl;
                if(!flag){
                    if(temp.size() == 1){
                        res += temp;
                        res.push_back(' ');
                        continue;
                    }
                    long double price = stod(temp.substr(1));
                    price = price - (discount*price)/100.0;
                    
                    res.push_back('$');
                    
                    string newprice = to_string(price);
                    int i = 0;
                    for(; i < newprice.size(); i++){
                        if(newprice[i] == '.') break;
                    }
                    i++;
                    int j = newprice.size() - 1;
                    while(j - i >= 2){
                        newprice.pop_back();
                        j--;
                    }
                    res += newprice;
                    res.push_back(' ');
                }
                else{
                    res += temp;
                    res.push_back(' ');
                }
            }
            else{
                res += temp;
                res.push_back(' ');
            }
        }
        res.pop_back();
        return res;
    }
};
