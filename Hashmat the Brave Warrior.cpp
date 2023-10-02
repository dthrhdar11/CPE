#include<iostream>
#include<cmath>
int main()
{
	long long a,b,dif;
	while(std::cin >> a >> b){
		dif = abs(a-b);
		std::cout << dif << std::endl;
	}
}
