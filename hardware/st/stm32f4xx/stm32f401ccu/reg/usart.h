/**
* \brief universal synchronous asynchronous receiver transmitter
*/
struct usart_reg
{
	volatile u32 SR;         /*!< USART Status register,                   Address offset: 0x00 */
	volatile u32 DR;         /*!< USART Data register,                     Address offset: 0x04 */
	volatile u32 BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
	volatile u32 CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
	volatile u32 CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
	volatile u32 CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
	volatile u32 GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
};