#include <iostream>
#include <string>
#include <unordered_set>
#include <print> // C++23

int main() {
    std::string s = "abcdabcbb";
    int max = 0;

    for (size_t start = 0; start < s.length(); ++start) {
        std::unordered_set<char> seen;
        int count = 0;

        std::print("start: {}\n", s[start]);

        for (size_t end = start; end < s.length(); ++end) {
            char ch = s[end];
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

