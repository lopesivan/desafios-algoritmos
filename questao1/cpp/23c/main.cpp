#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>  // obrigatório para std::ranges::for_each
#include <ranges>
#include <print>

int main() {
    std::string s = "abcdabcbb";
    int max = 0;

    // Gera todos os deslocamentos da string: s, s[1:], s[2:], ...
    std::ranges::for_each(std::views::iota(0u, static_cast<unsigned>(s.size())),
    [&](auto start) {
        std::unordered_set<char> seen;
        int count = 0;

        std::print("start: {}\n", s[start]);

        for (char ch : std::views::drop(s, start)) {
            std::print("end: {}\n", ch);
            std::print("seen[{}] = {}\n", static_cast<int>(ch), seen.contains(ch) ? 1 : 0);

            if (seen.contains(ch))
                break;

            seen.insert(ch);
            ++count;
        }

        max = std::max(max, count);
    });

    std::print("Maior substring sem repetição: {} caracteres\n", max);
}
