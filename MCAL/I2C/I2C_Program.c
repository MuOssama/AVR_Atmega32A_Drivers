
#include<avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"I2C_Interface.h"


void MTWI_voidMasterInit(){
	//SET clock freq 200Kbps
	TWBR = 72;

	//Clear 2bits of TWPS
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);

	//Enable TWI
	SET_BIT(TWCR, 2);

}

void MTWI_voidSlaveInit(u8 A_u8SalveAddress){

	//Initialize slave address;
	TWAR = (A_u8SalveAddress<<1);

	//Enable TWI
	SET_BIT(TWCR, 2);
}

TWI_ErrStatus MTWI_SendStartCondition(){
	TWI_ErrStatus Local_ErrorState = NoError;

	/*Send Start Condition*/
	SET_BIT(TWCR, 5);

	/*Clear The Interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait Till the interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0xf8) != 0x08){
		Local_ErrorState = StartConditionErr;
	}

	return Local_ErrorState;
}






TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress){

	TWI_ErrStatus Local_ErrorState = NoError;

	/*Send Start Condition with low*/
	CLR_BIT(TWCR, 5);

	/*Set slave address in MSB in Data Reg*/
	TWDR = (A_u8SalveAddress <<1);
	/*Clear bit for write op*/
	CLR_BIT(TWDR, 0);

	/*Clear The Interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait Till the interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0xf8) != 0x18){
		Local_ErrorState = SlaveAdderssWithWriteErr;
	}

	return Local_ErrorState;
}


TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data){
	TWI_ErrStatus Local_ErrorState = NoError;

	/*Write Data on Data reg*/
	TWDR = A_u8Data;

	/*Clear The Interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait Till the interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0xf8) != 0x28){
		Local_ErrorState = MasterWriteDataErr;
	}

	return Local_ErrorState;

}

TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData){

	TWI_ErrStatus Local_ErrorState = NoError;

	/*Set Ack Bit*/
	SET_BIT(TWCR,6);

	/*Clear The Interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait Till the interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0xf8) != 0x60){
			Local_ErrorState = SlaveAdderessRecievedErr;
	}

	//////////////////////////////

	/*Set Ack Bit*/
	SET_BIT(TWCR,6);

	/*Clear The Interrupt Flag to start the prev operation*/
	SET_BIT(TWCR, 7);

	/*Wait Till the interrupt flag is fired and the prev operation is complete*/
	while(GET_BIT(TWCR, 7) == 0);

	if((TWSR & 0xf8) != 0x80){
		Local_ErrorState = SlaveDataRecievedErr;
	}
	else{
		*A_pu8RecievedData = TWDR;
	}

	return Local_ErrorState;


}

void MTWI_voidSendStopCondition(){

	/*Stop Condtion on the bus*/
	SET_BIT(TWCR, 4);

	/*Clear Interrupt Flag*/
	SET_BIT(TWCR, 7);
}


