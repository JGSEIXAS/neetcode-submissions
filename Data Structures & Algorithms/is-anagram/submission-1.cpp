class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> string_a;
        map<char, int> string_b;
        for(auto a: s){
            string_a[a]++;
        }
        for(auto b: t){
            string_b[b]++;
        }
        for(auto a: s){
            if(string_a[a]==string_b[a]) continue;
            else return false;
        }
        return true;

        

    }
};
