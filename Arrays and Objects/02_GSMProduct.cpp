/**task:
* Implement class Product that describes GSM Product with following characteristics:
* SKU, Brand, MODEL, Price, Count, RAM, ROM.
* Add appropriate setters and getters.
* Implement class Store. The store consists of GSM products.
* Add following methods: add, delete, change a particular product and print all products.
* If needed add more functions to the class Product in order to help you with the implementation of class Store.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Product // describes GSM Product
{

	public:

        int getSKU() const;

        void setBrand(char const *);
        void setMODEL(char const *);
        void setSKU(int SKU);
        void setPrice(int Price);
        void setCount(int Count);
        void setRAM(int RAM);
        void setROM(int ROM);

        Product(int SKU=-1, char const* Brand ="" , char const* MODEL="", double Price = 0, int Count=0,int RAM =0, int ROM=0); //parameterized constructor
        ~Product(); //destructor
        Product(const Product & p); //copy constructor
        Product& operator = (const Product &p); //operator=

        void deleteProduct();
        void Print();



	private:

        int SKU;
        char * Brand;
        char * MODEL;
        double Price;
        int Count;

        int RAM;
        int ROM;
};

int Product::getSKU()const
{
    return SKU;
}
void Product::setBrand(char const *_brand)
{
	delete[] Brand;
	Brand = new char[strlen(_brand) + 1];
	strcpy(Brand, _brand);

}
void Product::setMODEL(char const *_model)
{
	delete[] MODEL;
	MODEL = new char[strlen(_model) + 1];
	strcpy(MODEL, _model);
}
void Product::setSKU(int _SKU)
{
	SKU = _SKU;
}
void Product::setPrice(int _price)
{
	Price = _price;
}
void Product::setCount(int _count)
{
	Count = _count;
}
void Product::setRAM(int _RAM)
{
	RAM = _RAM;
}
void Product::setROM(int _ROM)
{
	ROM = _ROM;
}

 Product::Product(const Product & p) //copy constructor
{
	this->SKU = p.SKU;
	setBrand(p.Brand);
	setMODEL(p.MODEL);
	this->Price = p.Price;
	this->Count = p.Count;
	this->RAM = p.RAM;
	this->ROM = p.ROM;
}

void Product::deleteProduct() //destructor
{
	delete [] Brand;
	delete [] MODEL;
}

void Product::Print()
{

	cout << "SKU: " << SKU << endl;

	cout << "Brand: " << Brand << endl;

	cout << "Model: " << MODEL << endl;

	cout << "Price: " << Price<< endl;

	cout << "Count: " << Count << endl;

	cout << "RAM: " << RAM << endl;
	cout << "ROM: " << ROM << endl;

}

Product & Product::operator=(const Product & p)
{
	if (this != &p)
    {
		this->SKU = p.SKU;
        setBrand(p.Brand);
        setMODEL(p.MODEL);
        this->Price = p.Price;
        this->Count = p.Count;
        this->RAM = p.RAM;
        this->ROM = p.ROM;
	}

	return *this;
}
Product::Product(int _SKU, char const * _Brand, char const* _MODEL, double _Price, int _Count,int _RAM, int _ROM) //parametrized constructor
	:
	SKU(_SKU),
	Brand(NULL),
	MODEL(NULL),
	Price(_Price),
	Count(_Count),
	RAM (_RAM),
	ROM(_ROM)
{
	setBrand(_Brand);
	setMODEL(_MODEL);
}

Product::~Product()
{
	deleteProduct();
}

class Store
{
public:
	Store();
	~Store();
	Store(Store const &);
	Store& operator=(Store const &);
	void AddProduct();
	void DeleteProduct(int SKU);
	void ChangeProduct(int SKU);
	void Print();
private:
	void deleteStore();
	void copyStore(Store const&);
	void resize();

	Product * products;
	int productCount;
	int capacity;
};


Store::Store() :productCount(0),capacity(100)
{
	products = new Product[capacity];
}

Store::~Store()
{
	deleteStore();
}

Store::Store(const Store & st)
{
	copyStore(st);
}

Store & Store::operator=(Store const & st)
{
	if (this != &st)
	{
		deleteStore();
		copyStore(st);
	}
	return *this;
}

void Store::AddProduct()
{
	if (productCount == capacity)
	{
		resize();
	}

	Product pr;
	cout << "SKU: ";
	int SKU;
	cin >> SKU;
	pr.setSKU(SKU);
	cout << endl;

	cin.ignore();
	cout << "Brand: ";
	char brand[101];
	cin.getline(brand,100);
	pr.setBrand(brand);
	cout << endl;

	cout << "Model: ";
	char model[100];
	cin.getline(model, 100);
	pr.setMODEL(model);
	cout << endl;

	cout << "Price: ";
	int price;
	cin >> price;
	pr.setPrice(price);
	cout << endl;

	cout << "Count: ";
	int count;
	cin >> count;
	pr.setCount(count);

	cout << "RAM: ";
	int ram;
	cin >> ram;
	pr.setRAM(ram);


	cout << "ROM: ";
	int rom;
	cin >> rom;
	pr.setROM(ram);


	products[productCount] = pr;
	productCount++;
}

void Store::DeleteProduct(int SKU)
{
	int indexToDelete=-1;
	for (int i = 0; i < productCount; i++)
	{
		if (products[i].getSKU() == SKU)
		{
			indexToDelete = i;
			break;
		}
	}
	if (indexToDelete == -1)
	{
		cout << "Product not found!";
		return;
	}
	for (int i = indexToDelete; i < productCount; i++)
	{
		products[i] = products[i + 1];
	}
	productCount--;
}
void DisplayChangeMenu()
{
    cout<< "----Change menu:----"<<endl;
	cout << "1. Change SKU" << endl;
    cout << "2. Change brand" << endl;
	cout << "3. Change model" << endl;
	cout << "4. Change price" << endl;
	cout << "5. Change count" << endl;
	cout << "6. Change RAM" << endl;
	cout << "7. Change ROM" << endl;
	cout << "0. Exit Change menu"<<endl;
}

void Store::ChangeProduct(int SKU)
{
	for (int i = 0; i < productCount; i++)
	{
		int option;

		if (products[i].getSKU() == SKU)
		{
			while (true)
			{
				DisplayChangeMenu();
				cout << "Please, choose an option: ";
				cin >> option;
				switch (option)
				{

				case 1:
				{
					cout << "Enter the new SKU: ";
					int newSku;
					cin >> newSku;
					products[i].setSKU(newSku);
				}
				break;

				case 2:
				{
					cin.ignore();
					cout << "Enter the new brand: ";
					char newBrand[101];
					cin.getline(newBrand, 100);
					products[i].setBrand(newBrand);
				}
				break;

				case 3:
				{
					cout << "Enter the new model: ";
					cin.ignore();
					char newModel[101];
					cin.getline(newModel, 100);
					products[i].setMODEL(newModel);
				}break;

				case 4:
				{
					int newPrice;
					cout << "Enter new price: "; cin >> newPrice;
					products[i].setPrice(newPrice);
				}break;
				case 5:
				{
					int newCount;
					cout << "Enter new count: "; cin >> newCount;
					products[i].setCount(newCount);
				}break;

				case 6:
				{
					int newRAM;
					cout << "Enter new RAM: "; cin >> newRAM;
					products[i].setRAM(newRAM);
				}break;

				case 7:
				{
					int newROM;
					cout << "Enter new ROM: "; cin >> newROM;
					products[i].setROM(newROM);
				}break;
				case 0:return; break;
				default:cout << "Invalid option! Try again!" << endl;
				}
			}
		}
	}
}
void Store::Print()
{
	cout << "Total products: " << productCount <<endl;
	for (int i = 0; i < productCount; i++)
	{
		products[i].Print();
		cout << endl;
	}
}

void Store::deleteStore()
{
	delete[] products;
}

void Store::copyStore(Store const& n)
{
	this->capacity = n.capacity;
	this->productCount = n.productCount;
	Product * newProducts = new Product[capacity];
	for (size_t i = 0; i < productCount; i++)
	{
		newProducts[i] = n.products[i];
	}
	products = newProducts;
}

void Store::resize()
{
	capacity *= 2;
	Product * newProducts = new Product[capacity];
	for (size_t i = 0; i < productCount; i++)
	{
		newProducts[i] = products[i];
	}
	delete[] products;
	products = newProducts;
}

void DisplayMenu()
{
	cout << "-------Menu-------" << endl;
	cout << "A. Add new Product" << endl;
	cout << "X. Delete Product" << endl;
	cout << "C. Change Product" << endl;
	cout << "D. Display Products" << endl;
	cout << "Q. QUIT" << endl;
}

int main()
{
	Store st;
	char option;
	while (true) {
		DisplayMenu();
		cin >> option;
		switch (option)
		{
		case 'a':
		case 'A':st.AddProduct(); break;
		case 'x':
		case 'X':
		{
			int SKU;
			cout << "Enter the SKU of the product you'd like to delete: ";
			cin >> SKU;
			st.DeleteProduct(SKU);
		}
		break;

		case 'c':
		case 'C':
		{
			int SKU;
			cout << "Enter the SKU of the product you'd like to change: ";
			cin >> SKU;
			st.ChangeProduct(SKU);
		}
		break;

		case'd':
		case'D':st.Print(); break;

		case'q':
		case'Q': return 0;

		default:cout << "Invalid option" << endl;

		}
	}
	return 0;
}


