class Solution {
public:
    bool isPalindrome(string s) {
        string palavra;
        for(auto c : s){
            if(c == ' ' || !isalnum(c)) continue;
            else palavra += c;
        }
        s = palavra;
        cout << s<< endl; 
        int i = 0;
        int j = s.size() - 1;
        bool resultado = false;
        while(i < j) {
            if(toupper(s[i]) != toupper(s[j])) {
                break;
            } else {
                i++;
                j--;
            }
        }
        if(i >= j) resultado = true;
        return resultado;
    }
};
