#include <stdio.h>
#include <stdlib.h>


int main() {
    unsigned long password;

    char rndbuf[8];
    char buf[16];
    unsigned long rnd;
    unsigned short is_admin=0;

    FILE* fp = fopen("/dev/urandom", "rb");
    fread(rndbuf, 1, 8, fp);
    fclose(fp);

    printf("Insert password:\n");
    fgets((char*)buf, 40, stdin);

    password = strtoul((char*)buf, NULL, 10);
    rnd = *((unsigned long*)rndbuf);

    if(password == rnd){
        is_admin = 1;
    }else{
        printf("Invalid password!\n");
    }
    if(is_admin == 1){
        printf("Congratulations you are now an admin!\n");
    }

}

