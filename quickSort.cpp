#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

int partition(std::vector<int>& ivec, int pivot, int end)
{
	int x = ivec[pivot];
	int i = pivot;
	for(int j = pivot + 1; j != end; j++)
	{
		if(ivec[j] <= x)
		{
			i++;
			std::swap(ivec[i], ivec[j]);
		}
	}
	std::swap(ivec[i], ivec[pivot]);
	return i;

}

void quick_sort(std::vector<int>& ivec, int pivot, int end)
{
	if(pivot < end)
	{
		int q = partition(ivec, pivot, end);
		quick_sort(ivec, pivot, q);
		quick_sort(ivec, q + 1, end);
	}
}


int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::vector<int> ivec;
	for(int i = 0; i != 10; i++)
		ivec.push_back(rand());
	for(auto it : ivec)
		std::cout << it <<" ";
	std::cout << std::endl;
	quick_sort(ivec, 0, ivec.size());
	for(auto it : ivec)
		std::cout << it <<" ";
}
