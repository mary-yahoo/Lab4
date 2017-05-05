#include <iostream>
int zad1(int *p){
    int n=0;
    for (int i = 0; i < 100; i++) {
        *(p+i)=rand()%10001;
        printf("a[%d]=%d\n", i, p[i]);
        if (p[i]%2==0)
            n++;
    }
    return n;
}
void zad2(int *k, int *p, int n){
    int l=0;
    for (int i = 0; i < 100; i++) {
        if(p[i]%2==0){
            *(k+l)=p[i];
            l++;
        }
    }
    printf("\n\n");
    for (int q = 0; q < n; q++)
        printf("b[%d]=%d\n", q, k[q]);
    free(p);
}
void zad3(int *k, int n){
    printf("\n\n");
    int p;
    for (int i = 0; i < n; i++) {
        p = k[i]|(-95);
        if (p==(-7)){
            printf("c[%d]=%d true\n", i, k[i]);
        }else {
            printf("c[%d]=%d false\n", i, k[i]);
        }

    }
    printf("\n\n");
}
void zad45(int *k, int n, int **t, int *r){
    int m;
    int w;
    for (int i = 0; i < n; i++) {
        printf("d[%d]=", i);
        m=k[i];
        w=1;
        while (m>9){
            m=m/10;
            w=w+1;
        }
        int B[w];
        m=k[i];
        for (int l = 0; l < w; l++) {
            B[l]=m%10;
            m=m/10;
        }
        r[i]=w;
        t[i]= (int *)calloc(4, w);
        for (int j = 0; j < w; j++) {
            t[i][j]=B[w-j-1];
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void zad6(int **t, int n, int *r){
    int y;
    for (int i = 0; i < n; i++) {
        printf("\ne[%d]=", i);
        for (int j = 0; j < r[i]; j++) {
            y=t[i][j];
            if (y<1){
                t[i][j]=9;
            }else{
                t[i][j]=y-1;
            }
            printf("%d ", t[i][j]);
        }
    }
    printf("\n\n");
}
void zad7(int *k, int **t, int n, int *r){
    int y;
    int d;
    int m;
    for (int i = 0; i < n; i++) {
        m=0;
        d=1;
        for (int j = r[i]-1; j > -1; j--) {
            y=t[i][j];
            m=m+y*d;
            d=d*10;
        }
        k[i]=m;
        printf("f[%d]=%d\n", i, k[i]);
    }
    printf("\n\n");
}
void zad8(int *k, int *r, int n, int **t){
    free(k);
    free(r);
    for (int i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);
}
int main() {
    int *p=(int *)calloc(4,100);
    int n=zad1(p);
    int *k=(int *)calloc(4,n);
    zad2(k, p, n);
    zad3(k, n);
    int *r=(int *)calloc(7,n);
    int **t=(int **)calloc(9,n);
    zad45(k, n, t, r);
    zad6(t, n, r);
    zad7(k, t, n, r);
    zad8(k, r, n, t);
    return 0;
}