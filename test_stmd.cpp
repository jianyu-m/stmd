
#include "stmd.hpp"
#include <iostream>

typedef std::uint_fast32_t u32;
typedef std::uint_fast64_t u64;
int main() {

    STMD stmd(4);

    stmd.parallelize_loop(0, 10, [](u32 idx){
        std::cout << "doing task at " << idx << "\n";
    });
    int arr[100];
    stmd.parallelize_loop(0, 100, [&arr](u32 idx){
        arr[idx] = idx;
    });
    for (int i = 0;i < 100;i++) {
        std::cout << arr[i] << "\n";
    }
}