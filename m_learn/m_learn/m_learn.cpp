#include <iostream>
#include<vector>
#include"Sort.h"

using namespace std;

void print_arr(const vector<int>& nums) {
    int size = nums.size();
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << nums[i];
        if (i != size - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]";
}

int main()
{   
  
    vector<int> arr1 = { 64, 34, 25, 12, 22, 11, 90,0,11,-1,-33 };
    cout << "排序前：" << std::endl;
    print_arr(arr1);
    cout << std::endl;
    Sort sort1;
    sort1.HeapSort(arr1);
    std::cout << "排序后：" << std::endl;
    print_arr(arr1);


}

