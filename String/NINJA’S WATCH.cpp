
//Ref:https://www.youtube.com/watch?v=99Gw7Hezii8
//https://www.codingninjas.com/codestudio/problems/ninja-s-watch_1264948?topList=top-uber-coding-interview-questions&leftPanelTab=0

//Approach - 1
//TLE
bool isValid(string t){
    
    if(t[3] > '5'){
        return false;
    }
    if(t[0] == '2'){
        if(t[1] > '3'){
            return false;
        }
    }
    if(t[0] > '2'){
        return false;
    }
    return true;
}
void solve(vector<int> &digits, string &temp, vector<string> &res){
    
    if(temp.size() == 5){
        res.push_back(temp);
        return;
    }
    
    if(temp.size() == 2){
        temp.push_back(':');
        solve(digits, temp, res);
        temp.pop_back();
        return;
    }
    
    if(temp.size() == 0){
        for(int i = 0; i < digits.size(); i++){
            if(digits[i] < 3){
                temp.push_back(digits[i] + '0');
                solve(digits, temp, res);
                temp.pop_back();
            }
        }
    }
    else if(temp.size() == 1){
        if(temp[0] == '2'){
            for(int i = 0; i < digits.size(); i++){
                if(digits[i] < 4){
                    temp.push_back(digits[i] + '0');
                    solve(digits, temp, res);
                    temp.pop_back();
                }
            }
        }
        else{
            for(int i = 0; i < digits.size(); i++){
                    temp.push_back(digits[i] + '0');
                    solve(digits, temp, res);
                    temp.pop_back();
            }
        }
    }
    else if(temp.size() == 4){
        for(int i = 0; i < digits.size(); i++){
                temp.push_back(digits[i] + '0');
                solve(digits, temp, res);
                temp.pop_back();
        }
    }
    else if(temp.size() == 3){
        for(int i = 0; i < digits.size(); i++){
            if(digits[i] < 6){
                temp.push_back(digits[i] + '0');
                solve(digits, temp, res);
                temp.pop_back();
            }
        }
    }
}
int converttomin(string t){
    
    int hr = stoi(t.substr(0,2));
    int min = stoi(t.substr(3,2));
    
    int ti = 60*hr + min;
    return ti;
}

string ninjaWatch(string &time)
{
    int alpha[10] = {0};
    
    for(int i = 0; i < time.size(); i++){
        if(time[i] != ':'){
            alpha[time[i] - '0']++;
        }
    }
    
    vector<int> digits;
    
    for(int i = 0; i < 10; i++){
        if(alpha[i] != 0){
            digits.push_back(i);
        }
    }
    vector<string> res;
    string temp;
    solve(digits,temp,res);
    
    int mins = converttomin(time);
    
    int diff = INT_MAX;
    string closest;
    
    for(int i = 0; i < res.size(); i++){
        
        int tmins = converttomin(res[i]);
        
        if(tmins > mins){
            if(tmins - mins < diff){
                diff = tmins - mins;
                closest = res[i];
            }
        }
        else{
            if(tmins + 2400 > mins){
                if(tmins + 2400 - mins < diff){
                    diff = tmins + 2400 - mins;
                    closest = res[i];
            	}
            }
        }
    }
    return closest;
}


//Approach - 2
//Accepted
string ninjaWatch(string &time)
{
    int minutes = stoi(time.substr(0,2))*60;
    minutes += stoi(time.substr(3,2));
    
    unordered_set<int> us;
    for(int i = 0; i < time.size(); i++){
        if(time[i] != ':'){
            us.insert(time[i] - '0');
        }
    }
    while(1){
        
        minutes = (minutes + 1)%1440;
        
        vector<int> v(4);
        v[0] = minutes/600;
        v[1] = (minutes/60)%10;
        v[2] = (minutes%60)/10;
        v[3] = (minutes%60)%10;
        
        bool flag = true;
        for(int i = 0; i < 4; i++){
            if(us.find(v[i]) == us.end()){
                flag = false;
                break;
            }
        }
        if(flag){
            string s;
            s.push_back(v[0] + '0');
            s.push_back(v[1] + '0');
            s.push_back(':');
            s.push_back(v[2] + '0');
            s.push_back(v[3] + '0');
            return s;
        }
    }
}
