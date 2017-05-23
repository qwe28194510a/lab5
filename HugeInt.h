#include<iostream>
#include<string>
#include<vector>
using namespace std;
class HugeInt{
friend istream & operator>>(istream &,HugeInt &);
friend ostream & operator<<(ostream &,const HugeInt &);

public:
	HugeInt();
	HugeInt(int);
	HugeInt(string);

	HugeInt & operator=(const HugeInt &);
        const HugeInt operator+(const HugeInt &);
        const HugeInt operator-(const HugeInt &);

private:
vector<int> int_vector;
};
