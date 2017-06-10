#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "utils.h"

static const char * FULLNAME = "Fullname";
static const char * ADDRESS = "Address";
static const char * PHONE_NUMBER = "Phone number";

s_contact * contact_new() {
  return (s_contact *) calloc(sizeof(s_contact), 1);
}

static 
int keys_max_length() {
  static int keys_length = -1;

  // keys_length is static, so maybe it's already calculated
  if (keys_length != -1) {
    return keys_length;
  }

  const char *keys[3] = {
    FULLNAME,
    ADDRESS,
    PHONE_NUMBER,
  };

  return keys_length = utils_strlen_max(keys, 3);
}

static 
int values_max_length(s_contact *contact) {
  const char *values[3] = {
    contact->fullname,
    contact->address,
    contact->phone_number,
  };
  
  return utils_strlen_max(values, 3);
}

static 
void print_value(const char *name, int pad_left, const char *value, int pad_right) {
  printf("| %*s: | %-*s |\n", pad_left, name, pad_right, value);
}

static
void print_in_center(char * buffer, const char * value, int width) {
  int slen = strlen(value);
  int pad = (width - slen) / 2;

  sprintf(buffer, "%*s%s%*s", pad, "", value, (width - pad - slen), "");
}

void contact_print(s_contact *contact) {
  int vlen = values_max_length(contact);
  int klen = keys_max_length();

  print_value(FULLNAME, klen, contact->fullname, vlen);
  print_value(ADDRESS, klen, contact->address, vlen);
  print_value(PHONE_NUMBER, klen, contact->phone_number, vlen);
}

void contact_print_table(s_contact **contacts, int len) {
  char ** buffer = (char **) calloc(sizeof(char *), len + 1);
  int i = 0;

  // FullName
  for (i = 0; i < len; i++) {
    buffer[i] = contacts[i]->fullname;
  }
  buffer[len] = (char *) FULLNAME;
  int fn_max = utils_strlen_max((const char **) buffer, len);

  // Address
  for (i = 0; i < len; i++) {
    buffer[i] = contacts[i]->address;
  }
  buffer[len] = (char *) ADDRESS;
  int ad_max = utils_strlen_max((const char **) buffer, len);

  // Phone number
  for (i = 0; i < len; i++) {
    buffer[i] = contacts[i]->phone_number;
  }
  buffer[len] = (char *) PHONE_NUMBER;
  int pn_max = utils_strlen_max((const char **) buffer, len);

  char * fn_title = calloc(fn_max + 1, 1);
  char * ad_title = calloc(ad_max + 1, 1);
  char * pn_title = calloc(pn_max + 1, 1);

  print_in_center(fn_title, FULLNAME, fn_max);
  print_in_center(ad_title, ADDRESS, ad_max);
  print_in_center(pn_title, PHONE_NUMBER, pn_max);

  int total_len = fn_max + ad_max + pn_max + 10;
  char * line = (char *) malloc(total_len + 1);
  memset(line, '-', total_len);
  line[total_len] = 0;

  printf("%s\n", line);
  printf("| %s | %s | %s |\n", fn_title, ad_title, pn_title);
  printf("%s\n", line);

  for (i = 0; i < len; i++) {
    printf("| %-*s | %-*s | %-*s |\n",
      fn_max, contacts[i]->fullname,
      ad_max, contacts[i]->address,
      pn_max, contacts[i]->phone_number
    );
  }

  printf("%s\n", line);
}

void contact_free(s_contact *contact) {
  free(contact);
}