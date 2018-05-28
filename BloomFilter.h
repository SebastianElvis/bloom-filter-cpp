#include <vector>

using namespace std;

template <class T>
class BloomFilter
{
public:
    BloomFilter(int size, int hash_count);
    bool add(T elem);
    bool contains(T elem);
private:
    vector<bool> array;
    int hash_count = 0;
};