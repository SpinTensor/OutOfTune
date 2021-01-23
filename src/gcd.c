long long gcd(long long a, long long b) {
   if (a == 0) {
      return (b<0) ? -b : b;
   } else if (b == 0) {
      return (a<0) ? -a : b;
   } else {
      long long h;
      do {
         h = a % b;
         a = b;
         b = h;
      } while (b != 0);
      return (a<0) ? -a : a;
   }
}
