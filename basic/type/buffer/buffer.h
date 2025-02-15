/**
* \brief static methods for manipulating an array of primitive types
*/
class buffer
{
	/**
	* \brief copies a specified number of elements [size] from a source array [src] starting at a definite offset [src_offset] to a destination array [dst] starting at a definite offset [dst_offset].
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
	* \brief adds all elements from a source array [src] of a definite size [src_size] to end of a destination array [dst] of a definite size [dst_size].
	* \param [dst] destination array
	* \param [dst_size] destination array's size
	* \param [src] source array
	* \param [src_size] source array's size
	* \returns destination array's size after operation
	*/
	template <typename type>
	static u32 add(type** dst, u32 dst_size, type** src, u32 src_size);

	/**
	* \brief includes all elements from a source array [src] of a definite size [src_size] to a destination array [dst] of a definite size [dst_size] into definite range [from \ to].
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