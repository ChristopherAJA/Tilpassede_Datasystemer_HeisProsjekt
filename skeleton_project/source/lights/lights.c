#include "../dependency.h"

void lights_update_from_orderlist(struct Elevator elevator) {
    for (int floor = 0; floor < N_FLOORS; floor++) {
        for (int button = 0; button < N_BUTTONS; button++) {
            if (elevator.orderList[floor][button] == 1) {
                elevio_buttonLamp(floor, button, 1);
            } else {
                elevio_buttonLamp(floor, button, 0);
            }
        }
    }
}
