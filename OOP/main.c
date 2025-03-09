#include <stdio.h>

#define OPTIONS 4

/*linked list of strings*/
typedef struct Node {
	char* data;
	struct Node *next;
}Node;

int prime(int n) {
	if (n % 2 == 0 || n < 2 )
}

void menu() {
	options = {
		"Prime numbers less than N",
		"",
		"",
		"",
	};
	for (int i = 0; i < OPTIONS; i++) {
		printf("%d. %s\n", i + 1, options[i]);
	}
}

int main() {
	printf("Hello, World!\n");
	return 0;
}