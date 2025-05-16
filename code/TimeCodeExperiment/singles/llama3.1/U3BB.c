
             #include <stdio.h>
             #include <stdlib.h>

             // Define the struct to represent a point in a 2D plane
             struct point {
                int a;
                int b;
             };

             // Function to add two points
             int add_points(struct point *p1, struct point *p2) {
                return (p1->a + p2->a) + (p1->b + p2->b);
             }

             // Function to print the coordinates of a point
             void print_point(struct point *p) {
                printf("(%d, %d)\n", p->a, p->b);
             }

             // Function to create a new point
             struct point* create_point(int a, int b) {
                struct point *p = (struct point*) malloc(sizeof(struct point));
                p->a = a;
                p->b = b;
                return p;
             }

             // Function to free the memory allocated for a point
             void free_point(struct point *p) {
                free(p);
             }

             int main() {
                // Create two points
                struct point *p1 = create_point(1, 2);
                struct point *p2 = create_point(3, 4);

                // Print the coordinates of the points
                printf("Point 1: ");
                print_point(p1);
                printf("Point 2: ");
                print_point(p2);

                // Add the points
                int sum = add_points(p1, p2);

                // Print the sum
                printf("Sum of coordinates: %d\n", sum);

                // Free the memory allocated for the points
                free_point(p1);
                free_point(p2);

                return 0;
             }
            