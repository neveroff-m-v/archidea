template <typename type>
class list
{
	list();
	list(u32 size);

	type& operator[] (u32 index);

	void add(list<type>* lst);
	void inc(list<type>* lst, u32 from, u32 to);
	void ext(list<type>* lst, u32 from, u32 to);
	void del(u32 from, u32 to);

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

template <typename type>
type& list<type>::operator[](u32 index)
{
	return arr[index];
}