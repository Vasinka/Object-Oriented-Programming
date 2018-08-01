#include "Product.h"

int main()
{
	std::ifstream myfile;
	myfile.open("file.txt");
	Product allProducts[100];

	int i = 0;
	while (!myfile.eof())
	{
		Product currProduct;
		myfile >> currProduct;
		allProducts[i] = currProduct;
		i++;
	}

	int *deleteIndex = new int[100]();

	for (size_t j = 0; j < i; j++)
	{
		for (size_t k = j + 1; k < i; k++)
		{
			if (allProducts[j].getNumber() == allProducts[k].getNumber())
			{
				if (allProducts[j].getPrice() < allProducts[k].getPrice())
				{
					deleteIndex[k] = 1;
				}
				else deleteIndex[j] = 1;
			}
		}
	}

	std::ofstream myfile2;
	myfile2.open("file2.txt");

	for (int m = 0; m < i; m++)
	{
		if (deleteIndex[m] == 0)
		{
			myfile2 << allProducts[m];
		}
	}

}
