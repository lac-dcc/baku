
int main() {
    int* p = NULL;
    int* q = &p;
    p = (int*)malloc(sizeof(int));
    *p = 10;
    printf("%d\n", *p);
    free(p);
    return 0;
}
