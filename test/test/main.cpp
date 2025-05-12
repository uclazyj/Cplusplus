//
//  main.cpp
//  test
//
//  Created by Yujian Zhao on 5/10/25.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> v = {1,2,3,4,5,6};
    auto iter = v.begin();
    v.erase(v.begin()+2);
    for (int num : v){
        cout << num << " ";
    }
    cout << endl;
    
    for (; iter < v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}
