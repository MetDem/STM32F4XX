// After KEILuVision Configuration add the stm32f4 library

#include "stm32f4xx.h"      // DEvice header 

int main()
{
    GPIO_InitTypeDef GPIO_InitStructure;                // GPIO_InitStructure is Value
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 


    // LED CONGIRATION 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       //.._IN
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12 |        // kart üzerinde D pinleri ledlere bağlı
    GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //.._OD
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  //.._50-25-2 MHz
    GPIO_Init(GPIOD, &GPIO_InitStructure);              // tanımlana bilgileri GPIOD'ye atadık
   
    // BUTTON CONFIGURATION
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;       
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0            // kart mavi buton
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;       //.._OD
    /* OD ya da PP olabilir external(harici-dışardan) direnç kullanılacaksa OD seçilir
    board üzerindeki buton PP ile kullanılır*/
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN       //.._DOWN  
    /*PP olarak belirledikten sonra gerekirse Pull-Down ya da Pull-Up ayarlanabilinir*/
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  //.._50-25-2 MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);



    /* Kullanılacak porta göre Clock Buslarını librarydan (.rcc) bakıp yazmak lazım */
    /* GPIO_Init fonksiyonu olmadan yapılan ayarlamalar havada kalır */

}


    
