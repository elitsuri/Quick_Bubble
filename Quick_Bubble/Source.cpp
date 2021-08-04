// -----------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
// -----------------------------------------------------
using namespace std;
const int N = 99999;
// -----------------------------------------------------
void input_numbers(int arr1[N], int arr2[N], vector <int> &arr3);
void print_numbers(int array[N]);
void bubble_sort(int array[N]);
void quick_sort(int array[N], int left, int right);
int partition(int array[N], int left, int right);
// -----------------------------------------------------
int main()
{
	int array1[N], array2[N];
	vector<int> array3;
	input_numbers(array1, array2, array3);
	print_numbers(array1);
	print_numbers(array2);
	bubble_sort(array1);
	cout << "Bubble Sort:\n";
	print_numbers(array1);
	cout << endl;
	quick_sort(array2, 0, N - 1);
	cout << "Quick Sort:\n";
	print_numbers(array2);
	cout << endl;
	sort(array3.begin() , array3.end());
	getchar();
	return 0;
}
// -----------------------------------------------------
void input_numbers(int arr1[N], int arr2[N],vector <int> &arr3)
{
	srand(time_t(NULL));
	for (int i = 0; i < N; ++i)
	{
		arr1[i] = rand() % 10;
		arr2[i] = arr1[i];
		arr3.push_back(arr2[i]);
	}
}
// -----------------------------------------------------
void bubble_sort(int array[N])
{
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (array[i] > array[j])
			{
				int t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
	cout << endl;
}
// -----------------------------------------------------
void quick_sort(int array[N], int left, int right)
{
	int index = partition(array, left, right);

	if (left < index - 1)
		quick_sort(array, left, index - 1);
	if (index < right)
		quick_sort(array, index, right);
}
// -----------------------------------------------------
int partition(int array[N], int left, int right)
{
	int i = left, j = right, tmp;
	int pivot = array[(left + right) / 2];
	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}
void print_numbers(int array[N])
{
	cout << "This is the numbers:\n[";

	for (int i = 0; i < N; ++i)
	{
		cout << array[i];
		if (i == N - 1)
			cout << ']';
		else
			cout << ',';
	}
	array[N];
	cout << endl;
}