/** @file
  * @brief Elevator panel light functionality
  *
  */

/** @brief Turns on lights by looping through the elevator orderlist
 *
 * @param elevator elevator object which includes attribute orderlist
 */
void lights_update_from_orderlist(struct Elevator elevator);