# 1 "newmain.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "newmain.c" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\__size_t.h" 1 3



typedef unsigned size_t;
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 2 3

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\__null.h" 1 3
# 5 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdarg.h" 1 3






typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);
# 11 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 2 3
# 43 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 3
struct __prbuf
{
 char * ptr;
 void (* func)(char);
};
# 85 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\conio.h" 1 3







# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\errno.h" 1 3
# 29 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\errno.h" 3
extern int errno;
# 8 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\conio.h" 2 3




extern void init_uart(void);

extern char getch(void);
extern char getche(void);
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);



extern char * cgets(char *);
extern void cputs(const char *);
# 85 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 2 3



extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);
# 180 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdio.h" 3
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);
# 1 "newmain.c" 2



struct myStruct {
 char s1;
 char s2;
 int s3;
 float s4;
};

int main() {
 struct myStruct data = {1,2,3,4};
 char x;
# 24 "newmain.c"
 int arr[sizeof(data)];

}
