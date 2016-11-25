/*
Visual Studio 2017 RC

MIT License
Copyright (c) 2016 <iamwrm>
<author>           <version>           <date>                   <change>
iamwrm 				1.0              2016-11-25					cooy c++ code from wikipedia


description: 
keywords:   

*/
#include<iostream>

template<typename T>
void quick_sort_recursive(T arr[], int start, int end)
{
	if (start >= end) return;
	T mid = arr[end];
	int left = start, right = end - 1;
	while (left < right)
	{
		while (arr[left] < mid && left < right) left++;
		while (arr[right] >= mid && left < right) right--;
		std::swap(arr[left], arr[right]);
	}
	if (arr[left] >= arr[end])
		std::swap(arr[left], arr[end]);
	else
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}
template<typename T> 
void quick_sort(T arr[], int len)
{
	quick_sort_recursive(arr, 0, len - 1);
}


int main()
{
	int  a[10]{ 1,5,4,4,7,34,4,1,9,6 };
	quick_sort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i]<<" ";
	}
	return 0;

}


