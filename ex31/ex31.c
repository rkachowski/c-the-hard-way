#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;

    while(i < 3000) {
        usleep(3000);
    }

    return 0;
}

