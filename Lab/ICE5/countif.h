#ifndef COUNTIF_H
#define COUNTIF_H

#include<iostream>

template<typename T , typename P>
int countif(T b , T e , P pred) 
{
    int count = 0;
    while(b != e)
    {
        if(pred(*b)) count++;
        b++;
    }
    return count;
}


#endif