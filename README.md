# STM32F4XX
Personality

Hangi port kullanılacaksa ona bağlı olan clock bus'ı enable edilmelidir.stm32f4xx.rcc kütüphanesi içerisinde buslar ve bağlı oldukları yerler bulunmaktadır.

RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); --> AHB1 BUS'u GPIOD'e bağlıdır.

Declaration'lar üstte olması lazım !

Be attention the Library version (generally use 1.0.8)

ARM Cortex mimarisinde kod her zaman main’den değil ResetInterruptHandler’dan başlar. main, reset interrupt handler tarafından herhangi bir fonksiyon gibi çağırılır. (main yerin herhangi bir fonksiyon cagrilabilir)

“()”, bu şu demektir: sen parametre olarak ne verirsen ver ben sallamayacağım ve onu kullanmayacağım.
“(void)” ise: sen parametre olarak bana bir şey veremezsin.

“stdint.h” sistemler farkli oldugunda boyutlarda sorun cikmasin diye. Her sistemde standart boyut saglar.
Degisken	İşareti	Bits	Bytes	Minimum Değer	Maksimum Değer
int8_t	  Signed	  8	  1	  −27 = −128	27 − 1 = 127
uint8_t	  Unsigned	8	  1	  0	28 − 1 = 255
int16_t	  Signed	  16	2	  −215 = −32,768	215 − 1 = 32,767
uint16_t	Unsigned	16	2	  0	216 − 1 = 65,535
int32_t	  Signed	  32	4	  −231 = −2,147,483,648	231 − 1 = 2,147,483,647
uint32_t	Unsigned	32	4	  0	232 − 1 = 4,294,967,295
int64_t	  Signed	  64	8	  −263 = −9,223,372,036,854,775,808	263 − 1 = 9,223,372,036,854,775,807
uint64_t	Unsigned	64	8	  0	264 − 1 = 18,446,744,073,709,551,615

Değişkene durduğun yerde dur diyeceğiz. static uint32_t (Adresi degismiyor)

volatile uint32_t med=1997;






