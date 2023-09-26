#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


/**
 * \brief The function for the recursive bubblesort algorythm
 * \param arr: the vector you want to sort
 * \param n: number of elements in the vector
 */
void bubbleSort(vector<int>& arr, int n)
{
    if (n == 1)
        return;
  
    int count = 0;

    for (int b=0; b<n-1; b++)
        if (arr[b] > arr[b+1]){
            swap(arr[b], arr[b+1]);
            count++;
        }
  
      /* Checks if any recursions happens */
      if (count==0)
           return;
  
    /* Largest element is fixed */
    bubbleSort(arr, n-1);
}

/**
 * \brief Swaps two values
 * \param x 
 * \param y 
 */
void swap(int& x, int& y)
{
	int temp = y;
    y = x;
    x = temp;
    
}

/**
 * \brief The function for the quick sort algorythm
 * \param A: The vector to be sorted
 * \param l: The starting index
 * \param h: The ending index
 */
void quickSort(vector<int>& vector, int start, int end)
{
    int Tstart = start; /* Temporary start */
    int Tend = end; /* Temporary end */
    int mid = start + (end - start) / 2;
    int pivot = vector[mid];

    while (Tstart < end || Tend > start)
    {
	    while (vector[Tstart] < pivot)
	    {
		    Tstart++;
	    }
	    while (vector[Tend] > pivot)
	    {
		    Tend--;
	    }

	    if (Tstart <= Tend)
	    {
		   swap(vector[Tstart], vector[Tend]);
	    	Tstart++;
            Tend--;
	    }
        else
        {
	        if (Tstart < end)
	        {
		      quickSort(vector, Tstart, end);
	        }
            if (Tend > start)
	        {
		      quickSort(vector, start, Tend); 
	        }
            return;
        }
    }
}

/**
 * \brief The function for the selection sort algorythm
 * \param zvector: the vector you want to sort
 * \param n: number of elements in the vector
 */
void SelectionSort(vector<int>& zvector, int n) {
	int min_element;
    for (int i = 0; i < n; i++)
    {
        min_element = i;
        for (int j = i + 1; j < n; j++)
        {
            if (zvector[j] < zvector[min_element])
            {
                min_element = j;
            }
        }
        if (min_element != i)
        {
	      swap(zvector[i], zvector[min_element]);  
        }
        
    }
}


/**
 * \brief Printing for the algorythms
 * \param Vecprint = the vector you want to print out
 */
void printVector(vector<int>& vecprint)
{
    for (int i=0; i < vecprint.size(); i++)
        cout<<vecprint[i]<<"\n";
}

/**
 * \brief prints out and drives the function, also randomizes the values for the algorythm, and prints out the time
 * \
 */
int main()
{
    int input;
    srand(time(NULL));
	vector<int> arr;

    cout<< "How big you want the vector to be? \n";
	cin >> input;
    cout << "\033c";

	for (int i = 0; i < input; i++)
    {
	    arr.emplace_back(rand());
    }
    cout << "press 1 for recursive bubble sort \n";
    cout << "press 2 for recursive quick sort \n";
    cout << "press 3 for iterative selection sort \n";
    cin >> input;
    cout << "\033c";
   
    auto start = high_resolution_clock::now();
    switch (input)
    {
    case 1:
        bubbleSort(arr, arr.size());
        break;
    case 2:
        quickSort(arr, 0, arr.size()-1);
        break;
    case 3:
        SelectionSort(arr, arr.size());
        break;
    }
    auto end = high_resolution_clock::now();
	duration<float> dur = end - start;
    float ms = dur.count()*1000;
    cout<<"Sorted Array: \n";
    printVector(arr);
	cout<< "Time used "<< ms << "ms" <<"\n";
    return 0;
}