/**
* \brief text as a sequence of utf-8 code units
*/
class string
{
public:
	string();
	string(u32 size);
	string(const c8* arr);

	c8& operator[] (u32 index);

	void u8 is_empty();

	void add(c8 c);
	void add(c8* arr, u32 size);
	void add(string* str);

	void sub(string* str, u32 from, u32 to);
	void del(u32 from, u32 to);

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

string::string(const c8* arr)
{
	for (size = 0; arr[size] != '\0'; size++) {}
	this->arr = new c8[size];

	for (u32 i = 0; i < size ; i++)
	{
		this->arr[i] = arr[i];
	}
}

c8& string::operator[](u32 index)
{
	return arr[index];
}

void string::del(string* str, u32 from, u32 to)
{
	*str = string(from, to);
	size = buffer::del(&arr, size, from, to);
}

void string::del(u32 from, u32 to)
{
	size = buffer::del(&arr, size, from, to);
}