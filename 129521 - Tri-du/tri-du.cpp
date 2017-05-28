#include <iostream>

using namespace std;

int tridu(int a, int b){
	return ((a >= b) * a) + ((b > a) * b);
}

int main(){
	int a, b;
	while(cin>>a>>b){
	
	cout<<tridu(a, b)<<endl;
	}
}
