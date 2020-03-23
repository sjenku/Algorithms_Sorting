//
//  algo.cpp
//  AlgoSortNotLibrary
//
//  Created by jenia kushnarenko on 22/03/2020.
//  Copyright © 2020 jenia kushnarenko. All rights reserved.
//

#include "algo.hpp"
#include "Timer.hpp"


template<typename T>
void algo::BubbleSort(std::vector<T>& vec)
{
    Timer timer; //Custom Timer
    for(unsigned int i = 0;i<vec.size() - 1;i++)
    {
        for(unsigned int j = 0;j<vec.size() - 1 - i;j++)
        {
            if (vec[j] > vec[j+1])
            {
                T temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
}

template<typename T>
void algo::SelectionSort(std::vector<T>& vec)
{
    Timer timer;  //Custom Timer
    for(unsigned int i = 0;i<vec.size();i++)
    {
        int CurrentMinIndex = i;
        for(unsigned int j = i+1;j<vec.size();j++)
        {
            if (vec[CurrentMinIndex] > vec[j])
            {
                CurrentMinIndex = j;
            }
        }
        T tmp = vec[i];
        vec[i] = vec[CurrentMinIndex];
        vec[CurrentMinIndex] = tmp;
    }
}

template<typename T>
void algo::InsertionSort(std::vector<T>& vec)
{
    Timer timer;
    for(int i = 0;i<vec.size();i++)
    {
        int j = i;
        while(j > 0 && vec[j - 1]>vec[j])
        {
            T tmp = vec[j - 1];
            vec[j - 1] = vec[j];
            vec[j] = tmp;
            j--;
        }
    }
}

template<typename T>
static void heapify(std::vector<T>& vec,int size,int i)
{
    int largest = i;
    int lc = i * 2 + 1;
    int rc = i * 2 + 2;
    if( lc < size && vec[lc] > vec[largest])
    {
        largest = lc;
    }
    if (rc < size && vec[rc] > vec[largest])
    {
        largest = rc;
    }
    if (largest != i)
    {
        T tmp = vec[largest];
        vec[largest] = vec[i];
        vec[i] = tmp;
        heapify(vec,size,largest);
    }
}

template<typename T>
void algo::HeapSort(std::vector<T>& vec)
{
    Timer timer;
    for(int i = static_cast<int>((vec.size() - 1) / 2 - 1) ; i >= 0 ;i-- )
    {
        heapify(vec,static_cast<int>(vec.size()), i);
    }
    
    for(int i = static_cast<int>(vec.size() - 1);i>= 0;i--)
    {
        T root = vec[0];
        vec[0] = vec[i];
        vec[i] = root;
        heapify(vec,i, 0);
    }
}

template<typename T>
static int partition(std::vector<T>& vec,int low,int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    while(i < j)
    {
        do
        {
            i++;
        } while(vec[i] <= vec[pivot] && i<j);
        
         while (vec[j] > vec[pivot]) j--;
        if (i < j)
        {
            T tmp = vec[i];
            vec[i] = vec[j];
            vec[j]  = tmp;
        }
    }
    T tmp = vec[j];
    vec[j] = vec[pivot];
    vec[pivot] = tmp;
    return j;
}

template<typename T>
void algo::QuickSort(std::vector<T>& vec,int firstIndex,int lastIndex)
{
   if(firstIndex<lastIndex)
   {
       int seperator = partition(vec, firstIndex, lastIndex);
       algo::QuickSort(vec, firstIndex, seperator - 1);
       algo::QuickSort(vec, seperator+1, lastIndex);
   }
    
}



template void algo::BubbleSort(std::vector<int>&);
template void algo::BubbleSort(std::vector<float>&);
template void algo::BubbleSort(std::vector<double>&);
template void algo::BubbleSort(std::vector<char>&);
template void algo::BubbleSort(std::vector<std::string>&);

template void algo::SelectionSort(std::vector<int> &);
template void algo::SelectionSort(std::vector<float> &);
template void algo::SelectionSort(std::vector<double> &);
template void algo::SelectionSort(std::vector<char> &);
template void algo::SelectionSort(std::vector<std::string>&);

template void algo::InsertionSort(std::vector<int> &);
template void algo::InsertionSort(std::vector<float> &);
template void algo::InsertionSort(std::vector<double> &);
template void algo::InsertionSort(std::vector<char> &);
template void algo::InsertionSort(std::vector<std::string>&);

template void algo::HeapSort(std::vector<int>&);
template void algo::HeapSort(std::vector<float>&);
template void algo::HeapSort(std::vector<double>&);
template void algo::HeapSort(std::vector<char>&);
template void algo::HeapSort(std::vector<std::string>&);

template void algo::QuickSort(std::vector<int>& vec,int firstIndex,int lastIndex);
template void algo::QuickSort(std::vector<float>& vec,int firstIndex,int lastIndex);
template void algo::QuickSort(std::vector<double>& vec,int firstIndex,int lastIndex);
template void algo::QuickSort(std::vector<char>& vec,int firstIndex,int lastIndex);
template void algo::QuickSort(std::vector<std::string>& vec,int firstIndex,int lastIndex);
