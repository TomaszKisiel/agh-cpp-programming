#include "confirm_terminate.hpp"

ConfirmTerminate::ConfirmTerminate(void) : MenuOption("Yes") {}

void ConfirmTerminate::execute(void) {
    exit(0);
}
