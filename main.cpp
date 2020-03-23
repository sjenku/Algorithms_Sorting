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
    
    std::vector<int> someVec {1,6,3,2,10,9,8,5,7,4};
    algo::HeapSort(someVec);
    for(auto val:someVec)
        printf("%d\n",val);
    
    
    return 0;
}
