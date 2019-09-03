/**
 * \file
 *
 * \brief SAM USART Quick Start
 *
 * Copyright (c) 2012-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include <delay.h>

volatile int current_ch = 0;
volatile int state = 0;
	
void configure_usart(void);

//! [module_inst]
struct usart_module usart_instance;
struct usart_module usart_instance1;
struct usart_module usart_instance2;
struct usart_module usart_instance3;
struct usart_module usart_instance4;
struct usart_module usart_instance5;
//! [module_inst]

//! [setup]
void configure_usart(void)
{
	//*********** SERCOM 0 INIT ****************

	struct usart_config config_usart;

	usart_get_config_defaults(&config_usart);

	config_usart.baudrate    = 300;
	config_usart.mux_setting = USART_RX_3_TX_2_XCK_3;
	config_usart.pinmux_pad0 = PINMUX_PA10C_SERCOM0_PAD2;
	config_usart.pinmux_pad1 = PINMUX_PA11C_SERCOM0_PAD3;
	config_usart.pinmux_pad2 = PINMUX_UNUSED;
	config_usart.pinmux_pad3 = PINMUX_UNUSED;

	while (usart_init(&usart_instance,
			SERCOM0, &config_usart) != STATUS_OK) {
	}
	usart_enable(&usart_instance);



	//*********** SERCOM 1 INIT ****************

	struct usart_config config_usart1;
	
	usart_get_config_defaults(&config_usart1);
	
	config_usart1.baudrate    = 300;
	config_usart1.mux_setting = USART_RX_1_TX_0_XCK_1;
	config_usart1.pinmux_pad0 = PINMUX_PA17C_SERCOM1_PAD1;
	config_usart1.pinmux_pad1 = PINMUX_PA16C_SERCOM1_PAD0;
	config_usart1.pinmux_pad2 = PINMUX_UNUSED;
	config_usart1.pinmux_pad3 = PINMUX_UNUSED;
	//! [setup_change_config]

	//! [setup_set_config]
	while (usart_init(&usart_instance1,
	SERCOM1, &config_usart1) != STATUS_OK) {
	}
	//! [setup_set_config]

	//! [setup_enable]
	usart_enable(&usart_instance1);
	//! [setup_enable]
	
	//*********** SERCOM 2 INIT ****************
	
	struct usart_config config_usart2;
		
	usart_get_config_defaults(&config_usart2);

	config_usart2.baudrate    = 300;
	config_usart2.mux_setting = USART_RX_3_TX_0_XCK_1;
	config_usart2.pinmux_pad0 = PINMUX_PA15C_SERCOM2_PAD3;
	config_usart2.pinmux_pad1 = PINMUX_PA12C_SERCOM2_PAD0;
	config_usart2.pinmux_pad2 = PINMUX_UNUSED;
	config_usart2.pinmux_pad3 = PINMUX_UNUSED;

	while (usart_init(&usart_instance2,
	SERCOM2, &config_usart2) != STATUS_OK) {
	}

	usart_enable(&usart_instance2);
	
	//*********** SERCOM 3 INIT ****************
	
	struct usart_config config_usart3;
		
	usart_get_config_defaults(&config_usart3);

	config_usart3.baudrate    = 300;
	config_usart3.mux_setting = USART_RX_1_TX_0_XCK_1;
	config_usart3.pinmux_pad0 = PINMUX_PA23C_SERCOM3_PAD1;
	config_usart3.pinmux_pad1 = PINMUX_PA22C_SERCOM3_PAD0;
	config_usart3.pinmux_pad2 = PINMUX_UNUSED;
	config_usart3.pinmux_pad3 = PINMUX_UNUSED;

	while (usart_init(&usart_instance3,
	SERCOM3, &config_usart3) != STATUS_OK) {
	}

	usart_enable(&usart_instance3);
	
	//*********** SERCOM 4 INIT ****************
	
	struct usart_config config_usart4;
		
	usart_get_config_defaults(&config_usart4);

	config_usart4.baudrate    = 300;
	config_usart4.mux_setting = USART_RX_1_TX_0_XCK_1;
	config_usart4.pinmux_pad0 = PINMUX_PB13C_SERCOM4_PAD1;
	config_usart4.pinmux_pad1 = PINMUX_PB12C_SERCOM4_PAD0;
	config_usart4.pinmux_pad2 = PINMUX_UNUSED;
	config_usart4.pinmux_pad3 = PINMUX_UNUSED;

	while (usart_init(&usart_instance4,
	SERCOM4, &config_usart4) != STATUS_OK) {
	}

	usart_enable(&usart_instance4);
	
	//*********** SERCOM 5 INIT ****************
	
	struct usart_config config_usart5;
		
	usart_get_config_defaults(&config_usart5);

	config_usart5.baudrate    = 300;
	config_usart5.mux_setting = USART_RX_1_TX_0_XCK_1;
	config_usart5.pinmux_pad0 = PINMUX_PB17C_SERCOM5_PAD1;
	config_usart5.pinmux_pad1 = PINMUX_PB16C_SERCOM5_PAD0;
	config_usart5.pinmux_pad2 = PINMUX_UNUSED;
	config_usart5.pinmux_pad3 = PINMUX_UNUSED;

	while (usart_init(&usart_instance5,
	SERCOM5, &config_usart5) != STATUS_OK) {
	}

	usart_enable(&usart_instance5);
}
//! [setup]

int main(void)
{
	system_init();
	delay_init();

	configure_usart();

	uint8_t string[] = "Hello World!\r\n";
	usart_write_buffer_wait(&usart_instance, string, sizeof(string));
	usart_write_buffer_wait(&usart_instance1, string, sizeof(string));
	usart_write_buffer_wait(&usart_instance2, string, sizeof(string));
	usart_write_buffer_wait(&usart_instance3, string, sizeof(string));
	usart_write_buffer_wait(&usart_instance4, string, sizeof(string));
	usart_write_buffer_wait(&usart_instance5, string, sizeof(string));
		
	uint16_t tmp;
	uint8_t rev;
	

	
	while (true) {
		if (usart_read_wait(&usart_instance, &tmp) == STATUS_OK) {
			rev = (uint8_t)tmp;
			
			if (state == 0 && rev != 0x04) {
				if (current_ch == 0) {
					usart_write_wait(&usart_instance1, tmp);
				} 
				else if (current_ch == 1) {
					usart_write_wait(&usart_instance2, tmp);
				} 
				else if (current_ch == 2) {
					usart_write_wait(&usart_instance3, tmp);
				} 
				else if (current_ch == 3) {
					usart_write_wait(&usart_instance4, tmp);
				} 
				else if (current_ch == 4) {
					usart_write_wait(&usart_instance5, tmp);
				} 
			} 
			else if (state == 1) {
				if (rev == 0x30) {
					current_ch = 0;
				} 
				else if (rev == 0x31) {
					current_ch = 1;
				} 
				else if (rev == 0x32) {
					current_ch = 2;
				} 
				else if (rev == 0x33) {
					current_ch = 3;
				} 
				else if (rev == 0x34) {
					current_ch = 4;
				}
				
				state = 0;
			}
			
			if (rev == 0x04) {
				state = 1;
			}
		}
		
		if (current_ch == 0 && usart_read_wait(&usart_instance1, &tmp) == STATUS_OK) {
			usart_write_wait(&usart_instance, tmp);
		} 
		else if (current_ch == 1 && usart_read_wait(&usart_instance2, &tmp) == STATUS_OK) {
			usart_write_wait(&usart_instance, tmp);
		} 
		else if (current_ch == 2 && usart_read_wait(&usart_instance3, &tmp) == STATUS_OK) {
			usart_write_wait(&usart_instance, tmp);
		} 
		else if (current_ch == 3 && usart_read_wait(&usart_instance4, &tmp) == STATUS_OK) {
			usart_write_wait(&usart_instance, tmp);
		} 
		else if (current_ch == 4 && usart_read_wait(&usart_instance5, &tmp) == STATUS_OK) {
			usart_write_wait(&usart_instance, tmp);
		} 
	}
//! [main_loop]
//! [main]
}
