-- main.lua
local s = "abcdabcbbbbbbbbbbbbbabc"
local max = 0

for start = 1, #s do
    local count = 0
    local seen = {} -- tabela de caracteres vistos

    for i = start, #s do
        local ch = s:sub(i, i)

        if seen[ch] then
            print("ch: " .. ch)
            print("seen[" .. string.byte(ch) .. "] = " .. tostring(seen[ch] and 1 or 0))
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
