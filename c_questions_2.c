main() {
	void *v;
	int integer=2;
	int *i=&integer; 
	v=i;
	printf("%d\n",(int*)*v);
} 
2
null
Runtime Error
Compiler Error
3
Void pointer is a generic pointer type. No pointer arithmetic can be done on it. Void pointers are normally used for, <br/>1. Passing generic pointers to functions nd returning such pointers.<br/>2. As a intermediate pointer type.<br/>3. Used when the exact pointer type will be known at a later point of time.