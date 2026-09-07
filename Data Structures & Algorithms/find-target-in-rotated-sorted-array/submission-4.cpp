class Solution {
public:
    int search(vector<int>& nums, int target) {
        int esquerda = 0;
        int direita = nums.size() -1;
        while(esquerda < direita){
            int meio = esquerda + (direita - esquerda)/2;
            if(nums[meio] > nums[direita]){
                esquerda = meio + 1;
            }
            else{
                direita = meio;
            }
        }

        int pivot = esquerda;
        esquerda= 0;
        direita = nums.size()-1;
        if(target >= nums[pivot] and target <= nums[direita]){
            esquerda = pivot;
        }
        else{
            direita = pivot -1;
        }

        while(esquerda <= direita){
            int meio = esquerda + (direita - esquerda)/2;
            if(nums[meio] == target) return meio;
            if(nums[meio] > target){
                direita = meio - 1;
            }
            else{
                esquerda = meio +1;
            }
        }
        return -1;
    }
};
