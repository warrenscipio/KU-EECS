double m[6];
double t;
scale(double x) {
  int i;
  i << 2;

  if (x == 0 && x > 10){
    return 1;
  }
  for (i = 0; i < 6; i += 1)
    m[i] *= x;
    if(i == 2)
      break;
  return 1;
}

