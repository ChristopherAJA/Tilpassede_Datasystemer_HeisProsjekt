#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"


/**
 * @file
 * @brief The main file of the elevator application
 */
int main(){

    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

//    elevio_motorDirection(DIRN_UP);
    struct Elevator elevator = initialize();

    printf("last floor is: %d", elevator.lastFloor);

//    while(1) {

//        update_order_list(elevator); // Update orders in the elevator object
//        lights_update_from_orderlist(elevator);
//        printf(button);
//
//        int floor = elevio_floorSensor();
//        printf("floor: %d , setFloor: %d\n",floor, setFloor);
/*

        if (floor != -1) {
            lastFloor = floor;
        }

        if(setFloor > lastFloor){
            printf("DIRN_UP\n");
            elevio_motorDirection(DIRN_UP);
        }

        if(setFloor < lastFloor){
            printf("DIRN_DOWN\n");
            elevio_motorDirection(DIRN_DOWN);
        }

        if (setFloor == lastFloor) {
            printf("DIRN_STOP\n");

            elevio_motorDirection(DIRN_STOP);
        }

        // Read every button and turn on lamp if button is pressed
        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);

                elevio_buttonLamp(f, b, btnPressed);
                if (btnPressed == 1){
                    setFloor = f;
                };

            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}
