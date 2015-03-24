1. Assume you have a method isSubstring which checks if one word is a substring of another. Given two string s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring(i.e., "waterbottle" is a rotation of "erbottlewat").

	* Check if length(s1) == length(s2). If not, return false;
	* Else, concate s1 with itself and see whether s2 is substring of the result.
	
		- input: s1=apple, s2=pleap ==> apple is a substring of pleappleap
		- input: s1=apple, s2=ppale ==> apple is not a substring of ppaleppale
	
				public static boolean isRotation(String s1, String s2) {
					int len = s1.length();
					if (len == s2.length() && len > 0) {
						String s1s1 = s1 + s1;
						return isSubstring(s1s1, s2);
					}
					return false;
				}
				
2. The towers of Hanoi: Recursively

		void moveDisks(int n, Tower dest, Tower buffer) {
			if (n > 0) {
				moveDisks(n - 1, buffer, dest);
				moveTopTo(dest);
				buffer.moveDisks(n - 1, dest, this);
			}
		}