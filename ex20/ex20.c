#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
    debug("a thing without the newline at end.");
    debug("passing in arguments like printf %s", "word");
}

void test_log_err()
{
    log_err("I believe everything is broken");
    log_err("there are %d problems in %s", 0, "space");
}

void test_log_warn()
{
    log_warn("you can safely ignore this");
    log_warn("maybe consider looking at %s","/etc/passwd");
}

void test_log_info()
{
    log_info("I did something boring");
    log_info("it happened %f times this past hour", 32.45f);
}

int test_check(char *file_name)
{
    FILE *input = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block);

    input = fopen(file_name, "r");
    check(input, "Failed to open %s.", file_name);

    free(block);
    fclose(input);
    return 0;

error:
    if(block) free(block);
    if(input) fclose(input);
    return -1;

}

int test_sentinel(int code)
{
    char *temp = malloc(100);
    check_mem(temp);

    switch(code){
        case 1:
            log_info("It worked");
        default:
            sentinel("I shouldn't run");
    }

    free(temp);
    return 1;

error:
    if(temp) free(temp);
    return -1;
}

int test_check_mem()
{
    char *test = NULL;
    check_mem(test);

    free(test);
    return 1;

error:
    return -1;
}


int test_check_debug()
{
    int i = 0;
    check_debug( i != 0 , "Well what do you know, it's zero.");

    return 0;

error:
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc == 2, "Need an argument.");

    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    check(test_check("ex20.c") == 0, "failed with ex20.c");
    check(test_check(argv[1]) == -1, "failed with argv");
    check(test_sentinel(1) == 0, "failed with test_sentinel");
    check(test_sentinel(100) == -1, "failed with test_sentinel");
    check(test_check_mem() == -1, "failed with test_check_mem");
    check(test_check_debug() == -1, "failed with test_check_debug");

    return 0;

error:
    return 1;
}
