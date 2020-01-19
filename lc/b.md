
# https://leetcode.com/problems/two-sum/
# Given an array of integers, return indices of the two numbers
# such that they add up to a specific target.
# You may assume that each input would have exactly one solution.

# Maintain a mapping from each number to its index.
# Check if target - num has already been found.
# Time - O(n)
# Space - O(n) for the dictionary

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        num_to_index = {}           # key is number, value is index in nums

        for i, num in enumerate(nums):

            if target - num in num_to_index:
                return [num_to_index[target - num], i]

            num_to_index[num] = i

        return []   # no sum
				
				
				
				

# https://leetcode.com/problems/add-two-numbers/
# You are given two linked lists representing two non-negative numbers.
# The digits are stored in reverse order and
# each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.

# Iterate over lists. Add to result a node with
# the the sum of input nodes plus carry, mod 10.
# Time - O(max(m,n)) where m and n are input list lengths.
# Space - O(max(m,n)), output will be at most one digit more than longest input.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        prev = result = ListNode(None)      # dummy head
        carry = 0

        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            prev.next = ListNode(carry % 10)
            prev = prev.next
            carry //= 10

        return result.next
				
				

# https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Given a string, find the length of the longest
# substring without repeating characters.

# Maintain a sliding window, updating the start
# whenever we see a character repeated.
# Time - O(n)
# Space - O(1), dictionary is limited by fixed size alphabet

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        last_seen = {}      # mapping from character to its last seen index in s
        start = 0           # start index of current substring
        longest = 0

        for i, c in enumerate(s):

            if c in last_seen and last_seen[c] >= start:
                # start a new substring after the previous sighting of c
                start = last_seen[c] + 1
            else:
                longest = max(longest, i - start + 1)

            last_seen[c] = i    # update the last sighting index

        return longest
				
				

# https://leetcode.com/problems/median-of-two-sorted-arrays/
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# Find the median of the two sorted arrays. The overall
# run time complexity should be O(log (m+n)).

# Find the middle element if sum of input list lengths
# is odd, or else the average of the middle pair.
# get_kth_smallest recusively removes k//2 elements from one list.
# Time - O(log(m+n)), half of the elements smaller
# than median are removed each recursive call.
# Space - O(log(m+n)) for the recursive call stack.

class Solution(object):
    def findMedianSortedArrays(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: float
        """
        def get_kth_smallest(a_start, b_start, k):

            if k <= 0 or k > len(A) - a_start + len(B) - b_start:
                raise ValueError('k is out of the bounds of the input lists')

            # base cases
            if a_start >= len(A):
                return B[b_start + k - 1]
            if b_start >= len(B):
                return A[a_start + k - 1]
            if k == 1:
                return min(A[a_start], B[b_start])

            # remove k//2 elements from one list
            # find the smallest of the k//2 - 1th element from both lists and recurse having reduced that list.
            # k//2 - 1th element must exist in at least 1 list
            mid_A, mid_B = float('inf'), float('inf')
            if k // 2 - 1 < len(A) - a_start:
                mid_A = A[a_start + k // 2 - 1]
            if k // 2 - 1 < len(B) - b_start:
                mid_B = B[b_start + k // 2 - 1]

            if mid_A < mid_B:
                return get_kth_smallest(a_start + k // 2, b_start, k - k // 2)
            return get_kth_smallest(a_start, b_start + k // 2, k - k // 2)

        right = get_kth_smallest(0, 0, 1 + (len(A) + len(B)) // 2)
        if (len(A) + len(B)) % 2 == 1:  # odd total length
            return right

        left = get_kth_smallest(0, 0, (len(A) + len(B)) // 2)
        return (left + right) / 2.0
				
				

# https://leetcode.com/problems/longest-palindromic-substring/
# Given a string S, find the longest palindromic substring in S.
# You may assume that the maximum length of S is 1000, and
# there exists one unique longest palindromic substring.

# For each centre point of a character or between 2 characters,
# expand the palindrome if the end characters are the same.
# Return early by starting with the middle centre and
# ruling out later centres that could not have longer
# substring than the palindrome already found.
# Time - O(n^2), 2n centres, each expanded upto n times
# Space - O(n) to store the result

# Note that Manacher's algorithm provides a O(n) time solution.

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longest = ""

        # create list of 2n-1 possible centres, each letter and between each pair
        # even indices represent letters, odd represent between letters
        # start with middle index that potentially creates longest palindrome
        centres = [len(s) - 1]
        for diff in range(1, len(s)):  # build list of indices from long to short
            centres.append(centres[0] + diff)
            centres.append(centres[0] - diff)

        for centre in centres:

            if (min(centre + 1, 2 * len(s) - 1 - centre) <= len(longest)):
                break  # return if cannot make a longer palindrome

            if centre % 2 == 0:
                left, right = (centre // 2) - 1, (centre // 2) + 1
            else:
                left, right = centre // 2, (centre // 2) + 1

            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # left and right are now beyond the ends of the substring

            if right - left - 1 > len(longest):
                longest = s[left + 1:right]

        return longest
				
				

