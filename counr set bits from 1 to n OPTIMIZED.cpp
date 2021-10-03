/*

Reference >> prepcoding utube

Observation >>  say n=11

0 -> 0000
1 -> 0001
2 -> 0010
3 -> 0011
4 -> 0100
5 -> 0101
6 -> 0110
7 -> 0111
8 -> 1000
9 -> 1001
10-> 1010
11-> 1011 

11 se pehle 2 ki highest power 8 hai  2^3 =8 
8 ki madat se hum [0--7] tak jitne bits hai sab nikaal sakte hai
observe karo vertical me right se left tak

[0 se 7] tak 1st vertical row me 4 bits set hai
[0 se 7] tak 2nd vertical row me 4 bits set hai
[0 se 7] tak 3rd vertical row me 4 bits set hai

yaani 2^3/2 bits at 3 places 
 8/2 * 3 = 12
 
 yaani 2^x se pehle muze (2^x-1 * x) bits milengi
 
 
 ab [8-11] me kya hoga
 
 4th vertical row me saare 1 hai matlab usko apan kaise likhenge -> (n - 2^x +1)

ab baaki rows me kya hua -> 
8 -> 1 000
9 -> 1 001
10-> 1 010
11-> 1 011 
     |   \
included  in teeno ko dekhna hai abhi

observe karo vo waapis kiske binary hue->
8 -> 000 -> 8-8  = 0 ka binary
9 -> 001 -> 9-8  = 1 ka binary
10-> 010 -> 10-8 = 2 ka binary
11-> 011 -> 11-8 = 3 ka binary
 
so the formula becomes 

s(n) = (2^x-1 * x) + (n - 2^x +1) + s(3)
                                     / 
                                    bache hue numbers pe waapis same repeat karo

*/

#include <bits/stdc++.h>
using namespace std;
 
int findLargestPower(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
}
 
int countSetBits(int n)
{
    if (n <= 1)
        return n;
    int x = findLargestPower(n);
    return (x * pow(2, (x - 1))) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x));
}
 
int main()
{
    int N = 17;
    cout << countSetBits(N) << endl;
    return 0;
}
