#include <stdio.h>

typedef struct {
    int pc, n;
    char from, to, via;
} Frame;

// frame work for a state machine
#define call(...) ({ *(++top) = (Frame) { .pc = 0, __VA_ARGS__ }; })
#define ret()     ({ top--; })
#define goto(loc) ({ f->pc = (loc) - 1; })

void hanoi(int n, char from, char to, char via) {
    Frame stk[64], *top = stk - 1;
    call(n, from, to , via);
    for(Frame *f; (f = top) >= stk; f->pc++) {
}