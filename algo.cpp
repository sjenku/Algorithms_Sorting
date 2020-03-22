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

