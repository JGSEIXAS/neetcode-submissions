class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        
        vector<int> inicios;
        vector<int> terminos;
        
        // 1. Separamos os horários como se fossem "tickets" independentes
        for (auto& i : intervals) {
            inicios.push_back(i.start);
            terminos.push_back(i.end);
        }
        
        // 2. Ordenamos as duas linhas do tempo
        sort(inicios.begin(), inicios.end());
        sort(terminos.begin(), terminos.end());
        
        int salas_ocupadas = 0;
        int max_salas = 0;
        
        // Ponteiros para as nossas linhas do tempo
        int p_inicio = 0;
        int p_termino = 0;
        
        // 3. Vamos varrendo a linha do tempo (Sweep Line)
        while (p_inicio < inicios.size()) {
            
            // Um carro quer entrar ANTES do próximo carro sair?
            if (inicios[p_inicio] < terminos[p_termino]) {
                salas_ocupadas++; // Precisamos de mais uma sala!
                p_inicio++;       // Lemos o próximo ticket de entrada
            } 
            // Um carro saiu! (A reunião atual terminou antes ou no mesmo minuto da próxima começar)
            else {
                salas_ocupadas--; // Uma sala foi liberada!
                p_termino++;      // Lemos o próximo ticket de saída
            }
            
            // Guardamos a foto de quando o "estacionamento" esteve mais cheio
            max_salas = max(max_salas, salas_ocupadas);
        }
        
        return max_salas;
    }
};