/*This C program is written to explain about the bufferoverflow vulnerability 
 this explain about how the bufferoverflow causes from the user input
 and also about the methods used to defend*/

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char username[20];

    // Safer input using fgets
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    
    // Preventing buffer overflow using strncpy and proper bounds checking
    char safer_buffer[10];

    if (strlen(username) >= sizeof(safer_buffer)) {
        printf("Input too long. Truncating...\n");
        strncpy(safer_buffer, username, sizeof(safer_buffer) - 1);
        safer_buffer[sizeof(safer_buffer) - 1] = '\0'; // Ensure null-termination
    } else {
        strcpy(safer_buffer, username);
    
    }
    
    // Now, the buffer overflow is prevented.
    printf("Safer buffer content: %s\n", safer_buffer);

    return 0;
    
} 

/* compiler flags to help detect and prevent buffer overflow vulnerabilities.
   For example,
             -fstack-protector and -Wformat-security 
             flags can provide some protection by adding runtime checks.

    Buffer overflow vulnerabilities are not solely dependent on the compiler but also on the operating system's security features. 
    *Address Space Layout Randomization (ASLR)* and *Data Execution Prevention (DEP)*
    are operating system features that can make it more challenging to exploit buffer overflows.
*/