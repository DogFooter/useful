#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>


template <typename STR>
void HangulCorrection(STR& breaked_Str) {
  //인자는 string 이나 char 배열 가능
  
	setlocale(LC_ALL, "");

	int len = std::size(breaked_Str);
	assert(len != 0 && "empty string while hangulCorrection");

	std::vector<wchar_t> warr(len);

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)std::data(breaked_Str), -1, warr.data(), len);

	WideCharToMultiByte(CP_ACP, 0, warr.data(), -1, (LPSTR)std::data(breaked_Str), len, NULL, NULL);

}
