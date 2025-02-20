/**
* \brief strongly typed list of objects that can be accessed by index
*/
template <typename type>
class list
{
public:
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

template <typename type>
void list<type>::inc(list<type>* lst, u32 from, u32 to)
{
	size = buffer::inc(&arr, size, &(lst->arr), lst->size, from, to);
}

template <typename type>
void list<type>::ext(list<type>* lst, u32 from, u32 to)
{
	lst->size = buffer::ext(&(lst->arr), &arr, from, to);
}

template <typename type>
void list<type>::del(u32 from, u32 to)
{
	size = buffer::del(&arr, size, from, to);
}