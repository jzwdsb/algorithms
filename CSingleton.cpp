//
// Created by manout on 18-3-28.
//

#include "CSingleton.h"

CSingleton::CSingleton()
{
     /** do something here*/
}

CSingleton &CSingleton::get_instance()
{
    static CSingleton instance;
    return instance;
}

