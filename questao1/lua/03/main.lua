local s = "asasa shebangabc as aas as as aabc abc abc def abc"
local q = "abc"

local count = 0
local start = 1

while true do
    local i = string.find(s, q, start)
    if not i then -- not nil == true
        break
    end

    count = count + 1
    start = i + 1 -- continua após a ocorrência atual
end

print("Total de ocorrências:", count)
