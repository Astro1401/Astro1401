class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        
        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }

        string p = "";
 
        for(int i = 0; i<s.length(); i++){
            
            if(s[i] == '('){
                string k = "";
                i++;
                while(s[i] != ')'){
                    k.push_back(s[i]);
                    i++;
                }
                if(mp.find(k) != mp.end())
                    p += mp[k];
                else{
                    p += "?";
                }
                
                continue;
            }

            p.push_back(s[i]);
        }

        return p; 
    }
};