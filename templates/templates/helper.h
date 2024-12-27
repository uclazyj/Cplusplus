//
//  helper.h
//  templates
//
//  Created by Yujian Zhao on 12/27/24.
//

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
