#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>
#include <cassert>

class CSmartFile

{
	std::unique_ptr<std::unique_ptr<FILE>> mFpHandle;

public:
	bool mhandleVaild = false;
	CSmartFile(const char* fname) {

		FILE* temp = fopen(fname, "a+b");//default
		assert(temp);
		if (temp) mhandleVaild = true;
		mFpHandle = std::make_unique<std::unique_ptr<FILE>>(temp);
	}
	CSmartFile(const char* fname, const char* mode) {
		FILE* temp = fopen(fname, mode);//default
		assert(temp);
		if (temp) mhandleVaild = true;
		mFpHandle = std::make_unique<std::unique_ptr<FILE>>(temp);
	}
	static bool fileIsExist(const char* fname) {
		FILE* temp = fopen(fname, "r+b");//default
		if (temp) {
			fclose(temp);
			return true;
		}
		else
			return false;
	}
	//explicit
	FILE* getFp() const {
		return mFpHandle.get()->get();
	}
	/*    need debug
	void reset(const char* fname, const char* mode) {
	 mhandleVaild = false;
	 fclose(mFpHandle.get()->get());
	 mFpHandle.get()->release();
	 FILE* temp = fopen(fname, mode);
	 assert(temp && "File reset Failed !");
	 if (temp) mhandleVaild = true;
	 mFpHandle = std::make_unique<std::unique_ptr<FILE>>(temp);
	}
	*/
	//implicit
	operator FILE* () const {
		return mFpHandle.get()->get();
	}

	CSmartFile& operator=(CSmartFile&) = delete; 
	~CSmartFile() { 
		try {
			fclose(mFpHandle.get()->get());
			mFpHandle.get()->release();
		}
		catch (...) {
			abort();
		}
	}

};
#pragma once
