namespace index
{
	enum
	{
		/// index not found
		not_found = -1,
	};
}

/**
* \brief static methods for manipulating an array of primitive types
*/
class buffer
{
public:
	/**
	* \brief copies a specified number of elements [size] from a source array [src] starting at a definite offset [src_offset] to a destination array [dst] starting at a definite offset [dst_offset]
	* \param [dst] destination array
	* \param [dst_offset] destination array's offset
	* \param [src] source array
	* \param [src_offset] source array's offset
	* \param [size] number of elements
	* \returns none
	*/
	template <typename type>
	static void copy(type** dst, u32 dst_offset, type** src, u32 src_offset, u32 size);

	/**
	* \brief adds all elements from a source array [src] of a definite size [src_size] to end of a destination array [dst] of a definite size [dst_size]
	* \param [dst] destination array
	* \param [dst_size] destination array's size
	* \param [src] source array
	* \param [src_size] source array's size
	* \returns destination array's size after operation
	*/
	template <typename type>
	static u32 add(type** dst, u32 dst_size, type** src, u32 src_size);

	/**
	* \brief includes all elements from a source array [src] of a definite size [src_size] to a destination array [dst] of a definite size [dst_size] into definite range [from \ to]
	* \param [dst] destination array
	* \param [dst_size] destination array's size
	* \param [src] source array
	* \param [src_size] source array's size
	* \param [from] range's begin index
	* \param [to] range's end index
	* \returns destination array's size after operation
	*/
	template <typename type>
	static u32 inc(type** dst, u32 dst_size, type** src, u32 src_size, u32 from, u32 to);

	/**
	* \brief extracts all elements from a source array [src] to a destination array [dst] into definite range [from \ to]
	* \param [dst] destination array
	* \param [src] source array
	* \param [from] range's begin index
	* \param [to] range's end index
	* \returns destination array's size after operation
	*/
	template <typename type>
	static u32 ext(type** dst, type** src, u32 from, u32 to);

	/**
	* \brief deletes all elements in a destination array [dst] of a definite size [dst_size] into definite range [from \ to]
	* \param [dst] destination array
	* \param [dst_size] destination array's size
	* \param [from] range's begin index
	* \param [to] range's end index
	* \returns destination array's size after operation
	*/
	template <typename type>
	static u32 del(type** dst, u32 dst_size, u32 from, u32 to);

	static u32 replace();
	static u32 replace_all();

	template <typename type>
	static u32 index(type** dst, u32 dst_size, u32 dst_offset, type** src, u32 src_size);

	template <typename type>
	static u32 index_last(type** dst, u32 dst_size, u32 dst_offset, type** src, u32 src_size);

	template <typename type>
	static u32 find(type** dst, u32 dst_size, u32 dst_offset, type** src, u32 src_size);
};

template <typename type>
void buffer::copy(type** dst, u32 dst_offset, type** src, u32 src_offset, u32 size)
{
	type* dst_array = (type*) *dst + dst_offset;
	type* src_array = (type*) *src + src_offset;

	for (u32 i = 0; i < size; i++)
	{
		dst_array[i] = src_array[i];
	}
}

template <typename type>
u32 buffer::add(type** dst, u32 dst_size, type** src, u32 src_size)
{
	type* dst_array = new type[dst_size + src_size];

	copy(&dst_array, 0, dst, 0, dst_size);
	copy(&dst_array, dst_size, src, 0, src_size);

	if (*dst != nullptr) delete[](*dst);
	*dst = dst_array;

	return dst_size + src_size;
}

template <typename type>
u32 buffer::inc(type** dst, u32 dst_size, type** src, u32 src_size, u32 from, u32 to)
{
	type* dst_array = new type[dst_size + src_size - (to - from)];

	copy(&dst_array, 0, dst, 0, from);
	copy(&dst_array, from, src, 0, src_size);
	copy(&dst_array, from + src_size, dst, to, dst_size - to);

	if (*dst != nullptr) delete[](*dst);
	*dst = dst_array;

	return dst_size + src_size - (to - from);
}

template <typename type>
u32 buffer::ext(type** dst, type** src, u32 from, u32 to)
{
	type* dst_array = new type[to - from];

	copy(&dst_array, 0, src, from, to - from);

	if (*dst != nullptr) delete[](*dst);
	*dst = dst_array;

	return to - from;
}

template <typename type>
u32 buffer::del(type** dst, u32 dst_size, u32 from, u32 to)
{
	type* dst_array = new type[dst_size - (to - from)];

	copy(&dst_array, 0, dst, 0, from);
	copy(&dst_array, from, dst, to, dst_size - to);

	if (*dst != nullptr) delete[](*dst);
	*dst = dst_array;

	return dst_size - (to - from);
}

template <typename type>
u32 buffer::index(type** dst, u32 dst_size, u32 dst_offset, type** src, u32 src_size)
{
	dst_size -= src_size;
	for (u32 i = dst_offset; i < dst_size; i++)
	{
		for (u32 j = 0; j < src_size; j++)
		{
			if ((*dst)[i + j] != (*src)[j])
			{
				break;
			}
			if (j + 1 == src_size) 
			{
				return i;
			}
		}
	}

	return index::not_found;
}

template <typename type>
u32 buffer::index_last(type** dst, u32 dst_size, u32 dst_offset, type** src, u32 src_size)
{
	dst_size -= src_size;
	for (u32 i = dst_offset; i >= 0; i--)
	{
		for (u32 j = 0; j < src_size; j++)
		{
			if ((*dst)[i + j] != (*src)[j])
			{
				break;
			}
			if (j + 1 == src_size) 
			{
				return i;
			}
		}
	}

	return index::not_found;
}

template <typename type>
u32 buffer::find(type** dst, u32 dst_size, u32 dst_offset, type** src, u32 src_size)
{
	u32 count = 0;

	dst_size -= src_size;
	for (u32 i = dst_offset; i < dst_size; i++)
	{
		for (u32 j = 0; j < src_size; j++)
		{
			if ((*dst)[i + j] != (*src)[j])
			{
				break;
			}
			if (j + 1 == src_size)
			{
				count++;
			}
		}
	}

	return count;
}