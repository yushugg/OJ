## Tips

1. vector.size() is unsigned int, so if vector.size() == 0, vector.size() - 1 > 0

## Problems

1. Majority Element: Use a counter
2. Remove Duplicates From Sorted Array: Two pointers, assignment on original array directly
3. Merge Sorted Array: Reversed merge, will save time and space
4. Min Stack: Use an extra stack to store min elements, if a new element is larger than the current minimum, we do not need to push it on to the min stack. When we perform the pop operation, check if the popped element is the same as the current minimum. If it is, pop it off the min stack too
5. Rotate Array: BA = rotate(rotate(A)rotate(B))
6. Unique Binary Search Trees: DP, F(i, n) = G(i - 1) * G(n - i), F(i, n) means number of unique trees when i is root, G(n) means total number of unique trees when nodes number is n, so G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
7. Maximum Subarray: maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; maxSubArray must has A[i] as the end element.
8. Single Number II: Use bits, ones-each bit of int appears once or not, twos-each bit of int appears twice or not, threes-each bit of int appears three times or not, if some bits of threes is marked 1, then these bits of ones and twos will all change to 0.
9. Sort Colors: Two iterations-Count and reassign; One iteration-two pointers and swap.
10. Container With Most Water: Two pointers, front and back.
11. Search in Rotated Sorted Array: Binary search, but compare A[mid] and A[low] to classify this problem, not A[mid] and target. If low == mid, just make ++low to move to the next.
12. Set Matrix Zeros: Store count things in place, just use one row or column from matrix to save something, so extra space will be saved.
13. Linked List Cycle II: To determine a cycle use slow and fast pointer, both start from head, to find the cycle start, use an entry pointer starting from head, then both move entry and slow one step by step, then meet position is the entry point.
14. Permutations: for E: {a, b, c}, Perm(E) = aPerm(Enoa) + bPerm(Enob) + cPerm(Enoc), so if size(E) == 1, add result, else for begin to end, swap(begin and i) Permutation swap(begin and i). Last step is called the "backtrack step".
15. Unique Binary Search Trees II: return std::vector<TreeNode*> to iterate and to add in the front.
16. 3Sum Closest: Similar to 3Sum, for each one convert to a 2Sum problem, 2Sum use two pointers from start and end, O(N).
17. Gas Station: Greedy, two pointers starting from the same position and one goes left, another goes right.
18. Anagrams: Use unordered_map to construct a hash table.
19. Two Sum: Use a hashMap or map to store {need number, now index}, can be O(N), but consume O(N) space complexity as well.
20. Word Break: DP, canBreak[i] = canBreak[j<=i] && dict.find(str.substr(j~i))
21. String to Integer (atoi): To deal with overflow, inspect the current number before multiplication. If the current number is greater than 214748364, we know it is going to overflow. On the other hand, if the current number is equal to 214748364, we know that it will overflow only when the current digit is greater than or equal to 8, ie. 2147483648 and 2147483649.
22. Maximum Product Subarray: M1) Use max and min two arrays to store result
		
		f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
		g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )
		
	M2) Two pointers, calculate frontProduct from front and endProduct from end, get the max one, this will cancel the sign problems
23. Median of Two Sorted Arrays: Convert to find kth min, first array to find k/2 - 1, second to find n - k/2 + 1, then find(A + a, m - a, B, n, k - a), or find(A, m, B + b, n - b, k - b), always make m < n, and test m and k == 1
24. Longest Consecutive Sequence: Use a hashmap(unordered_map)
25. Populating Next Right Pointers in Each Node II: Use next pointer to generate next level data, use prev pointer and consider left or right existence situations
26. Edit Distance: DP, table[m+1][n+1], [i][j] = min([i-1][j] + 1, [i][j-1] + 1, [i-1][j-1]+cost0or1)
27. Distinct Subsequences: DP, consider substring T, use one dimensional array, if S[i-1] == T[j-1] dp[j] += dp[j-1], for j decreases from t to 1; Use two dimensional array, S[i-1] != T[j-1], dp[i][j] = dp[i][j-1], S[i-1] == T[j-1], dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
28. Copy List with Random Pointer: Use a hashtable to record <origin node, new node>, then iterate once again to recover the random pointers; Another method, new node can be append right after origin node, this can save space.
29. Recover Binary Search Tree: Morris Traversal, the idea of thread tree
30. Maximum Gap: Use buckets.
31. Merge Intervals, Insert Interval: Sort intervals by start, then consider case to insert new interval.
32. Largest Rectangle in Histogram: Two stacks to store increasing heights and index, when find decreasing height, then pop until increasing height, and calculate area, push new height and **last index**.
33. Word Ladder: Construct a graph, and BFS.
34. Repeated DNA Sequences: Hash, and try to save space.
35. Surrounded Regions: DFS will cause stack overflow, use BFS instead(table modify inside condition).
36. Fraction to Recurring Decimal: Use numerator*10(i.e. reminder) number to decide if loop exist, and use this number to hash.
37. Scramble String: both +++----- or either -----+++, or use DP, dp[i][j][k], means start from ith of s1 and from jth s2, and length is k, if it is scramble or not.
38. Best Time to Buy and Sell Stock III: Find a position i, and split into maxProfit1 for prices[0...i] and maxProfit2 for prices[i...n];  
Then go through forwardly
		
		forward[i] = max(forward[i - 1], prices[i] - lowest[0...i])	
and go through backwardly
		
		backward[i] = max(backward[i + 1], highest[i...n] - prices[i])
Finally, add up forward[i] and backward[i], get the max
		
		maxProfit = max(maxProfit, forward[i] + backward[i])
39. Best Time to Buy and Sell Stock IV:

		dp[i, j] = max(dp[i, j-1], dp[i-1,t] + prices[j] - prices[t+1])
	When k > prices.size() / 2, problem turns to be any transactions problem, so can be speed up.
40. Maximal Rectangle: See every row as a ground line, and ones as height, then this problem converts to Largest Rectangle in Histogram.
41. Regular Expression Matching: dp[i][j], i, j means length of string and pattern

		if p[j - 1] != '*':
			dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1])
		else:
			// x* 0 times
			dp[i][j] = dp[i][j - 2]
			// x* >= 1 times
			dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || '.' == p[j - 2])

## Algorithms

### Containing a sequence

1. Rabin-Karp(or Karp-Rabin): Uses hashing to search pattern string in a text. For text of length n and p patterns of combined length m, its average and best case running time is O(n+m) in space O(p), but its worst-case time is O(nm). Because of common part of string, so hashing of a string only need to substraction and addition operation, which will be constant time.
2. Knuth-Morris-Pratt(or KMP): Search for occurrences of a word within a main text string by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters. Using Partial Match Table to predict movation.
3. Boyer-Moore: String searching algorithm. Bad characters and good postfixes movation.
4. Backtracking: First, some condition do something; Second, for-loop to other possible things. If first and second are one if-and-else, remember to undo parameters in for-loop.  
**Remember, do not need to generate next char or int, just for loop enough**  
**Same for loop explains same position, next recursive explains next position**
5. List: First, find previous list node, or add head if want to be convinence.
6. Tree level order traversal, including level: Every time read all queue content, then push all children of all content

    	while(!q.empty()) {
        	int size = q.size();
        	for (int i=0; i<size; i++) {
            	TreeNode *node = q.front();
            	q.pop();
            	if (i==(size-1)) vi.push_back(node->val);
            	if (node->left) q.push(node->left);
            	if (node->right) q.push(node->right);
        	}
    	}
