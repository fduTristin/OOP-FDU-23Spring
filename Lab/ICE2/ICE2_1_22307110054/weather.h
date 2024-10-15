#ifndef WEATHER_H
#define WEATHER_H
#include<iostream>
#include<vector>
#include<string>


struct city_temp{
    std::string name;
    double temp;
    double deviate;
};

std::istream& read(std::istream& is,std::vector<city_temp>& s);
double average(const std::vector<city_temp>& temp);
std::ostream& print(std::ostream& os,const std::vector<city_temp>& s , double& avg);
void deviate(std::vector<city_temp>&s , double& avg);
bool cmp(const city_temp& x, const city_temp& y);

#endif
