/**
* \brief text as a sequence of utf-8 code units
*/
class string
{
public:
	string();
	string(u32 size);
	string(const c8* arr);

	~string();

	c8& operator[] (u32 index);

	logic is_empty();

	void add(string* str);
	void inc(string* str, u32 from, u32 to);
	void ext(string* str, u32 from, u32 to);
	void del(u32 from, u32 to);

	u32 index(string* str, u32 start_index = 0);
	u32 find(string* str, u32 start_index = 0);

	void split(list<string>* lst, string* separator);

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

string::~string()
{
	//buffer::clear(&arr);
}

c8& string::operator[](u32 index)
{
	return arr[index];
}

logic string::is_empty()
{
	return size == 0;
}

void string::add(string* str)
{
	size = buffer::add(&arr, size, &(str->arr), str->size);
}

void string::inc(string* str, u32 from, u32 to)
{
	size = buffer::inc(&arr, size, &(str->arr), str->size, from, to);
}

void string::ext(string* str, u32 from, u32 to)
{
	str->size = buffer::ext(&(str->arr), &arr, from, to);
}

void string::del(u32 from, u32 to)
{
	size = buffer::del(&arr, size, from, to);
}

u32 string::index(string* str, u32 start_index)
{
	return buffer::index(&arr, size, start_index, &(str->arr), str->size);
}

u32 string::find(string* str, u32 start_index)
{
	return buffer::find(&arr, size, start_index, &(str->arr), str->size);
}

void string::split(list<string>* lst, string* separator)
{
	u32 from = 0;
	u32 to = 0;
	string str;

	lst = new list<string>(0);
	for(;;)
	{
		to = index(separator, from);
		if (to != index::not_found)
		{
			ext(&str, from, to);
			lst->add(&str);

			from = to + separator->size;
		}
		else
		{
			break;
		}
	}
}