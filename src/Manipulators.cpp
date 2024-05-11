#include <StreamConstants.h>

Print& flush(Print& print)
{
    print.flush();
    return print;
}

Print& endl(Print& print)
{
    print.write('\n');
    return flush(print);
}

Print& ends(Print& print)
{
    print.write('\0');
    return print;
}
