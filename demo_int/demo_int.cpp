#include "demo_int.hpp"
#include "graphviz.hpp"

int DemoInt::m_tmp_count = 0;

DemoInt::DemoInt(int val, const char* name):
	m_name(nullptr),
	m_value(val),
	m_operations_left(OPERATIONS_N)
{
	if (name == nullptr) {
		m_name = strdup(("tmp" + std::to_string(m_tmp_count++)).c_str());
		Graphviz_CreateNode(this, "red", "ffe0e0");
	} else {
		m_name = strdup(name);
		Graphviz_CreateNode(this, "darkgreen", "e0ffe0");
	}
}

DemoInt::~DemoInt()
{
	m_value = 0;
	m_operations_left = 0;
	free(m_name);
	m_name = nullptr;
}

#if (ALLOW_COPY_SEMANTICS == 1)

DemoInt::DemoInt(const DemoInt& other, const char* name)
{
	m_value = other.value();
	m_operations_left = OPERATIONS_N;

	if (name == nullptr) {
		m_name = strdup(("tmp" + std::to_string(m_tmp_count++)).c_str());
		Graphviz_CreateNode(this, "red", "ffe0e0");
	} else {
		m_name = strdup(name);
		Graphviz_CreateNode(this, "darkgreen", "e0ffe0");
	}

	Graphviz_CreateOrientedEdge(other, *this, "red", "COPY", "red");
	Graphviz_IncreaseCopyCount();
}

DemoInt& DemoInt::operator=(const DemoInt& other)
{
	if (m_operations_left <= 0) {
		printf("You have no operations left. Pay 5$ to continue.\n");
		return *this;
	}

	m_value = other.value();
	m_operations_left = other.op_left();

	Graphviz_CreateOrientedEdge(other, *this, "red", "COPY", "red");
	Graphviz_IncreaseCopyCount();
	return *this;
}

#endif /* ALLOW_COPY_SEMANTICS */

#if (ALLOW_MOVE_SEMANTICS == 1)

DemoInt::DemoInt(DemoInt&& other, const char* name)
{
	m_value = other.value();
	m_operations_left = OPERATIONS_N;

	if (name == nullptr) {
		m_name = strdup(("tmp" + std::to_string(m_tmp_count++)).c_str());
		Graphviz_CreateNode(this, "red", "ffe0e0");
	} else {
		m_name = strdup(name);
		Graphviz_CreateNode(this, "darkgreen", "e0ffe0");
	}

	Graphviz_CreateOrientedEdge(other, *this, "darkgreen", "MOVE", "darkgreen");
}

DemoInt& DemoInt::operator=(DemoInt&& other)
{
	if (m_operations_left <= 0) {
		printf("You have no operations left. Pay 5$ to continue.\n");
		return *this;
	}

	m_value = other.value();
	m_operations_left = other.op_left();

	Graphviz_CreateOrientedEdge(other, *this, "darkgreen", "MOVE", "darkgreen");
	return *this;
}

#endif /* ALLOW_MOVE_SEMANTICS */

#define UNARY_OPERATOR(op)                                                       \
DemoInt& DemoInt::operator op(const DemoInt& other)                              \
{                                                                                \
	if (m_operations_left <= 0) {                                            \
		printf("You have no operations left. Pay 5$ to continue.\n");    \
		return *this;                                                    \
	}                                                                        \
                                                                                 \
	m_value op other.value();                                                \
	m_operations_left--;                                                     \
                                                                                 \
	return *this;                                                            \
}

UNARY_OPERATOR(+=)
UNARY_OPERATOR(-=)
UNARY_OPERATOR(*=)
UNARY_OPERATOR(/=)
UNARY_OPERATOR(%=)
UNARY_OPERATOR(&=)
UNARY_OPERATOR(|=)
UNARY_OPERATOR(^=)
UNARY_OPERATOR(<<=)
UNARY_OPERATOR(>>=)

#undef UNARY_OPERATOR

DemoInt& DemoInt::operator++()
{
	if (m_operations_left <= 0) {
		printf("You have no operations left. Pay 5$ to continue.\n");
		return *this;
	}

	m_value++;
	m_operations_left--;

	return *this;
}

DemoInt DemoInt::operator++(int)
{
	DemoInt temp = *this;
	++*this;
	
	return temp;
}

DemoInt& DemoInt::operator--()
{
	if (m_operations_left <= 0) {
		printf("You have no operations left. Pay 5$ to continue.\n");
		return *this;
	}

	m_value--;
	m_operations_left--;

	return *this;
}

DemoInt DemoInt::operator--(int)
{
	DemoInt temp = *this;
	--*this;
	
	return temp;
}

DemoInt operator~(const DemoInt& num)
{
	DemoInt temp(~num.value());
	Graphviz_CreateUnaryOperationNode(num, temp, "~");

	return temp;
}

DemoInt operator-(const DemoInt& num)
{
	DemoInt temp(-num.value());
	Graphviz_CreateUnaryOperationNode(num, temp, "-");

	return temp;
}

DemoInt operator+(const DemoInt& num)
{
	DemoInt temp(+num.value());
	Graphviz_CreateUnaryOperationNode(num, temp, "+");

	return temp;
}

#define BINARY_OPERATOR(op)                                              \
DemoInt operator op(const DemoInt& first, const DemoInt& second)         \
{                                                                        \
	DemoInt temp(first.value() op second.value());                   \
	Graphviz_CreateOperationNode(first, second, temp, #op);          \
                                                                         \
	return temp;                                                     \
}

BINARY_OPERATOR(+)
BINARY_OPERATOR(-)
BINARY_OPERATOR(*)
BINARY_OPERATOR(/)
BINARY_OPERATOR(%)
BINARY_OPERATOR(&)
BINARY_OPERATOR(|)
BINARY_OPERATOR(^)
BINARY_OPERATOR(<<)
BINARY_OPERATOR(>>)

#undef BINARY_OPERATOR

bool operator<(const DemoInt& first, const DemoInt& second)
{
	return first.value() < second.value();
}

bool operator>(const DemoInt& first, const DemoInt& second)
{
	return second < first;
}

bool operator<=(const DemoInt& first, const DemoInt& second)
{
	return first < second || first == second;
}

bool operator>=(const DemoInt& first, const DemoInt& second)
{
	return first > second || first == second;
}

bool operator==(const DemoInt& first, const DemoInt& second)
{
	return !(first < second || first > second);
}

bool operator!=(const DemoInt& first, const DemoInt& second)
{
	return !(first == second);
}

int DemoInt::op_left() const
{
	return m_operations_left;
}

int DemoInt::value() const
{
	return m_value;
}

const char* DemoInt::name() const
{
	return m_name;
}

int DemoInt::tmp_count()
{
	return m_tmp_count;
}
