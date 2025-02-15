template <typename type>
class list
{
	list();
	list(u32 size);

	type* buf;
	u32 size;
};

template <typename type>
list<type>::list()
{
	this->buf = nullptr;
	this->size = 0;
}

template <typename type>
list<type>::list(u32 size)
{
	this->buf = new type[size]{};
	this->size = size;
}