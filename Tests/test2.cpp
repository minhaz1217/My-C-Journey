# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <string.h>

using namespace std;

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
    cout << str << endl;
  }
  return 0;
}
