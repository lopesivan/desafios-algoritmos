# Nome do executável a ser gerado
TARGET = main

# Compiler
CXX = g++-14

# Flags para o compilador
CXXFLAGS = -std=c++23 -g -O0 -Wall -Werror -Wextra -Wshadow -Wpedantic -Wno-parentheses

# Arquivos fonte
SOURCES = main.cpp

# Arquivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@
#	$(CXX) $(OBJECTS) -o $@ -lfmt

# Compilação
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos intermediários e do executável
clean:
	rm -f $(OBJECTS) $(TARGET)

# roda o aplicativo
run: $(TARGET)
	./$(TARGET)

# Depuração com gdb
debug: $(TARGET)
	gdb ./$(TARGET)

