#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    pid_t pid = getpid(); // Get process ID
    uid_t uid = getuid(); // Get user ID

     
    int fd = open("log.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0){
    write(STDERR_FILENO, "Failed to open file.\n", 22);
    return 1;
    }

    // Open (or create) a file for writing
    write(STDOUT_FILENO, "Enter a message : \n", 20);
    char msg[63];
    size_t raw_len = (read(STDIN_FILENO, msg, sizeof(msg))-1);

    msg [raw_len] = '\0'; 
    char msg_buffer [128];
    int msg_len = snprintf(msg_buffer, sizeof(msg_buffer), "User input: %s \n", msg);
    write(fd, msg_buffer, msg_len);
    write(STDOUT_FILENO, "Your input was saved. \n", 22);

    
    // Prepare output
    char buffer[128];
    int len = snprintf(buffer, sizeof(buffer), "PID: %d \t UID: %d \n", pid, uid);
    write(fd, buffer, len); // Write to file
    write(STDOUT_FILENO, "Log written to file.\n", 22); // Confirmation

    close(fd);
    return 0;
}
