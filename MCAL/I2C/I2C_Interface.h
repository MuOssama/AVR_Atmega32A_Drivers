
#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

typedef enum{
	NoError ,
	StartConditionErr,
	SlaveAdderssWithWriteErr,
	MasterWriteDataErr,
	SlaveAdderessRecievedErr,
	SlaveDataRecievedErr,

}TWI_ErrStatus;

void MTWI_voidMasterInit();

void MTWI_voidSlaveInit(u8 A_u8SalveAddress);


TWI_ErrStatus MTWI_SendStartCondition();

TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress);
TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data);

TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData);
void MTWI_voidSendStopCondition();


#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
