#ifndef _DOUBLER_H_
#define _DOUBLER_H_

#ifdef __cplusplus
extern "C" {
#endif

  int double_int(int);
  double double_float(double);
  char* double_str(char*);
  void str_free(char*);

#ifdef __cplusplus
}
#endif

#endif // _DOUBLER_H_
