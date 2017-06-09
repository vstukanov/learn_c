#include <stdlib.h>
#include <stdio.h>

#include "contact.h"
#include "list.h"
#include "cli.h"

int main () {

  contact_say_hello();
  list_say_hello();
  cli_say_hello();

  return EXIT_SUCCESS;
}