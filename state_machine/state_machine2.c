#include <stdarg.h>
#include <stdio.h>

enum e_state { LETTER, FLAG, CONV, ERROR, END };

typedef struct {
    enum e_state state;
    int (*process)(char, va_list, FILE *);
} t_state_machine;

int process_letter(char ch, va_list args, FILE *stream);
int process_flag(char ch, va_list args, FILE *stream);
int process_conv(char ch, va_list args, FILE *stream);
int process_error(char ch, va_list args, FILE *stream);
int process_end(char ch, va_list args, FILE *stream);

t_state_machine state_machine[] = {
    { LETTER, process_letter },
    { FLAG, process_flag },
    { CONV, process_conv },
    { ERROR, process_error },
    { END, process_end },
};

int myprintf(const char *format, ...)
{
    int total_written = 0;
    va_list args;
    FILE *stream = stdout;
    t_state_machine machine = { LETTER, process_letter };

    va_start(args, format);

    for (const char *ptr = format; *ptr != '\0'; ptr++) {
        int written = machine.process(*ptr, args, stream);
        if (written >= 0) {
            total_written += written;
        } else {
            return -1;
        }
        machine = state_machine[machine.state];
    }

    va_end(args);

    return total_written;
}

int process_letter(char ch, va_list args, FILE *stream)
{
    int written = 0;
    if (ch == '%') {
        return 0;
    } else {
        fputc(ch, stream);
        written++;
        return written;
    }
}

int process_flag(char ch, va_list args, FILE *stream)
{
    if (ch == 'c') {
        char c = va_arg(args, int);
        fputc(c, stream);
        return 1;
    } else if (ch == 's') {
        char *s = va_arg(args, char *);
        fputs(s, stream);
        return strlen(s);
    } else {
        return -1;
    }
}

int process_conv(char ch, va_list args, FILE *stream)
{
    if (ch == 'd' || ch == 'i') {
        int value = va_arg(args, int);
        return fprintf(stream, "%d", value);
    } else if (ch == 'o') {
        unsigned int value = va_arg(args, unsigned int);
        return fprintf(stream, "%o", value);
    } else if (ch

