#include "minunit.h"
#include <lcthw/ringbuffer.h>
#include <lcthw/bstrlib.h>

const int TEST_LENGTH = 1000;
static RingBuffer *buffer = NULL;

char *test_create()
{
    buffer = RingBuffer_create(TEST_LENGTH); 
    mu_assert(buffer != NULL, "Failed to create buffer.");

    return NULL;
}

char *test_read_write()
{
    mu_assert(RingBuffer_empty(buffer), "Should be empty when nothing in it.");

    bstring string = bfromcstr("test string1");
    RingBuffer_puts(buffer,  string);

    mu_assert(!RingBuffer_empty(buffer), "Should have stored string.");
    bstring result = RingBuffer_gets(buffer, sizeof(bdata(string)));

    mu_assert(bstrcmp(string, result), "Strings should be the same.");

    return NULL;
}

char *test_destroy()
{
    RingBuffer_destroy(buffer);
    return NULL;
}


char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_read_write);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
