//
//  main.cpp
//  barclays
//
//  Created by Yujian Zhao on 5/12/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
public:
    Polynomial(const vector<int> coeff) {
        for (int num : coeff){
            coeff_.push_back(num);
        }
    }
    void multiply(const Polynomial& other) {
        vector<int> coeff = other.getCoeff();
        
        int m = coeff_.size();
        int n = coeff.size();
        int N = m + n - 1;;
        vector<int> res(N, 0);
        // calculate the coefficient for power of k
        for (int k = 0; k < N; k++){
            for (int i = 0; i <= k; ++i){
                int j = k - i;
                if (i < m && j < n){
                    res[k] += coeff_[i] * coeff[j];
                }
                
            }
        }
        coeff_ = res;
    }
    
    vector<int> getCoeff() const {
        return coeff_;
    }
private:
    vector<int> coeff_;
};

void print_vector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i){
        if (i == 0){
            cout << v[i];
        } else {
            cout << " " << v[i];
        }
    }
    cout << "]" << endl;
}

int main(int argc, const char * argv[]) {
    Polynomial p1 = Polynomial({1,1,1});
    print_vector(p1.getCoeff());
    Polynomial p2 = Polynomial({1,1,1});
    p1.multiply(p2);
    print_vector(p1.getCoeff());
    
}
