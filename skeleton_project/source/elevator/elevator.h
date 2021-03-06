/**@file
 * @brief
 */


 struct Elevator{
 enum State{
     movingUp,
     movingDown,
     loading,
     idle,
     stopped
 }state;
 enum Door{
     open,
     closed,
 }door;

 int lastFloor;
 int orderList[N_FLOORS][N_BUTTONS];
};
struct Elevator initialize();

/**@brief
 *
 * @param elevator
 */

void check_state(struct Elevator elevator);
void check_if_stop_at_floor(struct Elevator *elevator);
bool check_orders_over(int currentFloor,struct Elevator elevator);
bool check_orders_under(int currentFloor,struct Elevator elevator);