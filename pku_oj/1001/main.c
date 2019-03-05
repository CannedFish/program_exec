#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 8
#define MAX_ADD 16

char r[26][126];
char s[26];

int len_now = 0;
void _enlarge10(char *v, int times) {
  len_now = strlen(v);
  memset(v+len_now, '0', times);
  v[len_now+times] = '\0';
}

char tmp[126];
char *p_end;
char *vl_end, *vr_end, *res_end;
int inc = 0;
long long add_vl, add_vr, add_res;
long long base = pow(10.0, MAX_ADD);
void _add(char *vl, char *vr, int ml, int mr, char *res) {
  if(ml < mr) {
    memcpy(vl+(mr-ml), vl, ml);
    memset(vl, '0', mr-ml);
    ml = mr;
  } else {
    memcpy(vr+(ml-mr), vr, mr);
    memset(vr, '0', ml-mr);
    mr = ml;
  }
  vl_end = vl + ml;
  vr_end = vr + mr;
  res_end = res + 124 - MAX_ADD;
  memset(res, '\0', 126);
  inc = 0;
  while(vl_end-vl > MAX_ADD && vr_end-vr > MAX_ADD) {
    vl_end -= MAX_ADD;
    memcpy(tmp, vl_end, MAX_ADD);
    tmp[MAX_ADD] = '\0';
    add_vl = strtol(tmp, &p_end, 10);
    vr_end -= MAX_ADD;
    memcpy(tmp, vr_end, MAX_ADD);
    tmp[MAX_ADD] = '\0';
    add_vr = strtol(tmp, &p_end, 10);
    add_res = add_vl + add_vr + inc;
    inc = add_res / base;
    sprintf(tmp, "%0*lld", MAX_ADD, add_res % base);
    memcpy(res_end, tmp, strlen(tmp));
    res_end -= MAX_ADD;
  }
  res_end += MAX_ADD;
  if(vl_end != vl) {
    memcpy(tmp, vl, vl_end-vl);
    tmp[vl_end-vl] = '\0';
    add_vl = strtol(tmp, &p_end, 10);
    memcpy(tmp, vr, vr_end-vr);
    tmp[vr_end-vr] = '\0';
    add_vr = strtol(tmp, &p_end, 10);
    add_res = add_vl + add_vr + inc;
    sprintf(res, "%lld", add_res);
  }
  memcpy(res+strlen(res), res_end, strlen(res_end)+1);
  return ;
}

char tmp2[126];
void _mul(char *vl, char *vr, int ml, int mr, char *res) {
  memset(res, '\0', 126);
  if(ml == 1 || mr == 1 || (ml <= MAX && mr <= MAX)) {
    memcpy(tmp, vl, ml);
    tmp[ml] = '\0';
    long long _vl = strtol(tmp, &p_end, 10);
    memcpy(tmp, vr, mr);
    tmp[mr] = '\0';
    long long _vr = strtol(tmp, &p_end, 10);
    sprintf(res, "%lld", _vl*_vr);
    return ;
  }
  int _ml = ml/2, _mr = mr/2;
  char ac_res[126], bd_res[126], ad_res[126], bc_res[126];
  _mul(vl, vr, _ml, _mr, ac_res);
  _enlarge10(ac_res, (ml-_ml)+(mr-_mr));
  _mul(vl+_ml, vr+_mr, ml-_ml, mr-_mr, bd_res);
  _mul(vl, vr+_mr, _ml, mr-_mr, ad_res);
  _enlarge10(ad_res, ml-_ml);
  _mul(vl+_ml, vr, ml-_ml, _mr, bc_res);
  _enlarge10(bc_res, mr-_mr);
  _add(ac_res, ad_res, strlen(ac_res), strlen(ad_res), tmp2);
  memcpy(res, tmp2, strlen(tmp2));
  _add(res, bc_res, strlen(ac_res), strlen(bc_res), tmp2);
  memcpy(res, tmp2, strlen(tmp2));
  _add(res, bd_res, strlen(ac_res), strlen(bd_res), tmp2);
  memcpy(res, tmp2, strlen(tmp2));
}

void calc(int n) {
  int l = n/2, _r = n-l;
  if(s[l] != '1') calc(l);
  if(s[_r] != '1') calc(_r);
  _mul(r[l], r[_r], strlen(r[l]), strlen(r[_r]), r[n]);
  s[n] = '1';
  return ;
}

/* #define TEST */

#ifndef TEST

int main() {
  int n, p;
  char *ch;
  while(scanf("%s %d", r[0], &n) != EOF) {
    memset(s, '0', sizeof(char)*26);
    ch = strchr(r[0], '.');
    p = strlen(r[0]) - (ch - r[0]) - 1;
    *ch = '\0';
    if(strcmp(r[0], "0") == 0) {
      sprintf(r[1], "%s", ch+1);
    } else {
      sprintf(r[1], "%s%s", r[0], ch+1);
    }
    s[1] = '1';
    calc(n);
    inc = p*n;
    len_now = strlen(r[n]);
    if(inc < len_now) {
      ch = r[n] + strlen(r[n]) - p*n;
      memcpy(ch+1, ch, strlen(ch));
    } else {
      ch = r[n];
      memcpy(ch+inc-len_now+1, ch, len_now);
      memset(ch+1, '0', inc-len_now);
    }
    *ch = '.';
    ch = r[n] + strlen(r[n]) - 1;
    while(*ch == '0') --ch;
    *(ch+1) = '\0';
    printf("%s\n", r[n]);
  }
  return 0;
}

#endif
