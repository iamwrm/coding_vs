#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// write a bmp file
	fstream file;
	char ch;
	int n;

	file.open("test.bmp", ios::out|ios::binary);
	// write Bitmap File Header
	ch = 'B'; file.write(&ch, 1);
	ch = 'M'; file.write(&ch, 1);
	n = 14 + 40 + 1024 + 256*256;
	file.write(reinterpret_cast<char*> (&n), 4);
	n = 0; file.write(reinterpret_cast<char*> (&n), 4);
	n = 14 + 40 + 1024;
	file.write(reinterpret_cast<char*> (&n), 4);
	// write DIB Header
	n = 40;
	file.write(reinterpret_cast<char*> (&n), 4);
	n = 256;
	file.write(reinterpret_cast<char*> (&n), 4);
	file.write(reinterpret_cast<char*> (&n), 4);
	ch = 1; file.write(&ch, 1);
	ch = 0; file.write(&ch, 1);
	ch = 8; file.write(&ch, 1);
	ch = 0; file.write(&ch, 1);
	n = 0; file.write(reinterpret_cast<char*> (&n), 4);
	n = 256*256;
	file.write(reinterpret_cast<char*> (&n), 4);
	n = 0; file.write(reinterpret_cast<char*> (&n), 4);
	n = 0; file.write(reinterpret_cast<char*> (&n), 4);
	n = 0; file.write(reinterpret_cast<char*> (&n), 4);
	n = 0; file.write(reinterpret_cast<char*> (&n), 4);
	// color table
	for (int i=0; i<256; i++)
	{
		ch = i;
		file.write(&ch, 1);
		file.write(&ch, 1);
		file.write(&ch, 1);
		ch = 0;
		file.write(&ch, 1);
	}
	// pixel data
	for (int i = 0; i<256; i++)
		for (int j = 0; j<256; j++)
		{ch = j; file.write(&ch, 1);}
	file.close();
	return 0;
}