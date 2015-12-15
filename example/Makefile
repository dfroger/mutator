default: main main_foo_refactored

INCLUDES="-I../mutator"

%: %.cxx
	$(CXX) -o $@ $(INCLUDES) $<

test: test_main test_main_foo_refactored

test_main_foo_refactored: main_foo_refactored
	./main_foo_refactored > main_foo_refactored_output.txt
	diff main_foo_refactored_output.txt expected_output.txt

test_main: main 
	./main > main_output.txt
	diff main_output.txt expected_output.txt

clean:
	rm -f main main_foo_refactored main_output.txt main_foo_refactored_output.txt
