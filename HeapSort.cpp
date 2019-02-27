#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

void maxHeapify(vector<int>& ivec, size_t index, size_t heapSize)
{
	size_t left_index = index * 2 + 1;
	size_t right_index = index * 2 + 2;
	size_t largest = index;
	if(left_index < heapSize && ivec[left_index] > ivec[index])
		largest = left_index;
	if(right_index < heapSize && ivec[right_index] > ivec[largest])
		largest = right_index;
	 
	if(largest != index)
	{
		std::swap(ivec[largest], ivec[index]);
		maxHeapify(ivec, largest, heapSize);
	}
}

void buildHeap(vector<int>& ivec, size_t& heapSize)
{
	heapSize = ivec.size();
	std::cout << heapSize << std::endl;
	for(size_t i = ivec.size() / 2 - 1; i >= 0 && i < heapSize; i--)
		maxHeapify(ivec, i, heapSize);
}

void heapSort(vector<int>& ivec)
{
	size_t heapSize;
	buildHeap(ivec, heapSize);

	for(int ind = ivec.size() - 1; ind >= 0 && ind < heapSize; --ind)
	{
		std::swap(ivec[0], ivec[ind]);
		heapSize--;
		maxHeapify(ivec, 0, heapSize);
		//maxHeapify(ivec, 0, ind);
	}
}

int main()
{

	vector<int> ivec{0, 7, 1, 9, 5, 3, 15};
	//size_t heapSize = ivec.size();
	//std::cout << heapSize << std::endl;
	//buildHeap(ivec, heapSize);
	heapSort(ivec);
	for(auto it: ivec)
		std::cout << it << " ";
}


