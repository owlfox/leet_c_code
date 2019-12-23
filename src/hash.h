#ifndef _HASH_H
#define _HASH_H
#include "uthash.h"
#include <stdlib.h>
struct my_struct {
    int id;                    /* key */
    char name[10];
    UT_hash_handle hh;         /* makes this structure hashable */
};
struct my_struct *users = NULL;    /* important! initialize to NULL */

void add_user(int user_id, char *name) {
    struct my_struct *s;

    s = malloc(sizeof(struct my_struct));
    s->id = user_id;
    strcpy(s->name, name);
    HASH_ADD_INT( users, id, s );  /* id: name of key field */
}
struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );  /* s: output pointer */
    return s;
}
#endif // _HASH_H
