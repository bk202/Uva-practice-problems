#include <iostream>

#define INFINITY 10000000

using namespace std;

int min_SA(int num){
	
	int min = INFINITY;
	//int mina, minb, minc;
	for(int a=1; a<=num; a++){
		for(int b=1; b<=num; b++){
			int ab = a * b;
			if(a * b > num) break;
			int c = num % ab;
			if(c != 0) continue;
			c = num/ab;
			int area = (2 * a * b) + (2 * b * c) + (2 * a * c);
			if(area < min){
				min = area;
				/*mina = a;
				minb = b;
				minc = c;*/
			}
		}
	}
	//cout<<mina<<" "<<minb<<" "<<minc<<endl;
	return min;
}


int main(){
	int trials;
	cin>>trials;
	for(int i=0; i<trials; i++){
		int num;
		cin>>num;
		cout<<min_SA(num)<<endl;
	}
}
