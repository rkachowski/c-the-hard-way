#include "dbg.h"
#include "ex22.h"

const char *MY_NAME = "Donald Hutchison";

void scope_demo(int count)
{

    log_info("count is %d", count);

    if(count > 10){
        int count = 100;

        log_info("count in this scope is %d", count);
    }

    log_info("count after exit is %d", count);

    count = 3000;

    log_info("count after assignment is %d", count);
}

int main(int argc, char *argv[])
{
    log_info("my name %s, age %d", MY_NAME, get_age());

    set_age(100);

    log_info("my age is now %d", get_age());
    log_info("THE_SIZE is %d", THE_SIZE);
    print_size();

    THE_SIZE = 9;

    log_info("THE_SIZE is now %d ", THE_SIZE);
    print_size();

    log_info("ratio at first : %f", update_ratio(2.0));
    log_info("ratio now : %f", update_ratio(10.0));
    log_info("ratio finally : %f", update_ratio(300.0));

    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("Count after calling scope_demo : %d", count);

    return 0;
}
