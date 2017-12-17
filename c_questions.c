main() {<br/>char s[]="man";<br/>int i; for(i=0;s[i];i++)<br/>printf("%c%c%c%c\s[i],*(s+i),*(i+s),i[s]); <br/>}
Man
mmmm aaaa nnnn
Nnnn aaaa Mmmm
Man Man Man
1
s[i], *(i+s), *(s+i), i[s] are all different ways of expressing the same idea. Generally array name is the base address for that array. Here s is the base address. i is the index number/displacement from the base address. So, indirecting it with * is same as s[i]. i[s] may be surprising. But in the case of C it is same as s[i]."
main() {<br/>float me = 1.1;<br/>double you = 1.1;<br/>if(me==you)<br/>printf("I love U");<br/>else<br/>printf("I hate U");<br/>}
I love U
I hate U
Garbage value
Compiler Error
1
For floating point numbers (float, double, long double) the values cannot be predicted exactly. Depending on the number of bytes, the precession with of the value represented varies. Float takes 4 bytes and long double takes 10 bytes. So float stores 0.9 with less precision than long double."
main() {<br/>int static var = 5;<br/>printf("%d ",var--);<br/>if(var) main();<br/>}
Compiler Error
1 2 3 4 5
Infinite loop
5 4 3 2 1
3
When static storage class is given, it is initialized once. The change in the value of a static variable is retained even between the function calls. Main is also treated like any other ordinary function, which can be called recursively."
main() {<br/>c[ ]={2.8,3.4,4,6.7,5};<br/>int j,*p=c,*q=c;<br/>for(j=0;j<5;j++) {<br/>printf(" %d ",*c);<br/>++q;<br/>}
2.8  3.4  4  6.7
2  8  3  4  4  6  7
2  2  2  2  2  2  3  4  6  5 
2  2  2  2  2  2  3  4  6  5  6 7
2
Initially pointer c is assigned to both p and q. In the first loop, since only q is incremented and not c , the value 2 will be printed 5 times. In second loop pitself is incremented. So the values 2 3 4 6 5 will be printed.
main() {<br/>extern int i;<br/>i=20;<br/>printf("%d",i);<br/>} 
20
Error : undefined reference to `i'
Garbage Value
Infinite loop
1
extern storage class in the following declaration, extern int i; specifies to the compiler that the memory for i is allocated in some other program and that address will be given to the current program at the time of linking. But linker finds that no other variable of name iis available in any other program with memory space allocated for it. Hence a linker error has occured .
main() {<br/>int i=-1,j=-1,k=0,l=2,m;<br/>m=i++&&j++&&k++||l++;<br/>printf("%d %d %d %d %d",i,j,k,l,m);<br/>} 
2 2 1 3 1
1 1 0 2 0
0 0 1 3 1
0 0 1 3 0
2
Logical operations always give a result of 1 or 0 . And also the logical AND (&&) operator has higher priority over the logical OR (||) operator. So the expression ‘i++ && j++ && k++’ is executed first. The result of this expression is 0 (-1 && -1 && 0 = 0). Now the expression is 0 || 2 which evaluates to 1 (because OR operator always gives 1 except for ‘0 || 0’ combination- for which it gives 0). So the value of m is 1. The values of other variables are also incremented by 1."
main() {<br/>printf("%x",-1<<4);<br/>} 
10
fffffffe
fffffff0
ffffffe0
2
 -1 is internally represented as all 1's. When left shifted four times the least significant 4 bits are filled with 0's.The %x format specifier specifies that the integer value be printed as a hexadecimal value."
main() {<br/>int i=10;<br/>i=!i>14;<br/>printf("i=%d",i);<br/>} 
i=0
i=10
i= 1
Error
0
In the expression !i>14 , NOT (!) operator has more precedence than '>' symbol. !is a unary logical operator. !i (!10) is 0 (not of true is false). 0>14 is false (zero).
main() {<br/>char s[]={'a','b','c','\n','c','\0'};<br/>char *p,*str,*str1;<br/>p=&s[3];<br/>str=p;<br/>str1=s;<br/>printf("%d",++*p + ++*str1-32);<br/>}
10
11
98
77
3
p is pointing to character '\n'. str1 is pointing to character 'a' ++*p. "pispointingto'\n'andthatisincrementedbyone." the ASCII value of '\n' is 10, which is then incremented to 11. The value of ++*p is 11. ++*str1, str1 is pointing to 'a' that is incremented by 1 and it becomes 'b'. ASCII value of 'b' is 98."
#define square(x) x*x <br/>main() {<br/>int i;<br/>i = 64/square(4);<br/>printf("%d",i);<br/>}
4
64
16
0
1
the macro call square(4) will substituted by 4*4 so the expression becomes i = 64/4*4 . Since / and * has equal priority the expression will be evaluated as (64/4)*4 i.e. 16*4 = 64
main() {<br/>&nbsp;&nbsp;&nbsp;&nbsp;void *v;<br/>&nbsp;&nbsp;&nbsp;&nbsp;int integer=2;<br/>&nbsp;&nbsp;&nbsp;&nbsp;int *i=&integer;<br/>&nbsp;&nbsp;&nbsp;&nbsp;v=i;<br/>&nbsp;&nbsp;&nbsp;&nbsp;printf("%d",(int*)*v);<br/>} 
2
null
Runtime Error
Compiler Error
3
Void pointer is a generic pointer type. No pointer arithmetic can be done on it. Void pointers are normally used for, <br/>1. Passing generic pointers to functions nd returning such pointers.<br/>2. As a intermediate pointer type.<br/>3. Used when the exact pointer type will be known at a later point of time.
main() {<br/>static int i;<br/> i++;<br/> static int j;<br/> j++;<br/> static int k;<br/> k++;<br/> printf("i=%d j=%d k=%d",i,j,k);<br/>}
i=0 j=0 k=0
i=1 j=1 k=1
GarbageValues
RuntimeError
1
Since static variables are initialized to zero by default
main() {<br/>int n = 10;<br/>while(1) {<br/>     if(printf("%d",printf("%d ", n)))<br/>         break;<br/>     else<br/>          continue;<br/>     }<br/>}
Infinite Loop
10 3
3 10
10 2
1
The inner printf executes first to print 10 and space. The printf returns no of characters printed and this value=3. Still the outer printf prints 10 and space and so returns a non-zero value. So it encounters the break statement and comes out of the while statement
main() {<br/>unsigned int i=2;<br/> while(i-->=0)printf("%u ",i);<br/>}
2 1 0
InfiniteLoop
RuntimeError
0 1 2
1
The value of y%2 is 0. This value is assigned to x. The condition reduces to if (x) or in other words if(0) and so z goes uninitialized. Thumb Rule: Check all control paths to write bug free code.
#define prod(a,b) a*b<br/> main() {<br/>int x=3,y=4;<br/> printf("%d",prod(x+2,y-1));<br/> } 
9
10
11
12
1
The macro expands and evaluates to as: x+2*y-1 => x+(2*y)-1 => 10 
main() {<br/>int i=2;<br/> while(i++!=3);<br/> printf("%d ",i);<br/> } 
1 
2 3
3 4
4
3
Note the semicolon after the while statement.  i=2, it is not equal to  becomes 3, it increments 3 != 3 is false but i increments to 4, comes out out of while loop. This is due to post-increment on i, the value of i while printing is 4. 
main() {<br/>int i=0;<br/> while(+(+i--)!=0) i-=i++;<br/>printf("%d",i);<br/>}
0
1
-1
-2
2
Unary + is the only dummy operator in C. So it has no effect on the expression and now the while loop is, while(i--!=0) which is false and so breaks out of while loop. The value –1 is printed due to the post-decrement operator.
main() {<br/>unsigned char i=0;<br/> for(;i>=0;i++);<br/> printf("%d\n",i);<br/>}
-128
-127
128
Infinite Loop
3
unsigned char will always be greater than 0.
main() {<br/>char i=0;<br/> for(;i>=0;i++);<br/> printf("%d\n",i);<br/>}
-128
-127
128
Infinite Loop
0
Notice the semicolon at the end of the for loop. THe initial value of the i is set to 0. The inner loop executes to increment the value from 0 to 127 (the positive range of char) and then it rotates to the negative value of -128. The condition in the for loop fails and so comes out of the for loop. It prints the current value of i that is -128.
Find what does int (*x)[10] mean?
x is a array of 10 integer pointers.
x is a pointer to array of(size 10) integers.
x is a array of 10 integers
Wrong declaration
1
Apply left to right rule to find the meaning of this definition.
#ifdef something<br/>int some=0;<br/>#endif<br/>main() {<br/>int thing = 0;<br/>printf("%d %d\n", some ,thing);<br/>} 
Compiler Error
Runtime Error
0 0
garbage Values
0
This is a very simple example for conditional compilation. The name something is not already known to the compiler making the declaration int some = 0; 
#if something == 0<br/>int some=0;<br/>#endif<br/>main() {<br/>int thing = 0;<br/>printf("%d %d\n", some ,thing);<br/>} 
Compiler Error
Runtime Error
0 0
garbage Values
2
This code is to show that preprocessor expressions are not the same as the ordinary expressions. If a name is not known the preprocessor treats it to be equal to zero.
main() {<br/>int arr2D[3][3];<br/>printf("%d\n", ((arr2D==* arr2D)&&(* arr2D == arr2D[0])) );<br/>}
1
0
GarbageValue
RuntimeError
0
This is due to the close relation between the arrays and pointers. N dimensional arrays are made up of (N-1) dimensional arrays. arr2D is made up of a 3 single arrays that contains 3 integers each.The name arr2D refers to the beginning of all the 3 arrays. *arr2D refers to the start of the first 1D array (of 3 integers) that is the same address as arr2D. So the expression (arr2D == *arr2D) is true (1). Similarly, *arr2D is nothing but *(arr2D + 0), adding a zero doesn't change the value/meaning. Again arr2D[0] is the another way of telling *(arr2D + 0). So the expression (*(arr2D + 0) == arr2D[0]) is true (1). Since both parts of the expression evaluates to true the result is true(1) and the same is printed.
main() {<br/>if(~0 == (unsigned int)-1)<br/>printf("Hi");<br/>else<br/>	printf("Hello");<br/>}
Hi
Hello
CompilerError
RuntimeError
0
~ (tilde operator or bit-wise negation operator) operates on 0 to produce all ones to fill the space for an integer. –1 is represented in unsigned value as all 1's and so both are equal.
int swap(int *a,int *b) {<br/>*a=*a+*b;*b=*a-*b;*a=*a-*b;<br/>}<br/>main() {<br/>int x=10,y=20;<br/>swap(&x,&y);<br/>printf("x= %d y = %d\n",x,y);<br/>}
GarbageValue
RuntimeError
x = 10 y = 20
x = 20 y = 10
3
This is one way of swapping two values. Simple checking will help understand this.
main() {<br/>char *p = "ayqm";<br/>printf("%c",++*(p++));}
a
y 
b
c
2
*(p) points to a, ++*(p) - pre-increments the value of a to b, then prints b. Then post-increments the p address to point to y.
main() {<br/>int i=5;<br/>printf("%d",++i++);<br/>}
5
6
CompilerError
RuntimeError
2
Compiler error: Lvalue required in function main. ++i yields an rvalue.  For postfix ++ to operate an lvalue is required.
int aaa() {<br/>printf("hi");<br/>}<br/>int bbb() {<br/>printf("hello");<br/>} <br/>int ccc(){<br/>printf("bye");<br/>}<br/>main() {<br/>int (*ptr[3])();<br/>ptr[0] = aaa;<br/>ptr[1] = bbb;<br/>ptr[2] =ccc;<br/>ptr[2]();<br/>}
hi
hello
bye
CompilerError
2
int (* ptr[3])() says that ptr is an array of pointers to functions that takes no arguments and returns the type int. By the assignment ptr[0] = aaa; it means that the first function pointer in the array is initialized with the address of the function aaa. Similarly, the other two array elements also get initialized with the addresses of the functions bbb and ccc. Since ptr[2] contains the address of the function ccc, the call to the function ptr[2]() is same as calling ccc(). So it results in printing "bye".
main() {<br/>int i=5;<br/>printf("%d",i=++i==6);<br/>}
5
6
0
1
3
The expression can be treated as i = (++i==6), because == is of higher precedence than = operator. In the inner expression, ++i is equal to 6 yielding true(1). Hence the result.
main() {<br/>char p[]="%d\n";<br/>p[1] = 'c';<br/>printf(p,65);<br/>}
65
A
B
c
1
Due to the assignment p[1] = "c" the string becomes, "%c\n". Since this string becomes the format string for printf and ASCII value of 65 is 'A', the same gets printed.
main() {<br/>while (strcmp("some","some\0"))<br/>printf("Strings are not equal\n");<br/>} 
Strings are not equal
No output
InfiniteLoop
RuntimeError
1
Ending the string constant with \0 explicitly makes no difference. So “some” and “some\0” are equivalent. So, strcmp returns 0 (false) hence breaking out of the while loop.
main() {<br/>char str1[] = {'s','o','m','e'};<br/>char str2[] = {'s','o','m','e','\0'};<br/>while (strcmp(str1,str2)==0)<br/>printf("Strings are not equal\n");<br/>} 
Strings are not equal
No output
Infinite Loop
RuntimeError
1
If a string constant is initialized explicitly with characters, '\0' is not appended automatically to the string. Since str1 doesn't have null termination, it treats whatever the values that are in the following positions as part of the string until it randomly reaches a '\0'. So str1 and str2 are not the same, hence the result.
main() {<br/>int i = 3;<br/>for (;i++=0;)<br/>printf("%d",i);}
RuntimeError
CompilerError
4
0
1
Compiler Error: Lvalue required. As we know that increment operators return rvalues and hence it cannot appear on the left hand side of an assignment operation.
main() {<br/>int i=10,j=20;<br/>j = i, j?(i,j)?i:j:j;<br/>printf("%d %d",i,j);<br/>}
10 10
20 20
10 20
20 10
0
The Ternary operator ( ? : ) is equivalent for if-then-else statement. So the question can be written as: if(i,j) {<br/>if(i,j)<br/>j = i;<br/>else<br/>j = j;<br/>}else<br/>j = j;<br/>
main() {<br/>int i=5,j=10;<br/>i=i&=j&&10;<br/>printf("%d %d",i,j);<br/>}
10 1
1 10
5 10
10 5
1
The expression can be written as i=(i&=(j&&10)); The inner expression (j&&10) evaluates to 1 because j==10. i is 5. i = 5&1 is 1. Hence the result.
main() {<br/>int i=4,j=7;<br/>j = j || i++ && printf("YOU CAN");<br/>printf("%d %d", i, j);<br/>}
5 7
7 5
1 5
4 1
3
The boolean expression needs to be evaluated only till the truth value of the expression is not known. j is not equal to zero itself means that the expression's truth value is 1. Because it is followed by || and true || (anything) => true where (anything) will not be evaluated. So the remaining expression is not evaluated and so the value of i remains the same. Similarly when && operator is involved in an expression, when any of the operands become false, the whole expression's truth value becomes false and hence the remaining expression will not be evaluated. false && (anything) => false where (anything) will not be evaluated.
main() {<br/>register int a=2;<br/>printf("Address of a = %d",&a);<br/>}
RuntimeError
CompilerError
2
GarbageValue
1
Compier Error: '&' on register variable. Rule to Remember : & (address of ) operator cannot be applied on register variables.
main() {<br/>float i=1.5;<br/>switch(i)<br/>{<br/>case 1: printf("1");<br/>case 2: printf("2");<br/>default : printf("0");<br/>}<br/>}
1
RuntimeError
CompilerError
GarbageValue
2
Compiler Error: switch expression not integral. Switch statements can be applied only to integral types.
main() {<br/>extern i;<br/>printf("%d\n",i);<br/>{<br/>int i=20;<br/>printf("%d\n",i);<br/>}<br/>}
GarbageValue 20
20 20
RuntimeError
CompilerError
3
Linker Error : Unresolved external symbol i. The identifier i is available in the inner block and so using extern has no use in resolving it.
main() {<br/>int a=2,*f1,*f2;<br/>f1=f2=&a;<br/>*f2+=*f2+=a+=2.5;<br/>printf("\n%d %d %d",a,*f1,*f2);<br/>}
2 2 2
4 4 4 
16 16 16
8 8 8
3
f1 and f2 both refer to the same memory location a. So changes through f1 and f2 ultimately affects only the value of a.
main() {<br/>char *p="GOOD";<br/>char a[]="GOOD";<br/>printf("sizeof(p) = %d, sizeof(*p) = %d, strlen(p) = %d", sizeof(p), sizeof(*p), strlen(p));<br/>printf(" sizeof(a) = %d, strlen(a) = %d", sizeof(a), strlen(a));<br/>}
sizeof(p) = 2, sizeof(*p) = 1, strlen(p) = 4 sizeof(a) = 4, strlen(a) = 4
sizeof(p) = 8, sizeof(*p) = 1, strlen(p) = 4 sizeof(a) = 5, strlen(a) = 4
sizeof(p) = 2, sizeof(*p) = 1, strlen(p) = 4 sizeof(a) = 5, strlen(a) = 4
sizeof(p) = 2, sizeof(*p) = 4, strlen(p) = 1 sizeof(a) = 4, strlen(a) = 2
1
When sizeof operator is applied to an array it returns the sizeof the array and it is not the same as the sizeof the pointer variable. Here the sizeof(a) where a is the character array and the size of the array is 5 because the space necessary for the terminating NULL character should also be taken into account.
#define DIM(array, type) sizeof(array)/sizeof(type)<br/>main() {<br/>int arr[10];<br/>printf("The dimension of the array is %d", DIM(arr, int));<br/>}
10
80
40
20
0
The size of integer array of 10 elements is 10 * sizeof(int). The macro expands to sizeof(arr)/sizeof(int) => 10 * sizeof(int) / sizeof(int) => 10. 
int DIM(int array[]) {<br/>return sizeof(array)/sizeof(int);<br/>}<br/>main() {<br/>int arr[10];<br/>printf("The dimension of the array is %d", DIM(arr));<br/>}
1
2
10
80
1
Arrays cannot be passed to functions as arguments and only the pointers can be passed. So the argument is equivalent to int * array (this is one of the very few places where [] and * usage are equivalent). The return statement becomes, sizeof(int *)/ sizeof(int) that happens to be equal in this case.
main() {<br/>void swap();<br/>int x=10,y=8;<br/>swap(&x,&y);<br/>printf("x=%d y=%d",x,y);<br/>}<br/>void swap(int *a, int *b) {<br/>*a ^= *b, *b ^= *a, *a ^= *b;<br/>}
x=8 y=10
x=10 y=8
x=8 y=6
x=12 y=10
0
This is a way to swap two variables without using a temporary variable and that too in a single statement.
main() {<br/>int i = 257;<br/>int *iPtr = &i;<br/>printf("%d %d", *((char*)iPtr), *((char*)iPtr+1) );<br/>}
257 257
1 1
1 257
257 1
1
The integer value 257 is stored in the memory as, 00000001 00000001, so the individual bytes are taken by casting it to char * and get printed.
main() {<br/>int i = 258;<br/>int *iPtr = &i;<br/>printf("%d %d", *((char*)iPtr), *((char*)iPtr+1) );<br/>}
1 1
1 2
2 1
2 2
2
The integer value 257 can be represented in binary as, 00000001 00000001. Remember that the INTEL machines are 'small-endian' machines. Small-endian means that the lower order bytes are stored in the higher memory addresses and the higher order bytes are stored in lower addresses. The integer value 258 is stored in memory as: 00000001 00000010.
main() {<br/>int i=300;<br/>char *ptr = &i;<br/>*++ptr=2; printf("%d",i);<br/>}
556
302
557
300
0
The integer value 300 in binary notation is: 00000001 00101100. It is stored in memory (small-endian) as: 00101100 00000001. Result of the expression *++ptr = 2 makes the memory representation as: 00101100 00000010. So the integer corresponding to it is 00000010 00101100 => 556.
main() {<br/>char * str = "hello";<br/>char * ptr = str;<br/>char least = 127;<br/>while (*ptr++)<br/>least = (*ptr<least ) ? *ptr :least;<br/>printf("%d",least);<br/>} 
0
1
127
128
0
After 'ptr' reaches the end of the string the value pointed by 'str' is '\0'. So the value of 'str' is less than that of 'least'. So the value of 'least' finally is 0. 
Is the following code legal?<br/>struct a {<br/>int x;struct a b;<br/>}
yes
no
N/A
N/A
1
Is it not legal for a structure to contain a member that is of the same type as in this case. Because this will cause the structure declaration to be recursive without end.
Is the following code legal?<br/>struct a {<br/>int x;<br/>struct a *b;<br/>} 
yes
no
N/A
N/A
0
*b is a pointer to type struct a and so is legal. The compiler knows, the size of the pointer to a structure even before the size of the structure is determined(as you know the pointer to any type is of same size). This type of structures is known as 'self-referencing' structure. 
Is the following code legal?<br/>typedef struct a {<br/>int x;<br/>aType *b;<br/>}aType
yes
no
N/A
N/A
1
The typename aType is not known at the point of declaring the structure (forward references are not made for typedefs).
Is the following code legal?<br/>typedef struct a aType;<br/>struct a {<br/>int x;<br/>aType *b;<br/>}; 
yes
no
N/A
N/A
0
The typename aType is known at the point of declaring the structure, because it is already typedefined.
Is the following code legal?<br/>main() {<br/>typedef struct a aType;<br/>aType someVariable;<br/>struct a {<br/>int x;<br/>aType *b;<br/>};<br/>}
yes
no
N/A
N/A
1
When the declaration, typedef struct a aType; is encountered body of struct a is not known. This is known as 'incomplete types'. 
main() {<br/>printf("%d ", sizeof( void *));<br/>printf("%d ", sizeof(int *));<br/>printf("%d ", sizeof(double *));<br/>printf("%d ", sizeof(struct unknown *));<br/>}
8 8 8 8
4 4 4 4
1 4 8 8
1 4 4 8
0
The pointer to any type is of same size.
Is this code legal?<br/>int *ptr;<br/>ptr = (int *) 0x400;
yes
no
N/A
N/A
0
The pointer ptr will point at the integer in the memory location 0x400.
#define a 10 <br/>main() {<br/>#define a 50 <br/>printf("%d",a);<br/>}
50 
10
CompilerError
RuntimeError
0
The preprocessor directives can be redefined anywhere in the program. So the most recently assigned value will be taken.
#define clrscr() 100 <br/>main() {<br/>clrscr(); <br/>printf("%d\n",clrscr()); <br/>}
100
200
CompilerError
RuntimeError
0
Preprocessor executes as a seperate pass before the execution of the compiler. So textual replacement of clrscr() to 100 occurs.The input program to compiler looks like this<br/>main() {<br/>100;<br/>printf("%d\n",100);<br/>}<br/>Note: 100; is an executable statement but with no action. So it doesn't give any problem.
main() { <br/>printf("%p",main); <br/>}
CompilerError
Some Address will be printed
RuntimeError
InfiniteLoop
1
Function  names  are  just  addresses  (just  like  array  names  are addresses). main() is also a function. So the address of function main will be printed. %p in printf specifies that the argument is an address. They are printed as hexadecimal numbers.
enum colors {BLACK,BLUE,GREEN} <br/>main() {<br/>printf("%d..%d..%d",BLACK,BLUE,GREEN);<br/>}
0..0..0
1..1..1
0..1..2
2..2..2
2
enum assigns numbers starting from 0, if not explicitly defined
main() { <br/>char *p; p="Hello"; <br/>printf("%c\n",*&*p); <br/>}
H
e
l
o
0
* is a dereference operator & is a reference operator. They can be applied any number of times provided it is meaningful. Here p points to the first character in the string "Hello". *p dereferences it and so its value is H. Again & references it to an address and * dereferences it to the value H.
main() {<br/>int i=5; <br/>printf("%d",i++ + ++i);<br/>}
10
11
12
13
2
First ++i run to increment the value from 5 to 6. i+i = 6+6 = 12. It prints then i++ will increment the value to 13.
main() { <br/>int i=5; <br/>printf("%d",i++ ++ +i); <br/>} 
10
11
12
CompilerError
3
The expression i+++++i is parsed as i ++ ++ + i which is an illegal combination of operators.
main() {<br/>int i=1,j=2; <br/>switch(i) { <br/>case 1: printf("GOOD"); break; <br/>case j: printf("BAD"); break; <br/>} <br/>} 
CompilerError
RuntimeError
GOOD
BAD
0
Compiler Error: Constant expression required in function main. The case statement can have only constant expressions (this implies that we cannot use variable names directly so an error). Note: Enumerated types can be used in case statements.
main() {<br/>int i; <br/>printf("%d",scanf("%d",&i)); // value 10 is given as input here <br/>}
10
2
1
0
2
Scanf returns number of items successfully read and not 1/0. Here 10 is given as input which should have been scanned successfully. So number of items read is 1.
#define f(g,g2) g##g2 <br/>main() { <br/>int var12=100; <br/>printf("%d",f(var,12)); <br/>}
100
12
CompilerError
RuntimeError
0
f(var,12) will preprocessed to var12. var12 = 100. ## will concatenate the variables.
main() { <br/>int i;<br/>for(i=0; i++; printf("%d",i)); <br/>printf("%d",i); <br/>}
InfiniteLoop
CompilerError
RuntimeError
0
3
Before entering into the for loop the checking condition is "evaluated". Here it evaluates to 0 (false) and comes out of the loop, and i is incremented (note the semicolon after the for loop).
main() { <br/>printf("%d", out); <br/>} <br/>int out=100;
CompilerError
RuntimeError
100
0
0
The rule is that a variable is available for use from the point of declaration. Even though a is a global variable, it is not available for main. Hence an error. 
main() { <br/>extern out; <br/>printf("%d", out); <br/>}<br/>int out=100; 
CompilerError
RuntimeError
100
0
2
If you want to use global variable before initialization use extern, so it will get correctly initialized.
main() {<br/>int a[] = {10,20,30,40,50},j,*p; <br/>for(j=0; j<1; j++) { <br/>printf("%d" ,*a); a++; <br/>} <br/>}
10
CompilerError
RuntimeError
100
1
Compiler error: lvalue required. Error is in line with statement a++. The operand must be an lvalue and may be of any of scalar type for the any operator, array name only when subscripted is an lvalue. Simply array name is a non-modifiable lvalue.
main() { <br/>void *vp;<br/>char ch = 'g',*cp = "goofy";<br/>int j = 20;<br/>vp = &ch;<br/>printf("%c",*(char *)vp); <br/>vp = &j; <br/>printf("%d",*(int *)vp); <br/>vp = cp;<br/>printf("%s",(char *)vp + 3);<br/>}
20ofy
g0020
g20fy
g23fy
2
Since a void pointer is used it can be type casted to any other type pointer. vp = &ch stores address of char ch and the next statement prints the value stored in vp after type casting it to the proper data type pointer. the output is 'g'. Similarly the output from second printf is '20'. The third printf statement type casts it to print the string from the 4th value hence the output.
main() { <br/>static char *s[ ] = {"black", "white", "yellow", "violet"}; <br/>char **ptr[ ] = {s+3, s+2, s+1, s}, ***p; <br/>p = ptr; <br/>**++p; <br/>printf("%s",*--*++p + 3); <br/>} 
wh
ye
ck
et
2
In this problem we have an array of char pointers pointing to start of 4 strings. Then we have ptr which is a pointer to a pointer of type char and a variable p which is a pointer to a pointer to a pointer of type char. p hold the initial value of ptr, i.e. p = s+3. The next statement increment value in p by 1 , thus now value of p = s+2. In the printf statement the expression is evaluated *++p causes gets value s+1 then the pre decrement is executed and we get s+1 – 1 = s . the indirection operator now gets the value from the array of s and adds 3 to the starting address. The string is printed starting from this position. Thus, the output is ‘ck’.
main() { <br/>char *cptr,c; <br/>void *vptr,v; <br/>c=10; <br/>v=0; <br/>cptr=&c; <br/>vptr=&v; <br/>printf("%c %v",c,v); <br/>}
10 0
10 10 
RuntimeError
CompilerError
3
You can create a variable of type void * but not of type void, since void is an empty type. In the second line you are creating variable vptr of type void * and v of type void hence an error. 
main() { <br/>char *str1="abcd"; <br/>char str2[]="abcd"; <br/>printf("%d %d %d",sizeof(str1),sizeof(str2),sizeof("abcd")); <br/>}
2 5 5
4 5 5  
8 5 5
16 5 5
2
In first sizeof, str1 is a character pointer so it gives you the size of the pointer variable. In second sizeof the name str2 indicates the name of the array whose size is 5 (including the '\0' termination character). The third sizeof is similar to the second one.
main() { <br/>char not; <br/>not=!2; <br/>printf("%d",not);<br/>}
0
1
2
3
0
! is a logical operator. In C the value 0 is considered to be the boolean value FALSE, and any non-zero value is considered to be the boolean value TRUE. Here 2 is a non-zero value so TRUE. !TRUE is FALSE. so it prints 0.
#define FALSE -1 <br/>#define TRUE 1 <br/>#define NULL 0 <br/>main() { <br/>if(NULL) <br/>puts("NULL"); <br/>else if(FALSE) <br/>puts("TRUE"); <br/>else <br/>puts("FALSE"); <br/>}
NULL 
TRUE
FALSE
CompilerError
1
Preprocessor doesn't replace the values given inside the double quotes. The check by if condition is boolean value false so it goes to else. In second if -1 is boolean value true hence "TRUE" is printed.
main() { <br/>int k=1; <br/>printf("%d==1 is ""%s",k,k==1?"TRUE":"FALSE"); <br/>} 
CompilerError
RuntimeError
1==1 is FALSE
1==1 is TRUE
3
When two strings are placed together (or separated by white-space) they are concatenated (this is called as "stringization" operation). So the string is as if it is given as "%d==1 is %s". The conditional operator( ?: ) evaluates to "TRUE".
main() {<br/>int y = 2000;<br/>if( (y%4==0 && y%100 != 0) || y%100 == 0 ) <br/>printf("%d is a leap year", y); <br/>else <br/>printf("%d is not a leap year", y); <br/>}
2000 is a leap year
2000 is not a leap year
N/A
N/A
0
An ordinary program to check given year is leap year or not. 
int i=10; <br/>main() { <br/>extern int i; <br/>{ <br/>int i=20; <br/>{<br/>const volatile unsigned i=30; printf("%d ",i);<br/>}<br/>printf("%d ",i);<br/>}<br/>printf("%d",i);<br/>}
10 20 30
30 20 10
20 10 30
30 10 20
1
'{' introduces new block and thus new scope. In the innermost block i is declared as, const volatile unsignedwhich is a valid declaration. i is assumed of type int. So printf prints 30. In the next block, i has value 20 and so printf prints 20. In the outermost block, i is declared as extern, so no storage space is allocated for it. After compilation is over the linker resolves it to global variable i (since it is the only variable visible there). So it prints i's value as 10.
main() {<br/>int *j;<br/>{<br/>int i=10; <br/>j=&i; <br/>} <br/>printf("%d",*j); <br/>}
10
GarbageValue
SomeAddress
RuntimeError
0
The variable i is a block level variable and the visibility is inside that block only. But the lifetime of i is lifetime of the function so it lives upto the exit of main function. Since the i is still allocated space, *j prints the value stored in i since j points i. 
main() {<br/>char a[]="12345\0";<br/>int i=strlen(a);<br/>printf("%d\n",++i);<br/>}
4
5
6
7
2
The char array 'a' will hold the initialized string, whose length will be counted from 0 till the null character. Hence the 'I' will hold the value equal to 5, after the pre-increment in the printf statement, the 6 will be printed.
main() {<br/>int k=ret(sizeof(float)); <br/>printf("%d",++k); <br/>}<br/>int ret(int ret) {<br/>ret += 2.5; return(ret);<br/>}
5
6
7
8
2
The int ret(int ret), ie., the function name and the argument name can be the same. Firstly, the function ret() is called in which the sizeof(float) ie., 4 is passed, after the first expression the value in ret will be 6, as ret is integer hence the value stored in ret will have implicit type conversion from float to int. The ret is returned in main() it is printed after and preincrement.
main() {<br/>int i;<br/>char a[]="\0"; <br/>if(printf("%s\n",a)) <br/>printf("Ok here \n"); <br/>else<br/>printf("Forget it\n");<br/>}
Ok here
Forget it
N/A
N/A
0
printf will return how many characters does it print. Hence printing a null character returns 1 which makes the if statement true, thus "Ok here" is printed.