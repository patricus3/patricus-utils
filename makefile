all: build/cat build/cmpsize
# cat target
build/cat: cat.o | build
	clang $(CFLAGS) cat.o -o $@

cat.o: cat.c
	clang $(CFLAGS) -c $< -o $@

# cmpsize target
build/cmpsize: cmpsize.o bytes.o | build
	clang $(CFLAGS) cmpsize.o bytes.o -o $@

cmpsize.o: cmpsize.c
	clang $(CFLAGS) -c $< -o $@

bytes.o: bytes.c
	clang $(CFLAGS) -c $< -o $@

# Ensure build dir exists
build:
	@mkdir -p build 2>/dev/null

# Install target
install: build/cat build/cmpsize
	cp build/cmpsize /usr/local/bin && cp build/cat /usr/local/bin
# Clean target
clean:
	rm -f *.o
	rm -rf build