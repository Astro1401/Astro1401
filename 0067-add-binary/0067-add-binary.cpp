class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string s = "";
        while(i>=0 || j>=0 || carry){
        
        int digit1 = i >= 0 ? a[i] - '0' : 0;
        int digit2 = j >= 0 ? b[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        s.push_back((sum % 2) + '0'); // append current bit
            carry = sum / 2; // update carry
            
            i--;
            j--;
        }

        reverse(s.begin(),s.end());
        return s;

    }
};