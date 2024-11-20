//
// Created by xander on 20-11-24.
//
#include <stdio.h>
#include <fcntl.h>


int main(void) {
    int fp;
    fp = open("/dev/kmodule", O_RDONLY, S_IRUSR);

    if (fp) {
	    printf("Opened file\n");
    } else {
	    printf("Could not open file\n");

    }
    return 0;
}
