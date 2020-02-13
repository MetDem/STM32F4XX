// After KEILuVision Configuration add the stm32f4 library

#include "stm32f4xx.h"      // DEvice header 

int main()
{
    GPIO_InitTypeDef GPIO_InitStructure;                // GPIO_InitStructure is Value
    uint8_t button_input;
    /*unsigned int */

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 

    /* Clock Bus tanimlamalari */


    // LED CONGIRATION 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       //.._IN
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12 |        // kart üzerinde D pinleri ledlere bağlı
    GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //.._OD
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  //.._50-25-2 MHz
    GPIO_Init(GPIOD, &GPIO_InitStructure);              // tanımlana bilgileri GPIOD'ye atadık
   
    // BUTTON CONFIGURATION
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;       
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0            // kart üzerindeki mavi buton A0-Pin
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;       //.._OD
    /* OD ya da PP olabilir external(harici-dışardan) direnç kullanılacaksa OD seçilir
    board üzerindeki buton PP ile kullanılır*/
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN       //.._UP 
    /* Butona basılmadığında 0 bigisi gidecektir */
    /*PP olarak belirledikten sonra gerekirse Pull-Down ya da Pull-Up ayarlanabilinir.*/
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  //.._50-25-2 MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    while(1)
    {
        button_input = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);

        if (button_input)
        {
            GPIO_SetBits(GPIOD, GPIO_Pin12 | GPIO_Pin13 | GPIO_Pin14 | GPIO_Pin15);
        }
        else
        {
            GPIO_ResetBits(GPIOD, GPIO_Pin12 | GPIO_Pin13 | GPIO_Pin14 | GPIO_Pin15);
        }
    }



    /* Kullanılacak porta göre Clock Buslarını librarydan (.rcc) bakıp yazmak lazım*/
    /* GPIO_Init fonksiyonu olmadan yapılan ayarlamalar havada kalır*/

}


    
