/*
   This file is meant to keep your settings after an upgrade of the multi source.
   If you know parameters you want for sure to be enabled or disabled in future
   then just force their values here.
   To enable  a setting use #define <setting name>
   To disable a setting use #undef  <setting name>
*/

// For example you can also define multiple module configurations, uncomment the one you want to compile for:
#define Module_iRX4plus_Tgy9X
// #define Module_iRX4lite_Tanaris_Xlite

//Example on how to force the "Flash from TX" feature for all modules
// #define CHECK_FOR_BOOTLOADER

//Example on how to force the same ID for all modules: be carefull this is really if you want to be able to use one or another radio but not both!
//#define FORCE_GLOBAL_ID	0x12345678

#if defined Module_iRX4plus_Tgy9X

	// Settings for the iRangeX iRX4+ I'm using with my Turnigy 9X
	// auto-bind Hubsan automatically
	#undef ENABLE_BIND_CH
	// Disable features I'm not using to make it fit
	#undef ENABLE_PPM
	#undef TELEMETRY

#elif defined Module_iRX4lite_Tanaris_Xlite
	// Settings for the iRangeX iRX4 Lite I'm using with my Tanaris X-lite
	// #undef INVERT_TELEMETRY

	// Disable features I'm not using to make it fit
	#undef ENABLE_PPM
	// #undef ENABLE_BIND_CH
	// some protocols I don't need (these are RX protocols for wireless trainer mode)
	#undef AFHDS2A_RX_A7105_INO
	#undef DSM_RX_CYRF6936_INO
	#undef FRSKY_RX_CC2500_INO
	#undef BAYANG_RX_NRF24L01_INO
	// Other protocols to make more room
	#undef FUTABA_CC2500_INO
	#undef HITEC_CC2500_INO
#endif

// Minor abuse of the config file: 
// The compiler PlatformIO uses _really_ wants proper prototypes for some things in Multiplatform.ino.
// To minimize inline source diffs, I'm providing those here.

void Send_CCPM_USART1();
void release_trainer_ppm();
void tim1_up();
void tim1_cc();
#ifdef STM32_BOARD
	void usart2_begin(uint32_t baud,uint32_t config );
	void usart3_begin(uint32_t baud,uint32_t config );
	void init_HWTimer();
#endif
#ifdef CHECK_FOR_BOOTLOADER
	void Mprotocol_serial_init( uint8_t boot );
#else
	void Mprotocol_serial_init();
#endif
