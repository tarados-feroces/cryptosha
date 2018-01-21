compiler    := g++
std_version := -std=c++14 -Wall


convertor_tests: _convertor.o _string_funcs.o _operations.o _convertor_tests.o
	$(compiler) $(std_version) _convertor.o _operations.o _string_funcs.o convertor_tests.o -o convertor.test.out
	./convertor.test.out


string_funcs_tests: _string_funcs.o
	$(compiler) $(std_version) _string_funcs.o string_funcs.cpp -o string_funcs.test.out
	./string_funcs.test.out


vector_funcs_tests: 
	$(compiler) $(std_version) vector_funcs.cpp -o vector_funcs.test.out
	./vector_funcs.test.out


_convertor_tests.o:
		$(compiler) $(std_version) -c convertor_test.cpp -o convertor_tests.o


_convertor.o:
		$(compiler) $(std_version) -c ../convertor/convertor.cpp -o _convertor.o


_string_funcs.o:
		$(compiler) $(std_version) -c ../funcs/string_funcs.cpp -o _string_funcs.o

_operations.o:
		$(compiler) $(std_version) -c ../convertor/operations_handler.cpp -o _operations.o



clear:
	rm *.o *.test.out *.out
