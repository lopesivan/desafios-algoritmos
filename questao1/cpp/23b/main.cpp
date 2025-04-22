#include <iostream>
#include <string>
#include <unordered_set>
#include <print>
#include <ranges>

int main() {
    std::string s = "abcdabcbb";
    int max = 0;

    for (auto start_it = s.begin(); start_it != s.end(); ++start_it) {
        std::unordered_set<char> seen;
        int count = 0;

        std::print("start: {}\n", *start_it);

        for (auto end_it = start_it; end_it != s.end(); ++end_it) {
            char ch = *end_it;
            std::print("end: {}\n", ch);
            std::print("seen[{}] = {}\n", static_cast<int>(ch), seen.contains(ch) ? 1 : 0);

            if (seen.contains(ch))
                break;

            seen.insert(ch);
            count++;
        }

        max = std::max(max, count);
    }

    std::print("Maior substring sem repetição: {} caracteres\n", max);
}

