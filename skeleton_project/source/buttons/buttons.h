/** @file
  * @brief Handling of Button signals
  */

/** @brief Returns the button list which includes the floor level and the button pressed.
  *
  * @param[in] button The called button (BUTTON_HALL_UP, BUTTON_HALL_DOWN, BUTTON_CAB)
  * @param[in] floor  The current floor the button was pressed
  * @return The button is pressed or not (1 or 0 as value)
  */
int buttons_get_signal(ButtonType button, int floor);

/** @brief Fetches the button signals from the elevator driver (elevio) and updates the elevator order list.
  */
//void update_order_list(struct Elevator elevator);



