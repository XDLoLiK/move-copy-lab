#ifndef DEMO_INT_HPP
#define DEMO_INT_HPP

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define ALLOW_COPY_SEMANTICS 1
#define ALLOW_MOVE_SEMANTICS 1

#define DEMO_INT(name, value) DemoInt name(value, #name)
#define NEW_DEMO_INT(name, value) DemoInt* name = new DemoInt(value, #name)

#define OPERATIONS_N 5

class DemoInt {
public:
	/* Construction/destruction */
	DemoInt(int val = 0, const char* name = nullptr);
	~DemoInt();

#if (ALLOW_COPY_SEMANTICS == 1)
	/* Copying */
	DemoInt(const DemoInt& other, const char* name = nullptr);
	DemoInt& operator=(const DemoInt& other);
#endif /* ALLOW_COPY_SEMANTICS */

#if (ALLOW_MOVE_SEMANTICS == 1)
	/* Moving */
	DemoInt(DemoInt&& other, const char* name = nullptr);
	DemoInt& operator=(DemoInt&& other);
#endif /* ALLOW_MOVE_SEMANTICS */

	/* Arithmetics */
	DemoInt& operator+= (const DemoInt& other);
    DemoInt& operator-= (const DemoInt& other);
    DemoInt& operator*= (const DemoInt& other);
    DemoInt& operator/= (const DemoInt& other);
    DemoInt& operator%= (const DemoInt& other);
    DemoInt& operator&= (const DemoInt& other);
    DemoInt& operator|= (const DemoInt& other);
    DemoInt& operator^= (const DemoInt& other);
    DemoInt& operator<<=(const DemoInt& other);
    DemoInt& operator>>=(const DemoInt& other);

	DemoInt& operator++();
	DemoInt  operator++(int);
	DemoInt& operator--();
	DemoInt  operator--(int);

    /* Getters */
    int op_left() const;
    int value() const;
    const char* name() const;
    static int tmp_count();

private:
	static int m_tmp_count;

	char* m_name = nullptr;
	int m_value = 0;
	int m_operations_left = OPERATIONS_N; /* MUTABLE */
};

DemoInt operator+ (const DemoInt& first, const DemoInt& second);
DemoInt operator- (const DemoInt& first, const DemoInt& second);
DemoInt operator* (const DemoInt& first, const DemoInt& second);
DemoInt operator/ (const DemoInt& first, const DemoInt& second);
DemoInt operator% (const DemoInt& first, const DemoInt& second);
DemoInt operator& (const DemoInt& first, const DemoInt& second);
DemoInt operator| (const DemoInt& first, const DemoInt& second);
DemoInt operator^ (const DemoInt& first, const DemoInt& second);
DemoInt operator<<(const DemoInt& first, const DemoInt& second);
DemoInt operator>>(const DemoInt& first, const DemoInt& second);

DemoInt operator~ (const DemoInt& num);
DemoInt operator- (const DemoInt& num);
DemoInt operator+ (const DemoInt& num);

bool operator< (const DemoInt& first, const DemoInt& second);
bool operator> (const DemoInt& first, const DemoInt& second);
bool operator<=(const DemoInt& first, const DemoInt& second);
bool operator>=(const DemoInt& first, const DemoInt& second);
bool operator==(const DemoInt& first, const DemoInt& second);
bool operator!=(const DemoInt& first, const DemoInt& second);

#endif // DEMO_INT_HPP
