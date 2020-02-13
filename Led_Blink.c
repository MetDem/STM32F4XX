// After KEILuVision Configuration add the stm32f4 library

#include "stm32f4xx.h"      // DEvice header 

int main()
{
    GPIO_InitTypeDef GPIO_InitStructure;                // GPIO_InitStructure is Value
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       //.._IN
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12 |        // kart üzerinde D pinleri ledlere bağlı
    GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //.._OD
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  //.._50-25-2 MHz

    /* GPIO'dan Structure ulaşmak gerekir (GPIO_InitTypeDef - IC2_InitTypeDef ...)
    GPIO CLOCK bilgisi gerektirir. ( Hangi hat kullanılacaksa o hatta bagli clock hatti RCC'da bulunur)
    (AHB1 CLocK BUS'a bagli AHB1Periph_GPIOD hattini ENABLE ettik) 
     Kullanılacak pinler belirtiliyor
      PushPull or OpenDrain
      Output durumunda PP(up-down belirtmeden) ya da OD (ikisi de aynı) yap boşuna direnç üzerinden akım geçirme
       Hızlar elektrik harcama ve tepki hızı olarak farklılık gösterir */

    GPIO_Init(GPIOD, &GPIO_InitStructure);          // tanımlana bilgileri GPIOD'ye atadık
    /* GPIO_InitStructure'da tanımlanan konfigler GPIOD'ye atadık*/

    GPIO_SetBits(GPIOD, GPIO_Pin_12);     // Logic High 3.3V
    GPIO_SetBits(GPIOD, GPIO_Pin_13); 
    // GPIO_ResetBits();   // Logic Zero 0V


    /* Kullanılacak porta göre Clock Buslarını librarydan (.rcc) bakıp yazmak lazım*/

}


    
