compiler := g++-7
standart := -std=c++17
flags    := $(standart) -Wall

build := $(compiler) $(flags)


CrylangDir := crylang
InterpreterDir := $(CrylangDir)/interpreter
LanguageDir := $(CrylangDir)/language



all: language_test

clear:
	rm -rf *.bin *.out *.test.bin


language_test: _operators

#-----------------------language_test-------------------------------------------
_operators:
	$(build) $(LanguageDir)/operators.cpp -o operators.test.bin
	./operators.test.bin
#----------------------[language_test]------------------------------------------
