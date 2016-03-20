#include "gmock/gmock.h"

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	int value = RUN_ALL_TESTS();
	system("pause");	// otherwise you can't see the results in MSVC
	return value;
}