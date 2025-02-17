template <typename type>
class list
{
	list();
	list(u32 size);

	type& operator[] (u32 index);

	void add(type* element);
	void add(list<type>* lst);

	void inc(list<type>* lst, u32 from, u32 to);
	void ext(list<type>* lst, u32 from, u32 to);
	void del(u32 from, u32 to);

	type* arr;
	u32 size;
};

template <typename type>
list<type>::list()
{
	this->arr = nullptr;
	this->size = 0;
}

template <typename type>
list<type>::list(u32 size)
{
	this->arr = new type[size]{};
	this->size = size;
}

template <typename type>
type& list<type>::operator[](u32 index)
{
	return arr[index];
}

template <typename type>
void list<type>::add(type* element)
{
	size = buffer::add(&arr, size, &element, 1);
}

template <typename type>
void list<type>::add(list<type>* lst)
{
	size = buffer::add(&arr, size, &(lst->arr), lst->size);
}