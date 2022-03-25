/* 尝试着在编译选项里使用和不使用-openmp 这个编译选项分别编译并执行代码 */
#include <iostream>

int main()
{
#ifdef _OPENMP  // 如果定义了这个宏
	std::cout << "Hello, OpenMP!" << std::endl;
#else
	std::cout << "OpenMP is not enabled." << std::endl;
#endif
	return 0;
}
