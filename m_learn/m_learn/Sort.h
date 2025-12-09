#pragma once
#include<vector>
using namespace std;
class Sort
{
public:
	//冒泡排序
	//冒泡排序
	//冒泡排序
	void BubbleSort(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i-1; j++) {
				if (nums[j] > nums[j+1]) std::swap(nums[j], nums[j+1]);
			}
		}
	}


	//快排
	//快排
	//快排
	void quickSort(vector<int>& nums, int left, int right) {
		if (left > right) return;
		int mid = left + (right - left) / 2;
		int i = left;
		int j = right;
		int pivot = nums[mid];
		while (i <= j) {
			while (nums[i] < pivot) {
				i++;
			}
			while (nums[j] > pivot) {
				j--;
			}
			if (i <= j) {
				std::swap(nums[i], nums[j]);
				j--;
				i++;
			}

		}
		quickSort(nums, left, j);
		quickSort(nums, i, right);
	}


	// 归并排序主函数
	// 归并排序主函数
	// 归并排序主函数
	void MergeSort(vector<int>& nums, int left, int right)
	{
		if (left >= right) return;
		int mid = left + (right - left) / 2;
		MergeSort(nums, left, mid);
		MergeSort(nums, mid+1, right);
		merge(nums, left, mid, right);

	}

	void merge(vector<int>& nums, int left,int mid, int right) {
		std::vector<int> tmp;
		int i = left; //左半部分的起始位置
		int j = mid + 1; //右半部分的起始位置

		while (i <= mid && j <= right) {
			if (nums[i] <= nums[j]) {
				tmp.push_back(nums[i]);
				i++;
			}
			else {
				tmp.push_back(nums[j]);
				j++;
			}
		}
		while (i <= mid) {
			tmp.push_back(nums[i]);
			i++;
		}
		while (j <= right) {
			tmp.push_back(nums[j]);
			j++;
		}
		//将排序好的数组重新写回
		for (int i = 0; i < tmp.size(); i++) {
			nums[left + i] = tmp[i];
		}
	}


	//堆排序
	//堆排序
	//堆排序
	void HeapSort(std::vector<int>& nums) {
		int n = nums.size();
		for (int i = n / 2 - 1; i >= 0; i--) {
			heap_just(nums, n, i);
		}
	
		for (int i = n - 1; i > 0; i--) {
			std::swap(nums[0], nums[i]); //最大值算出来了放到最后一个子节点。
			heap_just(nums, i, 0); //从第一个节点开始向下调整
		}
	}

	void heap_just(std::vector<int>& nums, int n, int i) {
		int largest = i;
		int left_children_index = i * 2 + 1;
		int right_children_index = i * 2 + 2;
		if (left_children_index <n && nums[left_children_index]<nums[largest]) {
			largest = left_children_index;
		}
		if (right_children_index <n && nums[right_children_index]<nums[largest]) {
			largest = right_children_index;
		}
		if (largest != i) {
			std::swap(nums[i], nums[largest]);
			heap_just(nums, n, largest);
		}
	}
};

