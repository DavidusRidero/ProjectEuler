#include <bits/stdc++.h>

using position = std::pair <size_t, size_t>;
std::set <std::pair<int, position>, std::greater<>> Positions;
std::array<std::array<int, 20>, 20> array{};

int safe_get(const int x, const int y) {
    try {
        return array.at(x).at(y);
    }
    catch (const std::out_of_range&) {
        return 0;
    }
}

auto offset_product_at_position (const size_t x, const size_t y, const int i, const int j) {
    unsigned long long product { 1 };
    int x_offset = 0, y_offset = 0;
    auto loop = 4;

    while (loop--) {
        product *= safe_get(x+x_offset, y+y_offset);
        x_offset += i;
        y_offset += j;
    }

    return product;
}

auto max_product_at_position (const size_t x, const size_t y) {
    std::set<unsigned long long, std::greater<>> Products;

    for (int i {-1}; i <= 1; i++)
        for (int j {-1}; j <= 1; j++) {
            if (i==0 and j==0) continue;
            Products.insert(offset_product_at_position(x,y,i,j));
        }

    return *Products.begin();
}

void ingest() {
    const std::string input {"P11_Input.txt"};
    std::ifstream fin (input);

    for (size_t i {}; i < 20; i++)
        for (size_t j {}; j < 20 and fin >> array[i][j]; j++)
            Positions.emplace(array[i][j], std::make_pair(i,j));
}

int main () {
    ingest();
    unsigned long long solution {};

    for (auto element : Positions) {
        solution = std::max(solution, max_product_at_position(element.second.first, element.second.second));
        if (element.first < 50 ) break;
    }

    std::cout << solution << "\n";

    return 0;
}