class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size()%2==1) return false;
        stack <char> brackets;
        for(auto caracter : s){
            if(caracter == '('|| caracter == '{' ||caracter == '['){
                brackets.push(caracter);
            }
            else{
                if(brackets.empty()) return false;
                auto comparador = brackets.top();
                if((comparador == '(' and caracter == ')' )||(comparador == '[' and caracter == ']') ||(comparador == '{' and caracter == '}')){
                    brackets.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        bool resultado = brackets.empty() ? true : false;
        return resultado;

    }
};
