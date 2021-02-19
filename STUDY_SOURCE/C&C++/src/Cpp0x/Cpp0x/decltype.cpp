double d = 10.0;
decltype(d) b = 20;

decltype(d + b) val;

int foo();
decltype(foo()) returnType;