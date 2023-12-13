#include <iostream>
#include <cstring>

int main(){
char s1[9] = "heyyy";

char s2[9] = "heyy12";

if (!(strncmp(s1,s2,5)))

   cout << "Well done!";

}
