#include <stdio.h>

char* format_bytes(size_t bytes) {
    static char result[50];  // Static buffer to hold the result string

    if (bytes < 1024) {
        snprintf(result, sizeof(result), "%zu B", bytes);
    } else if (bytes < 1024 * 1024) {
        snprintf(result, sizeof(result), "%.2f KB", bytes / 1024.0);
    } else if (bytes < 1024 * 1024 * 1024) {
        snprintf(result, sizeof(result), "%.2f MB", bytes / (1024.0 * 1024.0));
    } else if (bytes < 1024LL * 1024 * 1024 * 1024) {
        snprintf(result, sizeof(result), "%.2f GB", bytes / (1024.0 * 1024.0 * 1024.0));
    } else {
        snprintf(result, sizeof(result), "%.2f TB", bytes / (1024.0 * 1024.0 * 1024.0 * 1024.0));
    }

    return result;
}
