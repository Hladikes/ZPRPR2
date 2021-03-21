#include <stdio.h>
#include <stdlib.h>

#define array_define(name, type)                                         \
  typedef struct {                                                       \
    int length;                                                          \
    int _unitsize;                                                       \
    int _allocated;                                                      \
    type *items;                                                         \
  } name;                                                                \
  typedef type name##___type;                                            \
  name name##___default() {                                              \
    name arr = {                                                         \
      length : 0,                                                        \
      _unitsize : sizeof(name##___type),                                 \
      _allocated : 10                                                    \
    };                                                                   \
    arr.items = (name##___type *)malloc(arr._unitsize * arr._allocated); \
    return arr;                                                          \
  }

#define array(name) name##___default()

#define array_foreach(name, arr, index, iterator, code) \
  for (int ___i = 0; ___i < arr.length; ___i++) {       \
    name##___type iterator = arr.items[___i];           \
    int index = ___i;                                   \
    code;                                               \
  }

#define array_push(name, arr, item)                                                  \
  if (arr._allocated == arr.length) {                                                \
    arr._allocated *= 2;                                                             \
    arr.items = (name##___type *)realloc(arr.items, arr._unitsize * arr._allocated); \
  }                                                                                  \
  arr.items[(arr.length += 1) - 1] = item;

#define array_free(arr) free(arr.items)


typedef struct {
  double a[11];
} Numbers;

array_define(NumbersArray, Numbers);

int main(void) {
  NumbersArray arr = array(NumbersArray);

  for (int i = 0; i < 100; i++) {
    Numbers f;
    array_push(NumbersArray, arr, f);
  }

  array_foreach(NumbersArray, arr, index, item, {
    
  });

  getchar();

  array_free(arr);

  return 0;
}