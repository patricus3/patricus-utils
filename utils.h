#ifdef __cosmo__
#error "cosmopolitan libc got banned from usage, use clang from homebrew for macOS or msvc for windows"
#endif
#ifdef __linux__
#error "linux isn't supported."
#endif
#define version "3.2"