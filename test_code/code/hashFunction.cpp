#include<iostream>
#include<string>
#include <unordered_map>


class HashFunction{
    public:
        size_t operator()(const std::string& str)const{
            return std::hash<std::string>{}(str);
        }
};

class PairHash {
    public:
        std::size_t operator()(const std::pair<char, char>& p) const {
            std::size_t hashValue = std::hash<char>()(p.first);
            hashValue ^= std::hash<char>()(p.second) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
            return hashValue;
        }
};


int main(){
    std::unordered_map<std::string,int,HashFunction>hashMap;
    // 添加键值对到无序映射中
    hashMap["apple"] = 10;
    hashMap["banana"] = 20;
    hashMap["cherry"] = 30;

    // 访问无序映射中的键值对
    std::cout << "Value for 'apple': " << hashMap["apple"] << std::endl;
    std::cout << "Value for 'banana': " << hashMap["banana"] << std::endl;
    std::cout << "Value for 'cherry': " << hashMap["cherry"] << std::endl;


    std::unordered_map<std::pair<char, char>, int, PairHash> s_table;

    std::string s = "hello";
    std::string t = "world";
    s_table[std::make_pair(s[0],t[0])] = 15;
    if (s_table.find(std::make_pair(s[0], t[0])) == s_table.end()) {
        // 如果未找到键，执行相应的操作
        std::cout << "Key not found in the map." << std::endl;
    } else {
        // 找到键，返回相应的值
        std::cout << "Key found in the map." << std::endl;
    }
    return 0;

}