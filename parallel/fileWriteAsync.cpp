
#include <windows.h>
#include <vector>

void CALLBACK FileIOCompletionRoutine(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped) {
	if (dwErrorCode != NO_ERROR) {
		printf("Failed to write file with error code: %lu\n", dwErrorCode);
	}
	_aligned_free(lpOverlapped->hEvent); // Free the buffer
	delete lpOverlapped; // Delete the OVERLAPPED structure
}

int main() {
	std::vector<short> data(100000000, 1);


	HANDLE hFile = CreateFile(L"output1.dat", GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS,
		FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING,
		NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		printf("Failed to open file for writing\n");
		return 1;
	}

	DWORD bytesPerSector;
	GetDiskFreeSpace(L"C:\\", NULL, &bytesPerSector, NULL, NULL);

	// Adjust the size of data to be a multiple of the sector size
	size_t dataSize = ((data.size() * sizeof(short) + bytesPerSector - 1) / bytesPerSector) * bytesPerSector;

	void* buffer = _aligned_malloc(dataSize, bytesPerSector);
	if (!buffer)
	{
		printf("Failed to allocate memory\n");
		CloseHandle(hFile);
		return 1;
	}

	memcpy(buffer, data.data(), data.size() * sizeof(short));
	memset((char*)buffer + data.size() * sizeof(short), 0, dataSize - data.size() * sizeof(short)); // Fill the rest with zeros

	OVERLAPPED* overlapped = new OVERLAPPED{ 0 }; // Allocate on heap
	if (!overlapped)
	{
		printf("Failed to allocate memory for OVERLAPPED structure\n");
		CloseHandle(hFile);
		return 1;
	}

	overlapped->hEvent = buffer; // Store pointer so it can be freed later

	BOOL result = WriteFileEx(hFile,
		buffer,
		dataSize,
		overlapped,
		FileIOCompletionRoutine);

	if (!result)
	{
		printf("Failed to start async write operation\n");
		CloseHandle(hFile);
		return 1;
	}

	SleepEx(INFINITE, TRUE);

	CloseHandle(hFile);

	return 0;
}