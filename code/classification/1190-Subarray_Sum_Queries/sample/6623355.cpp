// Subarray Sum Queries
 
#include <stdio.h>
#include <stdlib.h>
 
int readint() {
   int res = 0;
   char first;
   fread(&first, sizeof(char), 1, stdin);
   while (first != '-' && (first < '0' || first > '9')) {
      fread(&first, sizeof(char), 1, stdin);
   }
   int neg = (first == '-');
   if (!neg) {
      res = first - '0';
   }
   char next;
   if (fread(&next, sizeof(char), 1, stdin)) {
      while (next >= '0' && next <= '9') {
         res = 10*res + (next - '0');
         if (!fread(&next, sizeof(char), 1, stdin)) break;
      }
   }
 
   return res * (neg ? -1 : 1);
}
 
typedef struct Node Node;
 
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
 
void printspace() {
   char c = ' ';
   fwrite(&c, 1, sizeof(char), stdout);
}
void printline() {
   char c = '\n';
   fwrite(&c, 1, sizeof(char), stdout);
}
void printint(int x) {
   char res[11];
   if (x < 0) {
      res[0] = '-';
      fwrite(res, 1, sizeof(char), stdout);
      x *= -1;
   }
   if (x == 0) {
      res[0] = '0';
      fwrite(res, 1, sizeof(char), stdout);
      return;
   }
   int p = 10;
   while (x) {
      res[p--] = (x % 10) + '0';
      x /= 10;
   }
   fwrite(res+p+1, 10-p, sizeof(char), stdout);
}
 
 
void printlong(long long int x) {
   char res[21];
   if (x < 0) {
      res[0] = '-';
      fwrite(res, 1, sizeof(char), stdout);
      x *= -1;
   }
   if (x == 0) {
      res[0] = '0';
      fwrite(res, 1, sizeof(char), stdout);
      return;
   }
   int p = 20;
   while (x) {
      res[p--] = (x % 10) + '0';
      x /= 10;
   }
   fwrite(res+p+1, 20-p, sizeof(char), stdout);
}
 
typedef struct Node Node;
typedef long long int lli;
 
struct Node {
   int lo, hi;
   lli prefix;
   lli suffix;
   lli ans;
   lli tot;
};
 
Node * arr;
int * orig;
void init(int ind, int lo, int hi) {
   arr[ind].lo = lo;
   arr[ind].hi = hi;
   if (lo != hi) {
      int mid = (lo + hi) >> 1;
      int rind = ind*2+2;
      int lind = rind-1;
      init(lind, lo, mid);
      init(rind, mid+1, hi);
      arr[ind].tot = arr[rind].tot + arr[lind].tot;
      
      arr[ind].suffix = MAX(arr[rind].tot + arr[lind].suffix, arr[rind].suffix);
      arr[ind].prefix = MAX(arr[lind].tot + arr[rind].prefix, arr[lind].prefix);
      
      arr[ind].ans = MAX(arr[rind].ans, arr[lind].ans);
      lli tmp = arr[lind].suffix + arr[rind].prefix;
      arr[ind].ans = MAX(arr[ind].ans, tmp);
   } else {
      arr[ind].tot = arr[ind].suffix = arr[ind].prefix = arr[ind].ans = orig[lo];
      if (arr[ind].prefix < 0) {
         arr[ind].suffix = 0;
         arr[ind].prefix = 0;
         arr[ind].ans = 0;
      }
   }
}
void update(int ind, int index, int val) {
   if (index < arr[ind].lo || arr[ind].hi < index) return;
   if (arr[ind].lo == arr[ind].hi) {
      arr[ind].tot = arr[ind].suffix = arr[ind].prefix = arr[ind].ans = val;
      if (arr[ind].prefix < 0) {
         arr[ind].suffix = 0;
         arr[ind].prefix = 0;
         arr[ind].ans = 0;
      }
      return;
   }
   int rind = ind*2+2;
   int lind = rind-1;
   update(rind, index, val);
   update(lind, index, val);
   arr[ind].tot = arr[rind].tot + arr[lind].tot;
   
   arr[ind].suffix = MAX(arr[rind].tot + arr[lind].suffix, arr[rind].suffix);
   arr[ind].prefix = MAX(arr[lind].tot + arr[rind].prefix, arr[lind].prefix);
   
   arr[ind].ans = MAX(arr[rind].ans, arr[lind].ans);
   lli tmp = arr[lind].suffix + arr[rind].prefix;
   arr[ind].ans = MAX(arr[ind].ans, tmp);
}
 
 
int main() {
   int n = readint(), m = readint();
   orig = (int *) malloc(sizeof(int) * n);
   arr = (Node *) malloc(sizeof(Node) * (n * 4 + 1));
   for (int i = 0; i < n; i++)
      orig[i] = readint();
   init(0, 0, n-1);
 
   while (m--) {
      int k = readint()-1, x = readint();
      update(0, k, x);
      printlong(arr[0].ans);
      printline();
   }
 
   return 0;
}
