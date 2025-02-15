/**
* \brief text as a sequence of utf-8 code units
*/
class string
{
public:
	string();
	string(u32 size);

	c8& operator[] (u32 index);

	/// array of character utf-8
	c8* arr;

	/// string's size
	u32 size;
};

string::string()
{
	this->arr = nullptr;
	this->size = 0;
}

string::string(u32 size)
{
	this->arr = new c8[size]{};
	this->size = size;
}

c8& string::operator[](u32 index)
{
	return arr[index];
}