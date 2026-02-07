#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#define PROMPT "exploit> "
#define SIZE 100

typedef struct  string {
    char    *buf;
    size_t  len;
    size_t  size;
} String;

String  *new_string() {
    String  *str;

    str = malloc(sizeof *str);
    if (! str) {
        return (NULL);
    }
    str->buf = malloc(SIZE * sizeof *(str->buf));
    if (! str->buf) {
        free(str);
        return (NULL);
    }
    str->len = 0;
    str->size = SIZE;
    return (str);
}

void    delete_string(String *str) {
    if (str->buf != NULL) {
        free(str->buf);
    }
    free(str);
}

int    add_buf(String *str, char buff[100]) {
    char    *newbuf;
    size_t  newsize;

    if (str->len + strlen(buff) >= str->size) {
        newsize = str->len + strlen(buff) + 1;
        newbuf = realloc(str->buf, newsize);
        if (! newbuf) {
            return (1);
        }
        str->buf = newbuf;
        str->size = newsize;
    }
    memcpy(str->buf, buff, strlen(buff));
    str->len += strlen(buff);
    *(str->buf + str->len) = 0;
    return(0);
}

int add_char(String *str, char c) {
    char    *newbuf;
    size_t  newsize;

    if (str->len + 1 >= str->size) {
        newsize = 2 * str->len + 1;
        newbuf = realloc(str->buf, newsize);
        if (! newbuf) {
            return (1);
        }
        str->buf = newbuf;
        str->size = newsize;
    }
    *(str->buf + str->len) = c;
    str->len += 1;
    *(str->buf + str->len) = 0;
    return (0);
}

String  *retrieve_line(char *prompt) {
    String  *line;
    int     c;

    if (prompt) {
        dprintf(2, "%s", prompt);
        fflush(stderr);
    }
    line = new_string();
    if (! line) {
        return NULL;
    }
    c = getchar();
    while (c!=EOF && c!='\n') {
        if (add_char(line, (char)c)) {
            free(line);
            return NULL;
        }
        c = getchar();
    }
    return line;
}

void    read_buff() {
    String  *line;

    line = retrieve_line(PROMPT);
    while (line) {
        if (line->len == 0) {
            free(line);
            return ;
        }
        //dprintf(2, "Line(%s)\n", line->buf);
        free(line);
        line = retrieve_line(PROMPT);
    }
}
