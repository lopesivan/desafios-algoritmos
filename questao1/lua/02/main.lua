-- main.lua
local s = "abcdabcbbbbbbbbbbeeehhhhheeeeeggggggabc"

local freq = {}

for i = 1, #s do
    local ch = s:sub(i, i)
    freq[ch] = (freq[ch] or 0) + 1
end

for letra, contagem in pairs(freq) do
    print(letra, contagem)
end
