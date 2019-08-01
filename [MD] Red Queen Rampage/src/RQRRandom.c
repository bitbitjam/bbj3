
int randomIntFromZeroTo(int randomMax)
{
int x = 0;
  do {
   x = random();
  }
  while (x >= randomMax);
  return x;
}