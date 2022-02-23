void app_init(void) {
	*GPIO_D_MODER &= 0x00000000;	// Nollställer bit 31-16 resten kvarstår
	*GPIO_D_MODER |= 0x55005555;	// 0101 0101 0101 0101 (bit 31-16) resten kvarstår, bit 31-16 utsignaler med varje pin representerade med 2 bitar
	*GPIO_D_OTYPER &= 0x0000;	//	Nollställ bit 15-12 i OTYPER (push-pull), bit 11-8 kvarstår. utpinnar som push-pull
	*((unsigned long *) GPIO_D_BASE + 0x0E) &= 0x00000000;
	*((unsigned long *) GPIO_D_BASE + 0x0E) |= 0x00AA0000;	//	Sätt pull-down (1010) på inpinnar i register PUPDR(2bit/pin)
}