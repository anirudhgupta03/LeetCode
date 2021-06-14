class Solution {
public:
    string intToRoman(int n) {
        
        string roman = "";
        
        for(int i = 1; i <= n/1000; i++){
            roman.push_back('M');
        }
        
        n %= 1000;
        
        if(n / 100 == 9){
            roman += "CM";
            n %= 100;
        }
        else{
            
            for(int i = 1; i <= n/500; i++){
                roman.push_back('D');
            }
            n %= 500;
        }
        
        if(n/100 == 4){
            roman += "CD";
            n %= 100;
        }
        else{
            
            for(int i = 1; i <= n/100; i++){
                roman.push_back('C');
            }
            
            n %= 100;
        }
        
        if(n/10 == 9){
            roman += "XC";
            n %= 10;
        }
        else{
            
            for(int i = 1; i <= n/50; i++){
                roman.push_back('L');
            }
            
            n %= 50;
        }
        
        if(n / 10 == 4){
            roman += "XL";
            n %= 10;
        }
        else{
            
            for(int i = 1; i <= n/10; i++){
                roman.push_back('X');
            }
            
            n %= 10;
        }
        
        if(n == 9){
            roman += "IX";
            n %= 1;
        }
        else{
            
            for(int i = 1; i <= n/5; i++){
                roman.push_back('V');
            }
            
            n %= 5;
        }
        
        if(n == 4){
            roman += "IV";
            n %= 1;
        }
        else{
            
            for(int i = 1; i <= n; i++){
                roman.push_back('I');
            }
            n %= 1;
        }
        
        return roman;
    }
};
