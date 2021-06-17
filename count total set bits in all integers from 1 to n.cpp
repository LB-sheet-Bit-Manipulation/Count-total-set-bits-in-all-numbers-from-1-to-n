//My approach:
//Traverse from 1 to n one by one                       >> TC O(n)
//Find set bits for each integer(already done such Q)   >> TC O(logn) 
//                                                      >> Total TC O(nlogn) 

//Issue:
//TC ko O(n) ya O(logn) pe laao.Its O(nlogn) currently


#include<iostream>

using namespace std;

int countSetBits(int n)
{
	int count=0;
	
	//while(n) is equivalent to while(n!=0)
	while(n)
	{
		count=count+(n&1);
		n=n>>1;    //rightshift by 1
	}
	return count;
}

int main() 
{ 
	//bitwise operations becomes undefined in negative numbers. so unsigned int is used.
	unsigned int n;
	int i,total=0;
	
	cout<<"\nEnter n ";
	cin>>n;
	 
	//corner case:
	//n>0 else bitwise operations will be undefined and meaningless
	if(n>=0) 
	{
		for(i=1;i<=n;i++)
		{
			total=total+countSetBits(i);
		}
		cout<<"\nThe total set bits from 1 to  "<<n<<" are "<<" "<<total;
	}
	else
	{
		cout<<"\nThe input number is negative AND hence invalid!!";	
	}
		
	return 0;
}
