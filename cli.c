#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open /dev/urandom");
        return 1;
    }

    unsigned int random_value;
    if (read(fd, &random_value, sizeof(random_value)) == -1) {
        perror("Failed to read");
        close(fd);
        return 1;
    }

    printf("Random value: %u\n", random_value);
    close(fd);
    return 0;
}

