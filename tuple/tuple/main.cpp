//
//  main.cpp
//  tuple
//
//  Created by Yujian Zhao on 5/9/25.
//

#include <iostream>
#include <tuple>

int main(int argc, const char * argv[]) {
    std::tuple<int, int, int> t = {3,1,2};
    std::cout << std::get<0>(t) << std::endl;
    
    //    The following does not work since we need to use a compile time constant for the index
    
    //    for (int i = 0; i < 3; ++i){
    //        std::cout << std::get<i>(t) << " ";
    //    }
}
