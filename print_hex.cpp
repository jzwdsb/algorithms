#include <cstdio>
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <cfloat>
using byte_pointer = unsigned char*;


void show_byte(byte_pointer start, size_t len)
{
	int i = len - 1;
	while (i >= 0)
	{
		printf("%.2x", start[i]);
		--i;
	}
	printf("\n");
}

void show_float(float x)
{
	printf("float %g : ", x);
	show_byte(reinterpret_cast<byte_pointer>(&x), sizeof(x));
}

int main(int argc, char* argv[])
{
	float a = 64.875f, b = 32.75f;

	show_float(a);
	show_float(b);
	printf("%g 与 %g 的和:\n", a, b);
	show_float(a + b);
	printf("%g 与 %g 的差 :\n", a, b);
	show_float(a - b);
	if (argc > 1)
	{
		a = boost::lexical_cast<float>(argv[1]);
		b = boost::lexical_cast<float>(argv[2]);
	}
	printf("%g 与 %g 的和:\n", a, b);
	show_float(a + b);
	printf("%g 与 %g 的差 :\n", a, b);
	show_float(a - b);
	show_float(3.14f);
	show_float(1e20f);
	printf("3.14 + 1e20 :\n");
	show_float(3.14f + 1e20f);
	printf("(3.14 + 1e20f) - 1e20f: \n");
	show_float((3.14f + 1e20) -1e20);
	printf("3.14f + (1e20f - 1e20f): \n");
	show_float(3.14f + (1e20f - 1e20f));
	printf("log(-2.0) = %g\n", log(-2.0));
	show_float(static_cast<float>(log(-2.0)));
	show_float(FLT_MIN);
	show_float(FLT_MAX);
	show_float(FLT_MAX + FLT_MAX);
	return 0;
}
