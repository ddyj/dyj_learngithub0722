#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

template<class T>
struct my_cmp : public binary_function<T,T,bool>{
   bool operator()(const T&a,const T&b){
        return 2*a > b;
   }
};

int main(){
    vector<int>su = {1,15,48,56,2,4,9,5,3,7};
    sort(su.begin(),su.end(),my_cmp<int>());
    for(int a : su){
        std::cout << a <<" ";
    }
    std::cout << "\n";
    return 0;
}
//56 48 9 15 7 3 5 4 2 1 
