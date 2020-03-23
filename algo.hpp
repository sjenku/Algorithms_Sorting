//
//  algo.hpp
//  AlgoSortNotLibrary
//
//  Created by jenia kushnarenko on 22/03/2020.
//  Copyright © 2020 jenia kushnarenko. All rights reserved.
//

#ifndef algo_hpp
#define algo_hpp

#include <iostream>
#include <vector>
#include <string>

namespace algo {

template<typename T>
void BubbleSort(std::vector<T>& vec);

template<typename T>
void SelectionSort(std::vector<T>& vec);

template<typename T>
void InsertionSort(std::vector<T>& vec);

template<typename T>
void HeapSort(std::vector<T>& vec);

template<typename T>
void QuickSort(std::vector<T>& vec,int firstIndex,int lastIndex);

template<typename T>
void MergeSort(std::vector<T>& vec,int l,int r);

}

#endif /* algo_hpp */
