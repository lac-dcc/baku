#include <cstdio>
namespace FastIO {
  int min(int a, int b) {return a<b?a:b;}
  const int SIZE = 1<<15;
  struct Reader {
    FILE *stream;
    char buffer[SIZE];
    char acc='.';
    int seek=0, byte_read=0;
    Reader(FILE *input):stream(input){}
    void refresh() {
      byte_read=fread(buffer,1,SIZE,stream);
      seek=0;
    }
    char read() {
      if (seek==min(byte_read,SIZE))
        refresh();
      if (byte_read==0) return '\n';
      return buffer[seek++];
    }
 
    inline Reader& operator >>              (short int &x) {
      char sign=0; x=0;
      while (acc<'0' || acc>'9') { sign=acc; acc=read(); };
      for (;acc>='0'&&acc<='9'; acc=read()) x = x * 10 + (acc - '0');  
      x=(sign=='-'?-x:x);
      return *this;
    }
    inline Reader& operator >>                    (int &x) {
      char sign=0; x=0;
      while (acc<'0' || acc>'9') { sign=acc; acc=read(); };
      for (;acc>='0'&&acc<='9'; acc=read()) x = x * 10 + (acc - '0');  
      x=(sign=='-'?-x:x);
      return *this;
    }
    inline Reader& operator >>          (long long int &x) {
      char sign=0; x=0;
      while (acc<'0' || acc>'9') { sign=acc; acc=read(); };
      for (;acc>='0'&&acc<='9'; acc=read()) x = x * 10 + (acc - '0');  
      x=(sign=='-'?-x:x);
      return *this;
    }
    inline Reader& operator >>     (unsigned short int &x) {
      x=0;
      while (acc<'0' || acc>'9') acc=read();
      for (;acc>='0'&&acc<='9'; acc=read()) x = x * 10 + (acc - '0');
      return *this;
    }
    inline Reader& operator >>           (unsigned int &x) {
      x=0;
      while (acc<'0' || acc>'9') acc=read();
      for (;acc>='0'&&acc<='9'; acc=read()) x = x * 10 + (acc - '0');
      return *this;
    }
    inline Reader& operator >> (unsigned long long int &x) {
      x=0;
      while (acc<'0' || acc>'9') acc=read();
      for (;acc>='0'&&acc<='9'; acc=read()) x = x * 10 + (acc - '0');
      return *this;
    }
    inline Reader& operator >>                   (char *s) {
      for (; acc==' '||acc=='\n'||acc=='\0'; acc=read());
      for (; acc!='\n'&&acc!=' '&&acc!='\0'; acc=read())
        *(s++)=acc;
      *s='\0';
      return *this;
    }
    inline Reader& operator >>                   (char &c) {
      c=read();
      return *this;
    }
  }fin(stdin);
 
 
  struct Writer {
    FILE *stream;
    char buffer[SIZE];
    char outnum[20];
    int seek=0;
    Writer(FILE *input):stream(input){}
    void flush() {
      fwrite(buffer,1,seek,stream);
      seek=0;
    }
    ~Writer() {flush();}
    void write(char c) {
      if (seek==SIZE)
        flush();
      buffer[seek++]=c;
    }
   
    inline Writer& operator <<              (const short int &x) {
      int i=10; short int temp=x;
      if (temp == 0) write('0');
      if (temp < 0) write('-'), temp=-temp;
      while (temp) outnum[--i]=temp%10+'0', temp/=10;
      while (i<10) write(outnum[i++]);
      return *this;
    }
    inline Writer& operator <<                    (const int &x) {
      int i=10; int temp=x;
      if (temp == 0) write('0');
      if (temp < 0) write('-'), temp=-temp;
      while (temp) outnum[--i]=temp%10+'0', temp/=10;
      while (i<10) write(outnum[i++]);
      return *this;
    }
    inline Writer& operator <<          (const long long int &x) {
      int i=20; long long int temp=x;
      if (temp == 0) write('0');
      if (temp < 0) write('-'), temp=-temp;
      while (temp) outnum[--i]=temp%10+'0', temp/=10;
      while (i<20) write(outnum[i++]);
      return *this;
    }
    inline Writer& operator <<     (const unsigned short int &x) {
      if (x == 0) write('0');
      int i=10; unsigned short int temp;
      while (temp) outnum[--i]=temp%10+'0', temp/=10;
      while (i<10) write(outnum[i++]); 
      return *this;
    }
    inline Writer& operator <<           (const unsigned int &x) {
      if (x == 0) write('0');
      int i=10; unsigned int temp;
      while (temp) outnum[--i]=temp%10+'0', temp/=10;
      while (i<10) write(outnum[i++]); 
      return *this;
    }
    inline Writer& operator << (const unsigned long long int &x) {
      if (x == 0) write('0');
      int i=20; unsigned long long temp;
      while (temp) outnum[--i]=temp%10+'0', temp/=10;
      while (i<20) write(outnum[i++]); 
      return *this;
    }
    inline Writer& operator <<                         (char *s) {
      while (*s!='\0') write(*(s++));
      return *this;
    }
    inline Writer& operator <<                   (const char *s) {
      *this << (char*)s;
      return *this;
    }
    inline Writer& operator <<                          (char c) {
      write(c);
      return *this;
    }
  }fout(stdout), ferr(stderr);
};
using FastIO::fin;
using FastIO::fout;
using FastIO::ferr;
 
#include <algorithm>
#include <set>
using std::multiset;
using std::sort;
 
int main() {
  int n, k;
  fin >> n >> k;
  long long int x, arr[n];
  for (int i=0; i<n; ++i) {
    fin >> arr[i] >> x;
    arr[i] += (x << 32);  
  }
  sort(arr,arr+n);
  multiset<int> st;
  int ans=0;
  for (int i=0; i<n; ++i)
    if (st.size() && int(arr[i]) >= *st.begin()) {
      auto ptr=st.upper_bound(int(arr[i]));
      st.erase(--ptr);
      st.insert(arr[i]>>32);
      ++ans;
    } else if ((int)st.size() < k) {
      st.insert(arr[i]>>32);
      ++ans;
    }
  fout << ans;
}
