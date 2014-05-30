#include <pwd.h>
#include <sys/types.h>

#ifdef DEBUG
#undef DEBUG
#endif

struct passwd *_getpwuid(uid_t uid);
struct passwd *_getpwnam(char *name);
int _str_cmp(char *str1, char *str2);
int _test_user(char *ss);
