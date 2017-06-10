#ifndef CONTACT_H
#define CONTACT_H

typedef struct {
  char * fullname;
  char * phone_number;
  char * address;
} s_contact;

s_contact * contact_new();
void contact_print(s_contact * contact);
void contact_print_table(s_contact **contacts, int len);
void contact_free();

#endif