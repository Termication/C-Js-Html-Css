#include <stdio.h>

struct User {
    char name[25];
    int age;
};

int main(void) {
    struct User user1 = {"Bline", 25};
    struct User user2 = {"Blake", 27};
    struct User user3 = {"Bakwe", 29};
    struct User user4 = {"inett", 21};

    struct User users[] = {user1, user2, user3, user4};
    

    for (int i = 0; i < 4; i++) {
        printf("Name: %s, Age: %d\n", users[i].name, users[i].age);
    }

    return 0;
}
