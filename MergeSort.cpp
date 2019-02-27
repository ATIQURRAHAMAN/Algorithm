#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>

using std::vector;

void merge(vector<int>& ivec, std::size_t low, std::size_t mid, std::size_t high)
{
	size_t n1 = mid - low + 1;
	size_t n2 = high - mid;
	vector<int> Lvec, Rvec;
	//Lvec.resize(n1);
	//std::cout << "n1 =  " <<  n1 << " n2 = " << n2 << " low =  " << low << " mid =  " << mid << " high =  " << high <<  std::endl;
	//Rvec.resize(n2);
	int i, j, k = low;
	for(i = 0; i != n1; ++i)
		Lvec.push_back(ivec[low + i]);
	for(j = 0; j != n2; j++)
		Rvec.push_back(ivec[mid + 1 + j]);
	//std::cout << "LVEC: ";
	
	Lvec.push_back(pow(2, 28));
	Rvec.push_back(pow(2, 28));
	Lvec.resize(n1+1);
	Rvec.resize(n2+1);
	//for(auto it: Lvec)
	//	std::cout << it << " ";
	//std::cout<<std::endl;
	//std::cout << "RVEC: ";
	//for(auto it: Rvec)
	//	std::cout << it << " ";
	//std::cout << std::endl;
	i = j = 0;
	while(k <= high)
	{
		if(Lvec[i] <= Rvec[j])
			ivec[k] = Lvec[i++];
		else
			ivec[k] = Rvec[j++];
		++k;
	}
}


void merge_sort(vector<int> &ivec, size_t low, size_t high)
{
	if(low < high)
	{
		size_t mid = std::floor((low + high)/2);
		merge_sort(ivec, low, mid);
		merge_sort(ivec, mid+1, high);
		merge(ivec, low, mid, high);
	}
}

int main()
{

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	vector<int> ivec;
	for(int i = 0; i != 100000; i++)
		ivec.push_back(rand() * rand());
	//std::time_t start = std::time(NULL);
	//for(auto it : ivec)
	//	std::cout << it <<" ";
	//std::cout << std::endl;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	merge_sort(ivec, 0, ivec.size() - 1);
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_secs = end-start;
	std::cout << "EXECUTED IN " << elapsed_secs.count() << "s";
	//for(auto it : ivec)
	//	std::cout << it <<" ";
}