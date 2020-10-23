#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>
#include <iterator>     // std::distance
#include <list>         // std::list

#define MINUS_INT_MAX INT_MAX * (-1)

// [2,1,5,6,2,3]

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        if(heights.size() == 0) {
            return 0;
        }
        int min_height = INT_MAX;
        int max_volume = MINUS_INT_MAX;

        for(int i = 0 ; i < heights.size(); ++i) {
            min_height = INT_MAX;
            for(int j = i ; j >= 0 ; --j) {
                if(heights[j] < min_height)
                    min_height = heights[j];
                int tmp_volume = min_height * (i-j+1);
                max_volume = std::max(max_volume, tmp_volume);
            }
            printf("[%d]V: %d\n",i, max_volume);
        }
        return max_volume;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> height{ 2,1,5,6,2,3 };
    printf("output:%d\n", s -> largestRectangleArea(height));
}
