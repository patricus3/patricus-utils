CFLAGS =
all: build/cat build/cmpsize

# Beta build target (adds -DBETA)
beta: CFLAGS += -DBETA
beta: all

# cat target
build/cat: cat.o | build
	cosmocc $(CFLAGS) cat.o -o $@

cat.o: cat.c
	cosmocc $(CFLAGS) -c $< -o $@

# cmpsize target
build/cmpsize: cmpsize.o bytes.o | build
	cosmocc $(CFLAGS) cmpsize.o bytes.o -o $@

cmpsize.o: cmpsize.c
	cosmocc $(CFLAGS) -c $< -o $@

bytes.o: bytes.c
	cosmocc $(CFLAGS) -c $< -o $@

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
