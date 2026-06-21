#include <bits/stdc++.h>

std::vector<std::string> input;

void ingest () {
    std::ifstream fin ("P22_Input.txt");

    std::string word;
    while (fin >> word)
        input.emplace_back(word);

    // std::ranges::sort(input);
    std::sort(input.begin(), input.end());
}

void solve () {
    unsigned long long solution {0};
    size_t idx {1};

    for (std::string & name: input) {
        size_t value{0};

        for (const char letter: name)
            value += letter - 'A' + 1;

        solution += value*idx;
        idx++;

        if (idx-1 == 938)
            std::cout << "938th Name: " << name << " with its score being " << value*(idx-1) << "\n";
    }

    std::cout << "Solution : " << solution << "\n";
}

int main() {
    ingest();
    solve();

    return 0;
}