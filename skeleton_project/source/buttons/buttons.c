#include "../dependency.h"
static int buttonSignals[N_FLOORS][N_BUTTONS];

int buttons_get_signal(ButtonType button, int floor) {
    return buttonSignals[button][floor];
}
//void update_order_list(struct Elevator elevator) {
////    struct Elevator elevatorCheck = elevator
//    for (int floor = 0; floor < N_FLOORS; floor++) {
//        for (int button = 0; button < N_BUTTONS; button++) {
//            if (!(floor == N_FLOORS - 1 && button == BUTTON_HALL_UP) && !(floor == 0 && button == BUTTON_HALL_DOWN)) {
//                elevator.orderList[floor][button] = elevio_callButton(button,floor);
//            }
//        }
//    }
////    elevator = elevatorCheck
//}


