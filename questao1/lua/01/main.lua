-- main.lua
local s = "abcdabcbbbbbbbbbbbbbabc"
local max = 0

for start = 1, #s do
    local count = 0
    local seen = {} -- tabela de caracteres vistos

    for i = start, #s do
        local ch = s:sub(i, i)

        if seen[ch] then
            break
        end

        seen[ch] = true
        count = count + 1
    end

    if count > max then
        max = count
    end
end

print("Maior substring sem repetição: " .. max .. " caracteres")
