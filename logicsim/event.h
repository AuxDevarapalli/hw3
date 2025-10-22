#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(Event* lhs,Event* rhs) const{
            if(lhs->time < rhs->time){
                return true;
            }
            else{
                return false;
            }
        }
} EventLess;
	
#endif
