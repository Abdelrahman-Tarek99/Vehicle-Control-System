#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>
#define ON 1
#define OFF 0
bool Engine_State=ON,AC_Condition=ON;
int Vehicle_Speed =30 ,Room_Temperature =35 ,Engine_Temperature =100 ;
void Menu1(void) {
	printf("a.Turn on the vehicle engine \n");
	fflush(stdout);
	printf("b.Turn off the vehicle engine \n");
	fflush(stdout);
	printf("c.Quit the system \n");
	fflush(stdout);
}
void Menu2(void) {
	printf("a.Turn off the engine \n");
	fflush(stdout);
	printf("b.Set the traffic light color.\n");
	fflush(stdout);
	printf("c.Set the room temperature (Temperature Sensor)\n");
	fflush(stdout);
	printf("d.Set the engine temperature (Engine Temperature Sensor)\n");
	fflush(stdout);
}
void Set_Traffic_light(char vh_speed){
	if(vh_speed== 'g'){
		Vehicle_Speed=100;
	}
	else if (vh_speed== 'o'){
		Vehicle_Speed=30;
		Room_Temperature=(Room_Temperature*(5/4))+1;
		Engine_State=ON;
		Engine_Temperature=(Engine_Temperature*(5/4))+1;
	}
	else {
		Vehicle_Speed=0;
	}

}
void Set_RoomTempreature_light(int Room_Temperature){
	if(Room_Temperature<10){
		AC_Condition= ON;
		Room_Temperature=20;

	}
	else if(Room_Temperature>30){
		AC_Condition= ON;
		Room_Temperature=20;
	}
	else {
		AC_Condition= OFF;
	}
}
void Engine_Controller(int EN_Temperature){
	if(Engine_Temperature<100){
		Engine_State=ON;
		Engine_Temperature=125;
	}
	else if(Engine_Temperature>150){
		Engine_State=ON;
		Engine_Temperature=125;
	}
	else{
		Engine_State=OFF;
	}
}
void Current_Vehicle_State(void){
	if(Engine_State==0){
		printf("Engine_State: OFF \n");
		fflush(stdout);
	}
	else{
		printf("Engine_Stater: ON \n");
		fflush(stdout);
	}
	if(AC_Condition==0){
		printf("AC: OFF \n");
		fflush(stdout);
	}
	else{
		printf("AC: ON \n");
		fflush(stdout);
	}
	printf("Vehicle Speed: %d \n",Vehicle_Speed);
	fflush(stdout);
	printf("Room_Temperature: %d \n",Room_Temperature);
	fflush(stdout);
	printf("Engine_Temperature: %d \n",Engine_Temperature);
	fflush(stdout);
}

int main(void) {
	char input, input2,vh_speed ;
	int rm_temp,EN_Temperature;
	Menu1();
	while(1){

			scanf(" %c", &input);
			if (input == 'a') {
				Menu2();
				while(1){
					scanf(" %c", &input2);
								if(input2 =='b'){
									printf("what is the traffic light?\nNOTE: The Default value will be Considered as a Red Sign\n");
									fflush(stdout);
									scanf(" %c", &vh_speed);
									Set_Traffic_light(vh_speed);
									Current_Vehicle_State();
									printf("\n");
									Menu2();
								}
								else if (input2=='c'){
									printf("what is the Room Temperature?\nNOTE: The Default value will be Considered as 35° \n");
									fflush(stdout);
									scanf(" %d", &rm_temp);
									Set_RoomTempreature_light(rm_temp);
									Current_Vehicle_State();
									printf("\n");
									Menu2();
								}
								else if (input2 == 'd'){
									printf("what is the Engine Temperature?\nNOTE: The Default value will be Considered as 100° \n");
									fflush(stdout);
									scanf(" %d", &EN_Temperature);
									Engine_Controller(EN_Temperature);
									Current_Vehicle_State();
									printf("\n");
									Menu2();
								}
								else{
									Menu1();
									break;
								}
				}
			} else if (input == 'b') {
				Menu1();
			} else {
				return 0;
			}


	}
}
