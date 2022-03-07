//
// Created by student on 07.03.2022.
//

#include "../dependency.h"
#include <stdio.h>

struct Elevator initialize(){
    int floor = elevio_floorSensor();
    if (floor < 0){
        elevio_motorDirection(1);
        while (floor < 0){
            floor = elevio_floorSensor();

        }
        printf("Stopping motor");
        elevio_motorDirection(0);
    }
    struct Elevator elevator;
    elevator.state = idle;
    elevator.lastFloor = floor;
    for (int floor = 0; floor < N_FLOORS; floor++) {
        for (int button = 0; button < N_BUTTONS; button++) {
            if (!(floor == N_FLOORS - 1 && button == BUTTON_HALL_UP) && !(floor == 0 && button == BUTTON_HALL_DOWN)) {
                elevator.orderList[floor][button] = 0;
            }
        }
    }
    elevator.door = closed;
    return elevator;
}

/**
 *
 * @param currentFloor
 * @param elevator
 * @return
 */
bool check_orders_over(int currentFloor,struct Elevator elevator) {
    bool orderOverCurrentFloor = false;
    for (int i = currentFloor; i < N_FLOORS; ++i) {
        if (currentFloor != i) {
            if (elevator.orderList[i][0] == 1) {
                orderOverCurrentFloor = true;
            }
            else if (elevator.orderList[i][1] == 1 ) {
                orderOverCurrentFloor = true;
            }
            else if (elevator.orderList[i][2] == 1) {
                orderOverCurrentFloor = true;
            }
            }
        }
    return orderOverCurrentFloor;
    }
/**
 *
 * @param currentFloor
 * @param elevator
 * @return
 */
bool check_orders_under(int currentFloor,struct Elevator elevator){
    bool orderOverCurrentFloor = false;
    for (int i = currentFloor; i >= 0; --i) {
        if (currentFloor != i) {
            if (elevator.orderList[i][0] == 1) {
                orderOverCurrentFloor = true;
            }
            else if (elevator.orderList[i][1] == 1 ) {
                orderOverCurrentFloor = true;
            }
            else if (elevator.orderList[i][2] == 1) {
                orderOverCurrentFloor = true;
            }
        }
    }
    return orderOverCurrentFloor;
}

/**
 *
 * @param elevator
 */
void check_if_stop_at_floor(struct Elevator *elevator) {
    int currentFloor = elevio_floorSensor();
    struct Elevator elevatorCheck = *elevator;
    if (currentFloor >= 0) {
        switch (elevatorCheck.state) {
            case movingUp:
                if (elevatorCheck.orderList[currentFloor][0] == 1 || elevatorCheck.orderList[currentFloor][2] == 1) {
                    elevatorCheck.state = loading;
                } else {
                    bool orderOver = check_orders_over(currentFloor, elevatorCheck);
                    if (orderOver == false) {
                        elevatorCheck.state = loading;
                    }
                }


            case movingDown:
                if (elevatorCheck.orderList[currentFloor][1] == 1 || elevatorCheck.orderList[currentFloor][2] == 1) {
                    elevatorCheck.state = loading;
                } else {
                    bool orderUnder = check_orders_under(currentFloor, elevatorCheck);
                    if (orderUnder == false) {
                        elevatorCheck.state = loading;
                    }

                }
            case stopped:
                printf("u fucked ");
            case idle:
                printf("u fucked ");
            case loading:
                printf("u fucked ");


        }
    }
    *elevator = elevatorCheck;
}

/*
void check_state(struct Elevator *elevator){
    switch (elevator.state) {
        case elevator.state == movingUp:
            //check if door open ?
            elevio_motorDirection(1)
            check_if_stop_at_floor(elevator);


        case movingDown:
            //check if door open ?
            elevio_motorDirection(-1)
            check_if_stop_at_floor(elevator);

        case stopped:
            elevio_motorDirection(0);
            // clear orderlist
            elevator.state = idle;


        case loading:
            elevio_motorDirection(0)
            // check if time open == 0
                // open doors
                // set time open
            //check time
                // check obst == yes
                    //update time open
                // check obst == no
                    // close doors
                    // state = idle
                    // set time open = 0



        case  idle:
            elevio_motorDirection(0)
            //check if order at current floor
                // state = loading
            // check if order in last direction
                //state = last direction
            // check if order in other direction
                //state = this direction




    }

}
*/