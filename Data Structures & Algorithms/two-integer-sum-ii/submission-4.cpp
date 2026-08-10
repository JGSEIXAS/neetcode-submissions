class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0;
        int j = numbers.size() - 1;
        vector<int> resultado;
        while(i != j){
            if(numbers[i]+numbers[j]> target){
                j--;           
            }
            else if(numbers[i]+numbers[j] == target){
                resultado.push_back(i +1);
                resultado.push_back(j +1);
                return resultado;
            }
            else i++;
        }
        return resultado;
    }
};
