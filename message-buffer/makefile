kompilator = g++
standard = -std=c++20
optRelease = -O3
optDebug =
errors = -pedantic-errors
release =
debug = -g
rownoleglosc =
release_folder = _release
debug_folder = _debug
OBJECTS = klasy.o main.o

.PHONY: release debug clean
release: $(release_folder)/main
	./$(release_folder)/main

debug: $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main

$(release_folder)/main: $(addprefix $(release_folder)/,$(OBJECTS))
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main: $(addprefix $(debug_folder)/,$(OBJECTS))
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^

$(release_folder)/%.o: %.cpp
	mkdir -p $(release_folder)
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $<

$(debug_folder)/%.o: %.cpp
	mkdir -p $(debug_folder)
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $<

clean:
	rm -rf $(release_folder) $(debug_folder)
