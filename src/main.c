#include <stdlib.h>
#include <stdio.h>

#include "contact.h"
#include "list.h"
#include "cli.h"

int main () {

  s_contact * c = contact_new();
  s_contact * ab = contact_new();

  c->fullname = "Valeriy Stukanov";
  c->address = "Ukraine, Kiev, Borisa Hmury 2b, 81 ap.";
  c->phone_number = "+38 (063) 992-46-82";

  ab->fullname = "Arthur Bogdanov";
  ab->address = "Ukraine, Lviv, Chernigivska 221b, 181 ap.";
  ab->phone_number = "+38 (063) 111-22-33";

  s_contact * ls[2] = { c, ab };

  contact_print_table(ls, 2);

  contact_free(c);
  contact_free(ab);

  return EXIT_SUCCESS;
}