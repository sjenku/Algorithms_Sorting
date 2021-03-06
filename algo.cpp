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
static void Swap(T* const first,T* const second)
{
    T tmp = *first;
    *first = *second;
    *second = tmp;
}

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
                Swap(&vec[j], &vec[j+1]);
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
        Swap(&vec[i], &vec[CurrentMinIndex]);
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
            Swap(&vec[j-1], &vec[j]);
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
        Swap(&vec[largest], &vec[i]);
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
        Swap(&vec[0], &vec[i]);
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
            Swap(&vec[i], &vec[j]);
        }
    }
    Swap(&vec[j], &vec[pivot]);
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

template<typename T>
static void merge(std::vector<T>& vec,int l,int m,int r)
{
    int size1 = m - l + 1;
    int size2 = r - m;
    T tmpLeftArr[size1];
    T tmpRightArr[size2];
    int z = 0;
    for(int i = l;i<=m;i++)  //Copy to tmp Arr All Left Side values
    {
        tmpLeftArr[z] = vec[i];
        z++;
    }
    for(int i = m+1,z = 0;i<=r;i++)  //Copy to tmp Arr All Right Side values
    {
        tmpRightArr[z] = vec[i];
        z++;
    }
    int i = 0;
    int j = 0;
    int k = l;
    
    while(i < size1 && j < size2)  //Compare and insert Elements/->Merge
    {
        if(tmpLeftArr[i] <= tmpRightArr[j])
        {
            vec[k] = tmpLeftArr[i];
            i++;
        }
        else
        {
            vec[k] = tmpRightArr[j];
            j++;
        }
        k++;
    }
    
    while( i < size1 ) //Copy Remain Elements
    {
        vec[k] = tmpLeftArr[i];
        i++;
        k++;
    }
    
    while ( j < size2 )
    {
        vec[k] = tmpRightArr[j];
        j++;
        k++;
    }
}

template<typename T>
void algo::MergeSort(std::vector<T>& vec,int l,int r)
{
    if(l<r)
    {
        int m = (r - l)/2 + l;
        MergeSort(vec,l,m);
        MergeSort(vec,m+1,r);
        merge(vec,l,m,r);
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

template void algo::MergeSort(std::vector<int>& vec,int l,int r);
template void algo::MergeSort(std::vector<float>& vec,int l,int r);
template void algo::MergeSort(std::vector<double>& vec,int l,int r);
template void algo::MergeSort(std::vector<char>& vec,int l,int r);
template void algo::MergeSort(std::vector<std::string>& vec,int l,int r);
