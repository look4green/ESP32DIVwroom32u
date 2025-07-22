#include "shared.h"
#include "Display.h"
#include "Menu.h"

bool in_sub_menu = false;
bool feature_active = false;
bool submenu_initialized = false;
bool is_main_menu = true;
bool feature_exit_requested = false;

extern Display display;
extern Menu menu;

// This function typically renders the submenu when triggered
void displaySubmenu() {
  if (!submenu_initialized) {
    menu.init();  // Or any submenu-specific setup
    submenu_initialized = true;
  }
  
  in_sub_menu = true;
  is_main_menu = false;
  display.clear();
  menu.renderSubmenu();  // Assuming you have this method
}
