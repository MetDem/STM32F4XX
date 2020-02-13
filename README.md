# STM32F4XX
Personality
Hangi port kullanılacaksa ona bağlı olan clock bus'ı enable edilmelidir.stm32f4xx.rcc kütüphanesi içerisinde buslar ve bağlı oldukları yerler bulunmaktadır.
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); --> AHB1 BUS'u GPIOD'e bağlıdır.
Declaration'lar üstte olması lazım !
