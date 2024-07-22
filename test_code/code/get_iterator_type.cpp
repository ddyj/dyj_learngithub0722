#include <iostream>
#include <iterator>
#include<typeinfo>
#include <vector>
#include <list>
using namespace std;

template <typename Iterator>
void print_iterator_traits_info(const Iterator& iter) {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::iterator_category category;
    
    std::cout << "Value type: " << typeid(value_type).name() << std::endl;
    std::cout << "Category: " << typeid(category).name() << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + 5);
    std::list<int> lst(vec.begin(), vec.end());
    
    
    print_iterator_traits_info(vec.begin()); // 向量迭代器
    print_iterator_traits_info(lst.begin()); // 链表迭代器
    
    return 0;
}