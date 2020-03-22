//
//  Timer.cpp
//  AlgoSortNotLibrary
//
//  Created by jenia kushnarenko on 22/03/2020.
//  Copyright © 2020 jenia kushnarenko. All rights reserved.
//

#include "Timer.hpp"



Timer::Timer()
{
    startTime = std::chrono::system_clock::now();
}
Timer::~Timer()
{
    using namespace std::chrono_literals;
    
    std::this_thread::sleep_for(std::chrono::seconds(0s)); //CREATING DELAY FOR                                                                   BETTER CHECKING
    endTime = std::chrono::system_clock::now();
    std::chrono::duration<float> duration = endTime - startTime;
    float ms = duration.count() * 1000.0f;
    std::cout<<"[Timer]: "<<ms<<" ms"<<std::endl;
}
