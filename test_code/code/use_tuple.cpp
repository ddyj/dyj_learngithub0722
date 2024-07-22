#include<iostream>
#include<tuple>
#include <memory>

using namespace std;
int main(){
    auto myTuple = std::make_tuple(10, "Hello", 3.14);
    // Access tuple elements
    std::cout << "First element: " << std::get<0>(myTuple) << std::endl;
    std::cout << "Second element: " << std::get<1>(myTuple) << std::endl;
    std::cout << "Third element: " << std::get<2>(myTuple) << std::endl;
}