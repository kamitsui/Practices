#include <stdarg.h>
#include <stdio.h>

enum e_state { LETTER, FLAG, CONV, ERROR, END };

typedef struct s_state_machine {
    enum e_state current_state;
    int (*process_func)(struct s_state_machine *, const char *, va_list, FILE *);
    int width;
    int precision;
    int left_just;
    int space;
    int plus;
    int hash;
    int zero;
    int count;
} t_state_machine;

int letter(t_state_machine *state, const char *str, va_list ap, FILE *stream) {
    fputc(*str, stream);
    state->count++;
    state->current_state = LETTER;
    return 0;
}

int flag(t_state_machine *state, const char *str, va_list ap, FILE *stream) {
    switch (*str) {
        case '-':
            state->left_just = 1;
            break;
        case ' ':
            state->space = 1;
            break;
        case '+':
            state->plus = 1;
            break;
        case '#':
            state->hash = 1;
            break;
        case '0':
            state->zero = 1;
            break;
        case '.':
            state->current_state = CONV;
            state->process_func = &conv;
            state->precision = 0;
            break;
        default:
            if (*str >= '0' && *str <= '9') {
                if (state->width == 0) {
                    state->width = *str - '0';
                } else {
                    state->width = (state->width * 10) + (*str - '0');
                }
            } else {
                state->current_state = CONV;
                state->process_func = &conv;
                return state->process_func(state, str, ap, stream);
            }
            break;
   

