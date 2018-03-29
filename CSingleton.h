//
// Created by manout on 18-3-28.
//

#ifndef ALOGRITHMS_CSINGLETON_H
#define ALOGRITHMS_CSINGLETON_H

#include <mutex>


class CSingleton
{
private:
    CSingleton();
    
public:
    CSingleton(const CSingleton&) = delete;
    CSingleton& get_instance();
};



#endif //ALOGRITHMS_CSINGLETON_H
