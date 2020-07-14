#include <stdio.h>
#include <math.h>


typedef struct {
    int x;
    int y;
} Point;


float get_distance(Point point1, Point point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}


char is_right_rectangle(Point point1, Point point2, Point point3) {
    int is_same_x = point1.x == point2.x || point1.x == point3.x || point2.x == point3.x;
    int is_same_y = point1.y == point2.y || point1.y == point3.y || point2.y == point3.y;
    int on_one_line = (point1.x == point2.x && point1.x == point3.x &&
        point1.y == point2.y && point1.y == point3.y);
    
    if (is_same_x && is_same_y && !on_one_line) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    Point point1, point2, point3;
    printf("Please enter point 1 [x,y]: ");
    scanf("%d,%d", &point1.x, &point1.y);
    printf("Please enter point 2 [x,y]: ");
    scanf("%d,%d", &point2.x, &point2.y);
    point3.x = point1.x;
    point3.y = point2.y;
    
    int horizontal_length = abs(point3.x - point2.x);
    int vertical_length = abs(point3.y - point1.y);
    float rest_length = get_distance(point1, point2);
    float perimeter = horizontal_length + vertical_length + rest_length;

    if (is_right_rectangle(point1, point2, point3)) {
        printf(
            "It's a right-angel rectangle.\n"
            "The third point is (%d,%d).\n"
            "Side's lengths: vertical-%d, horizontal-%d.\n"
            "Perimeter: %f.\n"
            "Area: %f.\n"
            , point3.x, point3.y, vertical_length, horizontal_length, perimeter,
            horizontal_length * vertical_length / 2.0);
    } else {
        printf("It isn't a right-rectangle\n");
    }
    
    return 0;
}
