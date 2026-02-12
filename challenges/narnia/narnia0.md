# [Narnia0->1](https://overthewire.org/wargames/narnia/narnia1.html)

???+ info

    There is no information for this level, intentionally

## Commands useful to solve the level

- [gdb](https://sourceware.org/gdb/current/onlinedocs/gdb.html/)
- [gcc](https://www.man7.org/linux/man-pages/man1/gcc.1.html)
- [strings](https://www.man7.org/linux/man-pages/man1/strings.1.html)

## Useful C functions to solve the level

- [fork](https://www.man7.org/linux/man-pages/man2/fork.2.html)
- [execve](https://man7.org/linux/man-pages/man2/execve.2.html)
- [write](https://man7.org/linux/man-pages/man2/write.2.html)
- [read](https://man7.org/linux/man-pages/man2/read.2.html)
- [memset](https://man7.org/linux/man-pages/man3/memset.3.html)

## Where to Start

For this level (and all the others to come), we'll be given:

1. A vulnerable binary to exploit
2. The binary's source code

Our goal will be to take advantage of the binary that is provided to us
to retrieve the password for the next level

??? note "Part 1: Binary Analysis"

    
