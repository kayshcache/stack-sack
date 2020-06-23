#ifndef COLLECT_H
#define COLLECT_H

char generate(int seed);

/* A A A A A 
 *
 * 1 x char
 * 1 constructor
 * 1 getter
 * */
class A {
	char name;
public:
	A() { name='A'; }
	char getName() { return name; }
};

/* B B B B B 
 *
 * 2 x chars
 * 1 constructor
 * 1 getter
 * */
class B {
	char name;
	char B1;
public:
	B() { name='B'; }
	char getName() { return name; }
};

/* C C C C C C 
 *
 * 4 x chars
 * 1 constructor
 * 1 getter
 * */
class C {
	char name;
	char C1, C2, C3;
public:
	C() { name='C'; }
	char getName() { return name; }
};

/* D D D D D D D
 *
 * 4 chars
 * 1 int
 * 1 constructor
 * 1 getter
 * */
class D {
	char name;
	char D1,D2,D3;
	int D4;
public:
	D() { name='D'; }
	char getName() { return name; }
};

/* E E E E E E E
 *
 * 4 chars
 * 3 ints
 * 1 constructor
 * 1 getter
 * */
class E {
	char name;
	char E1,E2,E3;
	int E4, E5, E6;
public:
	E() { name='E'; }
	char getName() { return name; }
};

/* F F F F F F
 *
 * 4 chars
 * 3 ints
 * 2 doubles
 * 1 constructor
 * 1 getter
 * */
class F {
	char name;
	char F1,F2,F3;
	int F4, F5, F6;
	double F7, F8;
public:
	F() { name='F'; }
	char getName() { return name; }
};

/* G G G G G
 *
 * 4 chars
 * 3 ints
 * 2 doubles
 * 2 long doubles
 * */
class G {
	char name;
	char G1,G2,G3;
	int G4,G5,G6;
	double G7,G8;
	long double G9,G10;
public:
	G() { name='G'; }
	char getName() { return name; }
};

#endif
