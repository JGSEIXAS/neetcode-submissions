class MedianFinder {
private:
    priority_queue<int> maxHeap; 
    
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // 1. Todo mundo entra primeiro pelo Lado Esquerdo
        maxHeap.push(num);
        
        // 2. Garantimos que o maior cara do Esquerdo vá para o Lado Direito
        // (Isso impede que números gigantes fiquem presos do lado dos "menores")
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // 3. Balanceamento: A regra é que o Esquerdo pode ter no máximo 1 elemento a mais.
        // Se o Direito ficar maior, devolvemos um elemento pro Esquerdo.
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // Se o Lado Esquerdo tem mais gente, o tamanho total é ímpar. 
        // O topo do esquerdo é a resposta exata!
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        
        // Se os tamanhos são iguais (par), pegamos os dois topos e dividimos.
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};