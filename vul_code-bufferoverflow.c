#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[10];
    strcpy(buffer, input); // This line is vulnerable to buffer overflow
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter input: ");
    scanf("%s", input);
    vulnerable_function(input);
    return 0;
}


