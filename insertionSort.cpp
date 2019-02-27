#include <vector>
#include <iostream>
#include <ctime>

using std::vector;
void selectionSort(vector<int> &ivec)
{
	for(auto it = ivec.begin() + 1 ; it != ivec.end() ; it++)
	{
		int key = *it;
		auto it2 = it - 1;
		while ( it2 >= ivec.begin()  && *it2 > key)
		{
			*(it2 + 1) = *it2;
			--it2;
		}
		*(it2 + 1) = key;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	vector<int> ivec;
	for(int i = 0; i != 10; i++)
		ivec.push_back(rand());
	for(auto it : ivec)
		std::cout << it <<" ";
	std::cout << std::endl;
	selectionSort(ivec);
	for(auto it : ivec)
		std::cout << it <<" ";
}