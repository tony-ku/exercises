bool check_if_palindrome(char *x, uint32_t size)
{
   uint32_t left = 0, right = size - 1;

   while (left < right) {
	   if (x[left] != s[right])
		   return false;
	   left++;
	   right--;
   }
   return true;
}
