/*
 * main.c
 *
 *  Created on: May 18, 2014
 *      Author: Devon
 */

#include "xparameters.h"
#include "xil_types.h"
#include "PWM_Generator.h"

int main(void)
{
	// Set period to 20ms and compare to 5% duty cycle
	PWM_GENERATOR_mDisableOutput(XPAR_PWM_GENERATOR_0_S_AXI_BASEADDR);
	PWM_GENERATOR_mSetLoad(XPAR_PWM_GENERATOR_0_S_AXI_BASEADDR, 2000000);
	PWM_GENERATOR_mSetCompare(XPAR_PWM_GENERATOR_0_S_AXI_BASEADDR, 200000);
	PWM_GENERATOR_mEnableOutput(XPAR_PWM_GENERATOR_0_S_AXI_BASEADDR);

	while(1)
	{

	}

	return 0;
}
