/**
* \brief external interrupt / event (exti) register
*/
struct exti_reg
{
	/// interrupt mask register
	volatile u32 imr;

	/// event mask register
	volatile u32 emr;

	/// rising trigger selection register
	volatile u32 rtsr;

	/// falling trigger selection register
	volatile u32 ftsr;

	/// software interrupt event register
	volatile u32 swier;

	/// pending register
	volatile u32 pr;
};