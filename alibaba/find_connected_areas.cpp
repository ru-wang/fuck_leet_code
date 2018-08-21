#include <cassert>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace {

std::unordered_map<int, int>
find_connected_areas(const std::vector<int>& img, int w, int h) {
    if (w == 0 || h == 0 || img.size() != w * h)
        return {};

    /* print the origin image */
    std::cout << "[input]\n";
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c)
            std::cout << img[r*w+c];
        std::cout << "\n";
    }
    std::cout << std::endl;

    std::unordered_map<int, int> areas;
    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            const int seed = row * w + col;

            /* skip visited pixel */
            if (areas.find(seed) != areas.end())
                continue;

            areas[seed] = seed;
            std::vector<int> stack(1, seed);
            while (not stack.empty()) {
                int k = stack.back();
                stack.pop_back();
                areas[k] = seed;
                int cur_row = k / w;
                int cur_col = k % w;

                /* check right pixel */
                if (cur_col + 1 < w && img[seed] == img[k+1] &&
                        areas.find(k+1) == areas.end())  /* avoid duplicates */
                    stack.push_back(k+1);

                /* check below pixel */
                if (cur_row + 1 < h && img[seed] == img[k+w] &&
                        areas.find(k+w) == areas.end())
                    stack.push_back(k+w);

                /* check left pixel */
                if (cur_row > 0 && img[seed] == img[k-w] &&
                        areas.find(k-w) == areas.end())
                    stack.push_back(k-w);

                /* check above pixel */
                if (cur_col > 0 && img[seed] == img[k-1] &&
                        areas.find(k-1) == areas.end())
                    stack.push_back(k-1);
            }
        }
    }

    /* print the result */
    assert(areas.size() == w * h);
    std::cout << "[output]\n";
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c)
            std::cout << std::setw(4) << areas.at(r*w+c);
        std::cout << "\n";
    }
    std::cout << std::endl;

    return areas;
}

}

int main() {
    /* test case 1 */ {
        std::vector<int> image {
            0,0,0,2,0,3,3,3,
            0,0,2,2,0,0,3,3,
            0,0,1,1,1,1,1,1,
            0,0,0,0,0,1,1,1,
        };
        auto connected_areas = find_connected_areas(image, 8, 4);
    }

    /* test case 2 */ {
        std::vector<int> image {
            0,0,0,2,0,3,3,3,
            0,0,0,0,0,0,3,3,
            0,0,1,1,1,1,1,1,
            0,0,0,0,0,1,1,1,
        };
        auto connected_areas = find_connected_areas(image, 8, 4);
    }

    /* test case 3 */ {
        std::vector<int> image {
            0,0,0,
            0,0,0,
            0,0,1,
            0,0,0,
        };
        auto connected_areas = find_connected_areas(image, 3, 4);
    }

    /* test case 4 */ {
        std::vector<int> image {
            0,0,0,
            0,0,0,
            0,0,0,
        };
        auto connected_areas = find_connected_areas(image, 3, 3);
    }

    /* test case 5 */ {
        std::vector<int> image;
        auto connected_areas = find_connected_areas(image, 0, 0);
    }

    return 0;
}
