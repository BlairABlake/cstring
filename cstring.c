#include "cstring.h"

#include <stdio.h>

string_t string(char* s) {
    size_t l = strlen(s);
    char* t = malloc(l);
    strcpy(t, s);
    return (string_t){l, (u_char*)t};
}

void string_init(string_t* s) {
    s->len = 0;
    s->data = NULL;
}

void string_cpy(string_t* destination, string_t* source) {
    if(destination->len < source->len) {
        string_free(destination);
        destination->len = source->len;
        destination->data = malloc(source->len);
    }

    strcpy((char*)destination->data, (char*)source->data);
}

void string_mov(string_t* destination, string_t* source) {
    string_cpy(destination, source);
    string_free(source);
}

void string_free(string_t* s) {
    free(s->data);
    s->len = 0;
    s->data = NULL;
}

void string_cat(string_t* s1, string_t* s2) {
    char* t = malloc(s1->len + s2->len);
    strcpy(t, (char*)s1->data);
    strcat(t, (char*)s2->data);
    string_free(s1);
    *s1 = string(t);
    free(t);
}

int string_cmp(string_t* s1, string_t* s2) {
    return strcmp((char*)s1->data, (char*)s2->data);
}