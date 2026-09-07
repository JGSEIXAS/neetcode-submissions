class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> maptime;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        maptime[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int esquerda = 0;
        int direita = maptime[key].size() - 1;
        string resp = "";
        
        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            
            if (maptime[key][meio].first <= timestamp) {
                
                resp = maptime[key][meio].second;
                
                esquerda = meio + 1;
            } 
            else {
                direita = meio - 1;
            }
        }
        
        return resp;
    }
};