class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> numeros;

        for(auto valores: tokens){
            if(valores == "+"||valores =="-"|| valores =="*"|| valores == "/"){
                int num_a = numeros.top();
                numeros.pop();
                int num_b = numeros.top();
                numeros.pop();
                int resultado;
                switch (valores[0]){
                    case '+':
                        resultado = num_a + num_b;
                        break;
                    case '*':
                        resultado = num_a * num_b;
                        break;
                    case '/':
                        resultado = num_b / num_a;
                        break;
                    case '-':
                        resultado = num_b - num_a;
                        break;
                }
                numeros.push(resultado);
            }
            else{
                int num = stoi(valores);
                numeros.push(num);
            }
        }
        return numeros.top();
    }
};
