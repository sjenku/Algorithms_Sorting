//
//  main.cpp
//  AlgoSortNotLibrary
//
//  Created by jenia kushnarenko on 20/03/2020.
//  Copyright © 2020 jenia kushnarenko. All rights reserved.
//

#include "algo.hpp"
#include <time.h>

int main(int argc, const char * argv[]) {
    
    std::srand(time(NULL));
    std::vector<int> vecOfBuble;
    std::vector<int> vecOfSelection;
    std::vector<int> vecOfInsertion;
    std::vector<int> vecOfHeaps;
    int num = 0;
    for(int i = 5;i>0;i--)
    {
        num = std::rand() % 100 + 1;
        vecOfBuble.push_back(num);
        vecOfSelection.push_back(num);
        vecOfInsertion.push_back(num);
        vecOfHeaps.push_back(num);
    }

    
    algo::SelectionSort(vecOfSelection);
    algo::BubbleSort(vecOfBuble);
    algo::InsertionSort(vecOfInsertion);
    algo::HeapSort(vecOfHeaps);
    
    for(auto val : vecOfHeaps)
    {
        printf("%d\n",val);
    }
    
    
    return 0;
}
