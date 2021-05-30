#ifndef SUSPEND_TERMINATE_HPP
#define SUSPEND_TERMINATE_HPP

#include "../menu/menu_option.hpp"

class SuspendTerminate : public MenuOption {
public:
    SuspendTerminate( void );
    void execute(void);
};

#endif
