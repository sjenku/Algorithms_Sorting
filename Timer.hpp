//
//  Timer.hpp
//  AlgoSortNotLibrary
//
//  Created by jenia kushnarenko on 22/03/2020.
//  Copyright © 2020 jenia kushnarenko. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::time_point<std::chrono::system_clock> startTime,endTime;
    Timer();
    ~Timer();
};

#endif /* Timer_hpp */
