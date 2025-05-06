#include <stdio.h>
#include <string.h>
#include <unistd.h>

void with_lib() {
    char s[64];
    char* p;
    int i;

    while(1) {
        p = fgets(s, 64, stdin);
        if (p == NULL)
            break;
        for(i = 0; s[i]; i++)
            s[i] = '*';
        fputs(s, stdout);
    }
}

void with_sys() {
    char s[64];
    int i, k;

    while(1) {
        k = read(0, s, 64);
        if(k <= 0)
            break;
        for(i=0; i < k - 1; i++)
            s[i] = '*';
        write(1, s, k);
    }
}

int main(int argc, char** argv){
    if(argc > 1 && strcmp("lib", argv[1]) == 0)
        with_lib();
    else if(argc > 1 && strcmp("sys", argv[1]) == 0)
        with_sys();
    else
        write(2, "error", strlen("error"));
    return 0;
}
