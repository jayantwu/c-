#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;



struct S1 {
    int a;
    int b;
    S1(int _a, int _b) : a(_a), b(_b){}
};

struct S2 {
    int c;
    S1 s1;
    S2(int a, int b, int _c): s1(a, b), c(_c) {}
};

struct cmp_fun {
    bool operator()(const S2& l, const S2& r) const {
        if (l.c != r.c)
            return l.c < r.c;
        
        if (l.s1.a != r.s1.a)
            return l.s1.a < r.s1.a;

        return l.s1.b < r.s1.b;
    }
};

struct equal_fun {
    bool operator()(const S2& l, const S2& r) const {
        if (l.c != r.c)
            return false;
        
        if (l.s1.a != r.s1.a)
            return false;
        
        return l.s1.b == r.s1.b;

    }
};

struct hash_fun {  
    size_t operator()(const S2& s) const {  
        // 这里只是一个简单的哈希函数示例，  
        // 实际应用中可能需要更复杂的哈希算法来减少哈希冲突  
        std::hash<int> hasher;  
        size_t hash = hasher(s.c); // 假设c的哈希值很重要  
        hash ^= hasher(s.s1.a) + 0x9e3779b9 + (hash << 6) + (hash >> 2); // 使用XOR Shift  
        hash ^= hasher(s.s1.b) + 0x9e3779b9 + (hash << 6) + (hash >> 2); // 再次使用XOR Shift  
        return hash;  
    }  
};  

unordered_map<S2, uint32_t, hash_fun, equal_fun> mymap;

map<S2, uint32_t, cmp_fun> mymap2;

int main()
{
    S2 s2(1, 2, 3);
    mymap[s2] = 2;
    mymap2[s2] = 3;

    cout << mymap[s2] << endl;
    cout << mymap2[s2] << endl;

} 