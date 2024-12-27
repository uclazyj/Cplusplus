//
//  main.cpp
//  new_and_delete
//
//  Created by Yujian Zhao on 12/25/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int* arr = new int[5];
    arr[0] = 1;
    cout << arr[0] << endl;
    
    delete [] arr;
    
    return 0;
}
