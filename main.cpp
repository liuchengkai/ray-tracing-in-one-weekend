#include <iostream>
#include "Vec3.h"
using namespace std;

int main(){
    int nx = 200, ny = 100;
    cout << "P3" << endl << nx << " " << ny << endl << "255" <<endl;
    for(int j = ny - 1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            Vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
            float ir = int(256 * col[0]);
            float ig = int(256 * col[1]);
            float ib = int(256 * col[2]);
            cout<<ir<<" "<<ig<<" "<<ib<<endl;
        }
    }
    cout<<"test"<<endl; 
    return 0;
}