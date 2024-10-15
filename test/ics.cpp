#include<iostream>

int mul3(int x) {
  int absvx = x + (((x >> 31) & (~x + 1)) << 1);
  int mod = (1 << 16) + ~1 + 1;
  int t = (absvx >> 16) & mod;
  int p = absvx & mod;
  int t_p = (p << 1) + p;
  int t_t = (t << 1) + t + (t_p >> 16);
  int flag = !(!(t_t >> 15));
  int _and = ~1 + 1 + flag;
  int sig = (x >> 31) & 1;
  return (((x << 1) + x) & _and) + ((sig + ~(1 << 31)) & (~_and));
}
int main()

{
    std::cout<<(((int)0x80000000)>>1);
}