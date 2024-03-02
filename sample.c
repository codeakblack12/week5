// #include <stdio.h>
// #include <stdlib.h>

// #define BUFSIZE 256

// // This program prints the size of a specified file in bytes
// int main(int argc, char** argv) {
// char cmd[BUFSIZE] = "wc -c < ";
// strcat(cmd, argv[1]);
// system(cmd);
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char cmd[BUFSIZE];
    snprintf(cmd, sizeof(cmd), "wc -c < %s", argv[1]);
    FILE* pipe = popen(cmd, "r");
    if (pipe == NULL) {
        perror("popen");
        return 1;
    }

    char result[BUFSIZE];
    while (fgets(result, sizeof(result), pipe) != NULL) {
        printf("File size: %s", result);
    }

    pclose(pipe);
    return 0;
}
