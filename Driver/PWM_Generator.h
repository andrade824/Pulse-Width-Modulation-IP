
#ifndef PWM_GENERATOR_H
#define PWM_GENERATOR_H


/****************** Include Files ********************/
#include "xil_types.h"
#include "xstatus.h"
#include "xil_io.h"

#define PWM_GENERATOR_S_AXI_LOAD_REG_OFFSET 0
#define PWM_GENERATOR_S_AXI_COMPARE_REG_OFFSET 4
#define PWM_GENERATOR_S_AXI_CONTROL_REG_OFFSET 8
#define PWM_GENERATOR_S_AXI_UNUSED_REG_OFFSET 12

/**************************** Type Definitions *****************************/
/**
 *
 * Write a value to a PWM_GENERATOR register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the PWM_GENERATORdevice.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void PWM_GENERATOR_mWriteReg(u32 BaseAddress, unsigned RegOffset, u32 Data)
 *
 */
#define PWM_GENERATOR_mWriteReg(BaseAddress, RegOffset, Data) \
  	Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))

/**
 *
 * Read a value from a PWM_GENERATOR register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the PWM_GENERATOR device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	u32 PWM_GENERATOR_mReadReg(u32 BaseAddress, unsigned RegOffset)
 *
 */
#define PWM_GENERATOR_mReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))

// Enables PWM Output by setting bit 0 of the control register
#define PWM_GENERATOR_mEnableOutput(BaseAddress) \
  	PWM_GENERATOR_mWriteReg(BaseAddress, PWM_GENERATOR_S_AXI_CONTROL_REG_OFFSET, 1)

// Disables PWM Output by clearing bit 0 of the control register
#define PWM_GENERATOR_mDisableOutput(BaseAddress) \
  	PWM_GENERATOR_mWriteReg(BaseAddress, PWM_GENERATOR_S_AXI_CONTROL_REG_OFFSET, 0)

// Sets the PWM Generator's load value
#define PWM_GENERATOR_mSetLoad(BaseAddress, Load) \
  	PWM_GENERATOR_mWriteReg(BaseAddress, PWM_GENERATOR_S_AXI_LOAD_REG_OFFSET, Load)

// Sets the PWM Generator's compare value
#define PWM_GENERATOR_mSetCompare(BaseAddress, Compare) \
  	PWM_GENERATOR_mWriteReg(BaseAddress, PWM_GENERATOR_S_AXI_COMPARE_REG_OFFSET, Compare)

/************************** Function Prototypes ****************************/
/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the PWM_GENERATOR instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus PWM_GENERATOR_Reg_SelfTest(void * baseaddr_p);

#endif // PWM_GENERATOR_H
