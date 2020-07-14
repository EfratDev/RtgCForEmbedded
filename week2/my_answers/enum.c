#include <stdio.h>

enum days {padding, sunday, monday, tuesday, 
    wednesday, thursday, friday, saturday};

int main() {
    enum days day;
    printf("Please enter a day number: ");
    scanf("%d", &day);
    if (day == sunday) {
        printf("sunday.\n");
    } else if (day == monday) {
        printf("monday.\n");
    } else if (day == tuesday) {
        printf("tuesday.\n");
    } else if (day == wednesday) {
        printf("wednesday.\n");
    } else if (day == thursday) {
        printf("thurseday.\n");
    } else if (day == friday) {
        printf("friday.\n");
    } else if (day == saturday) {
        printf("saturday.\n");
    } else {
        printf("No such day.\n");
    }
    return 0;
}