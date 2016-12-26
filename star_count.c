#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	const char *fileName = "IMG_raw_3030.raw";
	FILE *f = fopen(fileName, "rb");
	unsigned char *fileBuf;
	int star_count = 0;
	int threshold = 6; //lower threshold due to gaussian filter

	if (f == NULL)
		cout << "Could not open specified file" << endl;
	else
		cout << "File opened successfully" << endl;

	// Set the size of the file in bytes
	//long fileSize = 17915904;
	//long fileSize = 53747712;
	long fileSize = 17915904;
	// Allocate space in the buffer for the whole file
	fileBuf = new unsigned char[fileSize];
	//unsigned char fileBuf[5184][3456];

	// Read the file in to the buffer
	fread(fileBuf, fileSize, 1, f);

	int i = 0;
	int j = 0;


	// Show the value of the first 1000 pixels
	while (i<fileSize) {
		cout << (unsigned int)fileBuf[i] << " ";

		if (\
			(((unsigned int)fileBuf[i]) >  ((unsigned int)fileBuf[i - 1])) && \
			(((unsigned int)fileBuf[i]) >= ((unsigned int)fileBuf[i + 1])) && \
			/*(((unsigned int)fileBuf[i]) >  ((unsigned int)fileBuf[i][j - 1])) && \*/
			/*(((unsigned int)fileBuf[i]) >= ((unsigned int)fileBuf[i][j + 1])) && \*/
			(((unsigned int)fileBuf[i]) > threshold) \
			)
		{
			star_count++;
		}
		i++;
	}

	/*for (i = 0; i < 5184; i++)
	{
		for (j = 0; j< 3456; j++)
		{
			cout << (unsigned int)fileBuf[i] << " ";
			/*if (j >= 2116) //lower half of picture has higher background noise
			{
			threshold = 75;//adjust threshold
			}
			if (j >= 2821) //lower third of the picture has even higher background noise
			{
			threshold = 85;//adjust threshold further
			}
			if (\
				(((unsigned int)fileBuf[i][j]) >  ((unsigned int)fileBuf[i - 1][j])) && \
				(((unsigned int)fileBuf[i][j]) >= ((unsigned int)fileBuf[i + 1][j])) && \
				(((unsigned int)fileBuf[i][j]) >  ((unsigned int)fileBuf[i][j - 1])) && \
				(((unsigned int)fileBuf[i][j]) >= ((unsigned int)fileBuf[i][j + 1])) && \
				(((unsigned int)fileBuf[i][j]) > threshold) \
				)
			{
				star_count++;
			}


			
		}
	}*/

	cout << endl;
	cout << "i = " << i;
	cout << endl;
	cout << "Star count = " << star_count;
	cin.get();
	delete[]fileBuf;
	fclose(f);
	return 0;
}
