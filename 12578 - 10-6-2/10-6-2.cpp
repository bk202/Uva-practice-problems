#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
        int T;
        cin>>T;
        for(int i=0; i<T; i++){
                double L;
                cin>>L;
                
                double width = 0.6 * L;
                double radius = 0.2 * L;
                
                double total_area = L * width;
                double pi = acos(-1);
                
                double circle_area = pi * radius * radius;
                
                double green_area = total_area - circle_area;

                cout << fixed << setprecision(2) << circle_area << " " << green_area << endl;
        }
        return 0;
}
